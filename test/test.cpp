#include <gtest/gtest.h>

#include "../parser/parser.hpp"
#include "../adder/adder.hpp"

// Parser тесты

TEST(ParserTest, ReadCorrectData) {
    std::string text = "16: \"FF\"\n36: \"HELLO\"\n2";
    std::istringstream iss(text);

    NumberBase result = Parser::read(iss);
    
    EXPECT_EQ(result.getFirstNumber().first, "FF");
    EXPECT_EQ(result.getFirstNumber().second, 16);
    EXPECT_EQ(result.getSecondNumber().first, "HELLO");
    EXPECT_EQ(result.getSecondNumber().second, 36);
    EXPECT_EQ(result.getTargetBase(), 2);
}

TEST(ParserTest, ReadEmptyLine) {
    std::string text = "";
    std::istringstream iss(text);

    try {
        NumberBase result = Parser::read(iss);
    }

    catch (const std::exception& exception) {
        EXPECT_STREQ(exception.what(), "Does not match the type");
    }
}

TEST(ParserTest, ReadIncorrectData1) {
    std::string text = "-16: \"FF\"\n36: \"HELLO\"\n2";
    std::istringstream iss(text);

    try {
        NumberBase result = Parser::read(iss);
    }

    catch (const std::exception& exception) {
        EXPECT_STREQ(exception.what(), "The base takes a value from 2 to 36");
    }
}

TEST(ParserTest, ReadIncorrectData2) {
    std::string text = "16: \"@FF\"\n36: \"HELLO\"\n2";
    std::istringstream iss(text);

    try {
        NumberBase result = Parser::read(iss);
    }

    catch (const std::exception& exception) {
        EXPECT_STREQ(exception.what(), "The value can contain only letters and numbers");
    }
}

// Adder тесты

TEST(AdderTest, Add) {
    NumberBase base_number("FF", 16, "HELLO", 36, 2);

    EXPECT_STREQ(Adder::add(base_number).c_str(), "1101111100001011011011011");
}