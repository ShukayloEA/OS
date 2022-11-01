#include <gtest/gtest.h>

#include <array>
#include <filesystem>
#include <fstream>
#include <memory>
#include <cstdlib>

namespace fs = std::filesystem;

extern "C" {
  #include <lab2.h>
}

int *GenerateArray(int size, int *arr) {
    std::srand(std::time(nullptr));

    for (int i = 0; i < size; ++i) {
        arr[i] = std::rand() % 1000;
    }

    return arr;
}

int compare(const void* x1, const void* x2)   // функция сравнения элементов массива
{
    return (*(int*)x1 - *(int*)x2);              // если результат вычитания равен 0, то числа равны, < 0: x1 < x2; > 0: x1 > x2
}

TEST(SecondLabTests, SingleThread) {
    const char* fileWithInput = "input.txt";
    const char* fileWithOutput = "output.txt";

    const int numberThreads = 1;
    const int size = 10;
    
    int input[size] = {
        1, 6, 9, 3, 4, 5, 2, 0, 8, 7
    };
    
    int expectedOutput[size] = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9
    };

    {
        auto inFile = std::ofstream(fileWithInput);

        for (int i = 0; i < size; i++) {
            inFile << input[i] << ' ';
        }
    }

    auto deleter = [](FILE* file) {
        fclose(file);
    };

    std::unique_ptr<FILE, decltype(deleter)> inFile(fopen(fileWithInput, "r"), deleter);

    FILE* outfile = fopen(fileWithOutput, "w");
    if (!outfile) {
        printf("Failed to open file\n");
    }
    
    Sort(numberThreads, size, input, outfile);

    fclose(outfile);

    auto outFile = std::ifstream(fileWithOutput);

    ASSERT_TRUE(outFile.good());

    int res[size];

    for (int i = 0; i < size; i++) {
        outFile >> res[i];
        EXPECT_EQ(res[i], expectedOutput[i]);
    }

    auto removeIfExists = [](const char* path) {
        if (fs::exists(path)) {
            fs::remove(path);
        }
    };

    removeIfExists(fileWithInput);
    removeIfExists(fileWithOutput);
}

TEST(SecondLabTests, ThreadConfigurations) {
    auto performTestForGivenSize = [](int size, int maxThreadCount) {
        const char* fileWithInput = "input.txt";
        const char* fileWithOutput = "output.txt";

        int *input = (int*)malloc(sizeof(int) * size);

        GenerateArray(size, input);

        int *expectedOutput = input;
        qsort(expectedOutput, size, sizeof(int), compare);

        {
            auto inFile = std::ofstream(fileWithInput);

            for (int i = 0; i < size; i++) {
                inFile << input[i] << ' ';
            }
        }

        auto deleter = [](FILE* file) {
            fclose(file);
        };

        for (int i = 2; i < maxThreadCount; ++i) {
            std::unique_ptr<FILE, decltype(deleter)> inFile(fopen(fileWithInput, "r"), deleter);

            FILE* outfile = fopen(fileWithOutput, "w");
            if (!outfile) {
                printf("Failed to open file\n");
            }

            Sort(i, size, input, outfile);

            fclose(outfile);

            auto outFile = std::ifstream(fileWithOutput);

            ASSERT_TRUE(outFile.good());

            int* res = (int*)malloc(sizeof(int) * size);

            for (int i = 0; i < size; i++) {
                outFile >> res[i];
                EXPECT_EQ(res[i], expectedOutput[i]);
            }

            auto removeIfExists = [](const char* path) {
                if (fs::exists(path)) {
                    fs::remove(path);
                }
            };

            removeIfExists(fileWithInput);
            removeIfExists(fileWithOutput);
        }
    };

    performTestForGivenSize(100, 10);
    performTestForGivenSize(10000, 10);
    performTestForGivenSize(2000000, 4);
}

TEST(SecondLabTest, PerfomanceTest) {
    auto getAvgTime = [](int numberThreads, int size) {
        const char* fileWithInput = "input.txt";
        const char* fileWithOutput = "output.txt";
        
        int* input = (int*)malloc(sizeof(int) * size);
        GenerateArray(size, input);

        {
            auto inFile = std::ofstream(fileWithInput);

            for (int i = 0; i < size; i++) {
                inFile << input[i] << ' ';
            }
        }

        auto deleter = [](FILE* file) {
            fclose(file);
        };

        std::unique_ptr<FILE, decltype(deleter)> inFile(fopen(fileWithInput, "r"), deleter);

        FILE* outfile = fopen(fileWithOutput, "w");
        if (!outfile) {
            printf("Failed to open file\n");
        }

        constexpr int runsCount = 10;

        double avg = 0;

        for (int i = 0; i < runsCount; ++i) {
            auto begin = std::chrono::high_resolution_clock::now();
            Sort(numberThreads, size, input, outfile);
            auto end = std::chrono::high_resolution_clock::now();
            avg += std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
        }

        fclose(outfile);

        return avg / runsCount;
    };

    auto singleThread = getAvgTime(1, 10000);
    auto multiThread = getAvgTime(4, 10000);

    std::cout << "Avg time for 1 thread: " << singleThread << '\n';
    std::cout << "Avg time for 4 threads: " << multiThread << '\n';

    EXPECT_GE(singleThread, multiThread);
}
