#pragma once
#include "../parser/parser.hpp"
#include "../adder/adder.hpp"

#include <gtest/gtest.h>

TEST(ParserTest, ReadValidData1) {
    std::istringstream iss(
        "\t16: \"FF\"\n"    \
        "\t36: \"HELLO\"\n" \
        "\t2"
    );

    addition_param ap = parser::read(iss);
    EXPECT_EQ(ap.get_number_with_base_a().get_num(), "FF");
    EXPECT_EQ(ap.get_number_with_base_a().get_base(), 16);
    EXPECT_EQ(ap.get_number_with_base_b().get_num(), "HELLO");
    EXPECT_EQ(ap.get_number_with_base_b().get_base(), 36);
    EXPECT_EQ(ap.get_to_base(), 2);
}

TEST(ParserTest, ReadValidData2) {
    std::istringstream iss(
        "16: \"FF\"\n"    \
        "36: \"HELLO\"\n" \
        "2: \"1101111100001011011011011\""
    );

    addition_param ap = parser::read(iss);
    EXPECT_EQ(ap.get_number_with_base_a().get_num(), "FF");
    EXPECT_EQ(ap.get_number_with_base_a().get_base(), 16);
    EXPECT_EQ(ap.get_number_with_base_b().get_num(), "HELLO");
    EXPECT_EQ(ap.get_number_with_base_b().get_base(), 36);
    EXPECT_EQ(ap.get_to_base(), 2);
}

TEST(ParserTest, ReadValidData3) {
    std::istringstream iss(
        "16: \"FF\"\n"    \
        "36: \"HELLO\"\n" \
        "Something\n"     \
        "2: \"1101111100001011011011011\""
    );

    addition_param ap = parser::read(iss);
    EXPECT_EQ(ap.get_number_with_base_a().get_num(), "FF");
    EXPECT_EQ(ap.get_number_with_base_a().get_base(), 16);
    EXPECT_EQ(ap.get_number_with_base_b().get_num(), "HELLO");
    EXPECT_EQ(ap.get_number_with_base_b().get_base(), 36);
    EXPECT_EQ(ap.get_to_base(), 2);
}

TEST(ParserTest, ReadInvalidData) {
    std::istringstream iss(
        "16: \"FF\"\n"    \
        "36: \"HELLO\"\n"
    );

    EXPECT_THROW(addition_param ap = parser::read(iss), std::invalid_argument);
}

TEST(ParserTest, WriteValidData) {
    std::ostringstream oss;
    std::string buffer = "1101111100001011011011011";

    parser::write(oss, buffer);
    EXPECT_EQ(oss.str(), ": \"1101111100001011011011011\"");
}

TEST(ParserTest, WriteInvalidData) {
    std::ostringstream oss;
    std::string buffer = "@1101111100001011011011011";

    EXPECT_THROW(parser::write(oss, buffer), std::invalid_argument);
}