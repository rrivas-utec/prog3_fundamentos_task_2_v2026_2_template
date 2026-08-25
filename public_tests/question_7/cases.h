#pragma once

#include "catch.hpp"
#include "grade_filter.h"
#include <stdexcept>

#if TEST_CASE_INDEX == 1
TEST_CASE("Question 7.1 - minimum filter") {
    GradeReport report({10, 13, 14, 15, 16}); MinimumGradeFilter filter(14); REQUIRE(report.select(filter) == std::vector<int>({14, 15, 16}));
}

#elif TEST_CASE_INDEX == 2
TEST_CASE("Question 7.2 - even filter") {
    GradeReport report({10, 13, 14, 15, 16}); EvenGradeFilter filter; REQUIRE(report.select(filter) == std::vector<int>({10, 14, 16}));
}

#elif TEST_CASE_INDEX == 3
TEST_CASE("Question 7.3 - repository lookup") {
    FilterRepository repository; repository.add(std::make_unique<MinimumGradeFilter>(14)); REQUIRE(repository.find("minimum-14").accepts(14));
}

#elif TEST_CASE_INDEX == 4
TEST_CASE("Question 7.4 - missing filter") {
    FilterRepository repository; REQUIRE_THROWS_AS(repository.find("missing"), std::out_of_range);
}
#else
#error "TEST_CASE_INDEX must select an existing case"
#endif
