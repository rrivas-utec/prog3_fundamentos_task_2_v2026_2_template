#pragma once

#include "catch.hpp"
#include "average.h"

#if TEST_CASE_INDEX == 1
TEST_CASE("Question 1.1 - two integers") {
    REQUIRE(average(10, 20) == 15.0);
}

#elif TEST_CASE_INDEX == 2
TEST_CASE("Question 1.2 - three doubles") {
    REQUIRE(average(10.0, 15.0, 20.0) == 15.0);
}

#elif TEST_CASE_INDEX == 3
TEST_CASE("Question 1.3 - array") {
    int values[] = {14, 16, 18, 20}; REQUIRE(average(values, 4) == 17.0);
}

#elif TEST_CASE_INDEX == 4
TEST_CASE("Question 1.4 - empty input") {
    int value[] = {20}; REQUIRE(average(value, 0) == 0.0);
}
#else
#error "TEST_CASE_INDEX must select an existing case"
#endif
