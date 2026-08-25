#pragma once

#include "catch.hpp"
#include "polynomial_matrix.h"
#include <stdexcept>

#if TEST_CASE_INDEX == 1
TEST_CASE("Question 5.1 - polynomial addition") {
    Polynomial p(1), q(2); p.coefficient(0) = 1; p.coefficient(1) = 2; q.coefficient(1) = 3; q.coefficient(2) = 4; REQUIRE((p + q).coefficient(1) == 5);
}

#elif TEST_CASE_INDEX == 2
TEST_CASE("Question 5.2 - polynomial equality") {
    Polynomial first(1), second(1); first.coefficient(0) = second.coefficient(0) = 3; REQUIRE(first == second);
}

#elif TEST_CASE_INDEX == 3
TEST_CASE("Question 5.3 - matrix product") {
    SquareMatrix identity(2), matrix(2); identity(0, 0) = identity(1, 1) = 1; matrix(1, 0) = 5; REQUIRE((identity * matrix)(1, 0) == 5);
}

#elif TEST_CASE_INDEX == 4
TEST_CASE("Question 5.4 - matrix bounds") {
    SquareMatrix matrix(2); REQUIRE(matrix.size() == 2); REQUIRE_THROWS_AS(matrix(2, 0), std::out_of_range);
}
#else
#error "TEST_CASE_INDEX must select an existing case"
#endif
