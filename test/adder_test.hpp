#pragma once
#include "../parser/parser.hpp"
#include "../adder/adder.hpp"

#include <gtest/gtest.h>

TEST(AdderTest, Add1) {
    addition_param ap_1(number_with_base("FF", 16), number_with_base("HELLO", 36), 2);
    EXPECT_EQ(adder::add(ap_1).get_num(), "1101111100001011011011011");
    EXPECT_EQ(adder::add(ap_1).get_base(), 2);
}

TEST(AdderTest, Add2) {
    addition_param ap_2(number_with_base("ff", 16), number_with_base("hello", 36), 2);
    EXPECT_EQ(adder::add(ap_2).get_num(), "1101111100001011011011011");
    EXPECT_EQ(adder::add(ap_2).get_base(), 2);
}

TEST(AdderTest, Add3) {
    addition_param ap_3(number_with_base("1", 10), number_with_base("1", 10), 10);
    EXPECT_EQ(adder::add(ap_3).get_num(), "2");
    EXPECT_EQ(adder::add(ap_3).get_base(), 10);
}

TEST(AdderTest, Add4) {
    addition_param ap_4(number_with_base("ZZ", 36), number_with_base("10", 10), 16);
    EXPECT_EQ(adder::add(ap_4).get_num(), "519");
    EXPECT_EQ(adder::add(ap_4).get_base(), 16);
}