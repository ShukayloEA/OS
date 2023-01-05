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
	    -0.06241866, -0.93913021, -0.97074378, 0.45835694
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
	    14.00000, 0.50000, 1.00000, 16.00000
    };
    for(int i = 0; i < inputSize; i++) {
        EXPECT_EQ(Square(input[2*i], input[2*i+1]), expectedOutput[i]);
    }

}