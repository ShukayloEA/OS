#include <gtest/gtest.h>

#include <array>
#include <filesystem>
#include <fstream>
#include <memory>

namespace fs = std::filesystem;

extern "C" {
    #include <realization.h>
}

TEST(FifthLabTests, DerivativeTest) {
    constexpr int inputSize = 4;

    std::array<const float, inputSize * 2> input = {
            0.0, 0.125,
            1.0, 0.5,
            1.28, 0.1,
            3.14, 1.0
    };

    std::array<const float, inputSize> expectedOutput = {
	    0.00000000, -0.80684536, -0.95641997, -0.00134017
    };
    for(int i = 0; i < inputSize; i++) {
        EXPECT_NEAR(Derivative(input[2*i], input[2*i+1]), expectedOutput[i], 1e-5);
    }

}

TEST(FifthLabTests, SquareTest) {
    constexpr int inputSize = 4;

    std::array<const float, inputSize * 2> input = {
            2.0, 7.0,
            1.0, 0.5,
            10.0, 0.1,
            4.0, 4.0
    };

    std::array<const float, inputSize> expectedOutput = {
	    7.00000, 0.25000, 0.50000, 8.00000
    };
    for(int i = 0; i < inputSize; i++) {
        EXPECT_EQ(Square(input[2*i], input[2*i+1]), expectedOutput[i]);
    }

}