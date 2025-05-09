#include <gtest/gtest.h>

#include "../parser/parser.hpp"
#include "../adder/adder.hpp"

TEST(NumbaseTest, ConstructorAndGettersValidData) {
    numbase nb("FF", 16, "HELLO", 36, 2);

    numpair np_a = nb.get_numpair_a();
    EXPECT_EQ(np_a.first, "FF");
    EXPECT_EQ(np_a.second, 16);

    numpair np_b = nb.get_numpair_b();
    EXPECT_EQ(np_b.first, "HELLO");
    EXPECT_EQ(np_b.second, 36);

    EXPECT_EQ(nb.get_target(), 2);
}

TEST(NumbaseTest, ConstructorInvalidData) {
    EXPECT_THROW(numbase("FF", 0, "HELLO", 36, 2), std::invalid_argument);
    EXPECT_THROW(numbase("FF", 16, "HELLO", 0, 2), std::invalid_argument);
    EXPECT_THROW(numbase("FF", 16, "HELLO", 36, 0), std::invalid_argument);

    EXPECT_THROW(numbase("FF", -16, "HELLO", 36, 2), std::invalid_argument);
    EXPECT_THROW(numbase("FF", 16, "HELLO", -36, 2), std::invalid_argument);
    EXPECT_THROW(numbase("FF", 16, "HELLO", 36, -2), std::invalid_argument);

    EXPECT_THROW(numbase("@FF", 16, "HELLO", 36, 2), std::invalid_argument);
    EXPECT_THROW(numbase("FF", 16, "@HELLO", 36, 2), std::invalid_argument);
}

TEST(ParserTest, ReadValidData) {
    std::istringstream iss(
        "16: \"FF\"\n"    \
        "36: \"HELLO\"\n" \
        "2"
    );

    numbase nb = parser::read(iss);
    EXPECT_EQ(nb.get_numpair_a().first, "FF");
    EXPECT_EQ(nb.get_numpair_a().second, 16);
    EXPECT_EQ(nb.get_numpair_b().first, "HELLO");
    EXPECT_EQ(nb.get_numpair_b().second, 36);
    EXPECT_EQ(nb.get_target(), 2);
}

TEST(ParserTest, ReadInvalidData) {
    std::istringstream iss(
        "16: \"FF\"\n"    \
        "36: \"HELLO\"\n" \
        "2: \"1101111100001011011011011\""
    );

    EXPECT_THROW(parser::read(iss), std::length_error);
}

TEST(ParserTest, Write) {
    std::ostringstream oss;
    std::string buffer = "1101111100001011011011011";

    parser::write(oss, buffer);
    EXPECT_EQ(oss.str(), ": \"1101111100001011011011011\"");
}

TEST(AdderTest, Add) {
    numbase nb("FF", 16, "HELLO", 36, 2);

    EXPECT_EQ(adder::add(nb), "1101111100001011011011011");
}