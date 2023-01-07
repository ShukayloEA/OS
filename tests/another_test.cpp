#include <gtest/gtest.h>

#include <array>
#include <filesystem>
#include <fstream>
#include <memory>

namespace fs = std::filesystem;

extern "C" {
    #include <parent.h>
}

TEST(AnotherLabTests, SimpleTest) {
    const char* fileWithInput = "input.txt";
    const char* fileWithOutput = "output.txt";
    
    constexpr int inputSize = 4;

    std::array<const char*, inputSize> input = {
            "Hello, world!",
            "12345",
            "A B  C   D /",
            "    "
    };

    std::array<const char*, inputSize> expectedOutput = {
	    "hello, world!", "12345", "a b c d /", " "
    };

    {
        auto inFile = std::ofstream(fileWithInput);
	
        for(const auto& line : input) {
            inFile<< line << '\n';
        }
    }

    auto deleter = [](FILE* file) {
        fclose(file);
    };

    std::unique_ptr<FILE, decltype(deleter)> inFile(fopen(fileWithInput, "r"), deleter);

    FILE *outfile = fopen(fileWithOutput, "w");
    if (!outfile) {
      printf("Failed to open file\n");
    }

    Parent(inFile.get(), outfile);

    fclose(outfile);
    
    auto outFile = std::ifstream(fileWithOutput);

    ASSERT_TRUE(outFile.good());

    std::string result;

    for(int i = 0; i < inputSize; i++) {
      std::getline(outFile, result);
        EXPECT_EQ(result, expectedOutput[i]);
    }

    auto removeIfExists = [](const char* path) {
        if(fs::exists(path)) {
            fs::remove(path);
        }
    };

    removeIfExists(fileWithInput);
    removeIfExists(fileWithOutput);
}
