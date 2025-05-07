#include "../googletest/googletest/include/gtest/gtest.h"

#include "../parser/parser.hpp"
#include "../adder/adder.hpp"

// Parser тесты

TEST(ParserTest, ReadCorrectData) {
    std::string text = "16: \"FF\"\n36: \"HELLO\"\n2";

    std::istringstream iss(text);

    BaseNumber result = Parser::read(iss);
    
    EXPECT_EQ(result.base_a, 16);
    EXPECT_EQ(result.number_a, "FF");
    EXPECT_EQ(result.base_b, 36);
    EXPECT_EQ(result.number_b, "HELLO");
    EXPECT_EQ(result.base_c, 2);
}

TEST(ParserTest, ReadEmptyLine) {
    std::string text = "";

    std::istringstream iss(text);

    try {
        BaseNumber result = Parser::read(iss);
    }

    catch (const std::exception& exception) {
        EXPECT_STREQ(exception.what(), "Does not match the type");
    }
}

TEST(ParserTest, ReadIncorrectData1) {
    std::string text = "16: \"FF\"\n36: \"HELLO\"";

    std::istringstream iss(text);

    try {
        BaseNumber result = Parser::read(iss);
    }

    catch (const std::exception& exception) {
        EXPECT_STREQ(exception.what(), "Does not match the type");
    }
}

TEST(ParserTest, ReadIncorrectData2) {
    std::string text = "-16: \"FF\"\n36: \"HELLO\"\n2";

    std::istringstream iss(text);

    try {
        BaseNumber result = Parser::read(iss);
    }

    catch (const std::exception& exception) {
        EXPECT_STREQ(exception.what(), "Base cannot be negative");
    }
}

TEST(ParserTest, ReadIncorrectData3) {
    std::string text = "16: \"@FF\"\n36: \"HELLO\"\n2";

    std::istringstream iss(text);

    try {
        BaseNumber result = Parser::read(iss);
    }

    catch (const std::exception& exception) {
        EXPECT_STREQ(exception.what(), "Number must contain the characters (from 0 to 9) and (from a to z) and (from A to Z)");
    }
}

TEST(ParserTest, Write) {
    std::ostringstream oss;

    std::string buffer = "1101111100001011011011011";
    Parser::write(oss, buffer);

    std::string text = oss.str();
    EXPECT_EQ(text, ": \"1101111100001011011011011\"");
}

// Adder тесты

TEST(AdderTest, Add) {
    std::string text = "16: \"FF\"\n36: \"HELLO\"\n2";

    std::istringstream iss(text);

    BaseNumber result = Parser::read(iss);

    EXPECT_EQ(Adder::add(result), "1101111100001011011011011");
}