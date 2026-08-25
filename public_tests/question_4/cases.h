#pragma once

#include "catch.hpp"
#include "fraction_vector2.h"

#if TEST_CASE_INDEX == 1
TEST_CASE("Question 4.1 - fraction addition") {
    REQUIRE(Fraction(1, 2) + Fraction(1, 4) == Fraction(3, 4));
}

#elif TEST_CASE_INDEX == 2
TEST_CASE("Question 4.2 - fraction normalization") {
    REQUIRE(Fraction(-2, -4) == Fraction(1, 2));
}

#elif TEST_CASE_INDEX == 3
TEST_CASE("Question 4.3 - vector addition is pure") {
    Vector2 first(1, 2), sum = first + Vector2(3, -1); REQUIRE(sum.x() == 4); REQUIRE(sum.y() == 1); REQUIRE(first.x() == 1);
}

#elif TEST_CASE_INDEX == 4
TEST_CASE("Question 4.4 - compound vector addition") {
    Vector2 value(1, 2); (value += Vector2(3, -1)) += Vector2(1, 1); REQUIRE(value.x() == 5); REQUIRE(value.y() == 2);
}
#else
#error "TEST_CASE_INDEX must select an existing case"
#endif
