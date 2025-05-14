#include <gtest/gtest.h>

#include "../parser/parser.hpp"
#include "../adder/adder.hpp"

TEST(AdditionParamTest, ConstructorAndGettersValidData) {
    addition_param ap(number_with_base("FF", 16), number_with_base("HELLO", 36), 2);

    number_with_base nb_a = ap.get_number_with_base_a();
    EXPECT_EQ(nb_a.get_num(), "FF");
    EXPECT_EQ(nb_a.get_base(), 16);

    number_with_base nb_b = ap.get_number_with_base_b();
    EXPECT_EQ(nb_b.get_num(), "HELLO");
    EXPECT_EQ(nb_b.get_base(), 36);

    EXPECT_EQ(ap.get_target(), 2);
}

TEST(AdditionParamTest, ConstructorAndGettersValidDataConst) {
    const addition_param ap(number_with_base("FF", 16), number_with_base("HELLO", 36), 2);

    const number_with_base nb_a = ap.get_number_with_base_a();
    EXPECT_EQ(nb_a.get_num(), "FF");
    EXPECT_EQ(nb_a.get_base(), 16);

    const number_with_base nb_b = ap.get_number_with_base_b();
    EXPECT_EQ(nb_b.get_num(), "HELLO");
    EXPECT_EQ(nb_b.get_base(), 36);

    EXPECT_EQ(ap.get_target(), 2);
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

TEST(ParserTest, ReadValidData) {
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
    EXPECT_EQ(ap.get_target(), 2);
}

TEST(ParserTest, ReadInvalidData) {
    std::istringstream iss(
        "16: \"FF\"\n"    \
        "36: \"HELLO\"\n" \
        "2: \"1101111100001011011011011\""
    );

    EXPECT_THROW(parser::read(iss), std::length_error);
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

TEST(AdderTest, Add) {
    addition_param ap_1(number_with_base("FF", 16), number_with_base("HELLO", 36), 2);
    EXPECT_EQ(adder::add(ap_1).get_num(), "1101111100001011011011011");
    EXPECT_EQ(adder::add(ap_1).get_base(), 2);

    addition_param ap_2(number_with_base("ff", 16), number_with_base("hello", 36), 2);
    EXPECT_EQ(adder::add(ap_2).get_num(), "1101111100001011011011011");
    EXPECT_EQ(adder::add(ap_2).get_base(), 2);

    addition_param ap_3(number_with_base("1", 10), number_with_base("1", 10), 10);
    EXPECT_EQ(adder::add(ap_3).get_num(), "2");
    EXPECT_EQ(adder::add(ap_3).get_base(), 10);

    addition_param ap_4(number_with_base("ZZ", 36), number_with_base("10", 10), 16);
    EXPECT_EQ(adder::add(ap_4).get_num(), "519");
    EXPECT_EQ(adder::add(ap_4).get_base(), 16);
}