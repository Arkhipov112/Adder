#pragma once
#include "../parser/parser.hpp"
#include "../adder/adder.hpp"

#include <gtest/gtest.h>

TEST(AdditionParamTest, ConstructorAndGettersValidData) {
    addition_param ap(number_with_base("FF", 16), number_with_base("HELLO", 36), 2);

    number_with_base nb_a = ap.get_number_with_base_a();
    EXPECT_EQ(nb_a.get_num(), "FF");
    EXPECT_EQ(nb_a.get_base(), 16);

    number_with_base nb_b = ap.get_number_with_base_b();
    EXPECT_EQ(nb_b.get_num(), "HELLO");
    EXPECT_EQ(nb_b.get_base(), 36);

    EXPECT_EQ(ap.get_to_base(), 2);
}

TEST(AdditionParamTest, ConstructorAndGettersValidDataConst) {
    const addition_param ap(number_with_base("FF", 16), number_with_base("HELLO", 36), 2);

    const number_with_base nb_a = ap.get_number_with_base_a();
    EXPECT_EQ(nb_a.get_num(), "FF");
    EXPECT_EQ(nb_a.get_base(), 16);

    const number_with_base nb_b = ap.get_number_with_base_b();
    EXPECT_EQ(nb_b.get_num(), "HELLO");
    EXPECT_EQ(nb_b.get_base(), 36);

    EXPECT_EQ(ap.get_to_base(), 2);
}

TEST(AdditionParamTest, ConstructorInvalidData) {
    EXPECT_THROW(addition_param(number_with_base("FF", 0), number_with_base("HELLO", 36), 2), std::invalid_argument);
    EXPECT_THROW(addition_param(number_with_base("FF", 16), number_with_base("HELLO", 0), 2), std::invalid_argument);
    EXPECT_THROW(addition_param(number_with_base("FF", 16), number_with_base("HELLO", 36), 0), std::invalid_argument);

    EXPECT_THROW(addition_param(number_with_base("FF", -16), number_with_base("HELLO", 36), 2), std::invalid_argument);
    EXPECT_THROW(addition_param(number_with_base("FF", 16), number_with_base("HELLO", -36), 2), std::invalid_argument);
    EXPECT_THROW(addition_param(number_with_base("FF", 16), number_with_base("HELLO", 36), -2), std::invalid_argument);

    EXPECT_THROW(addition_param(number_with_base("@FF", 16), number_with_base("HELLO", 36), 2), std::invalid_argument);
    EXPECT_THROW(addition_param(number_with_base("FF", 16), number_with_base("@HELLO", 36), 2), std::invalid_argument);

    EXPECT_THROW(addition_param(number_with_base("FF", 2), number_with_base("HELLO", 36), 2), std::invalid_argument);
    EXPECT_THROW(addition_param(number_with_base("FF", 16), number_with_base("HELLO", 2), 2), std::invalid_argument);
}