#pragma once

#include "catch.hpp"
#include "distance.h"

#if TEST_CASE_INDEX == 1
TEST_CASE("Question 3.1 - two dimensions") {
    REQUIRE(distance(Point2D{0, 0}, Point2D{3, 4}) == 5.0);
}

#elif TEST_CASE_INDEX == 2
TEST_CASE("Question 3.2 - three dimensions") {
    REQUIRE(distance(Point3D{0, 0, 0}, Point3D{1, 2, 2}) == 3.0);
}

#elif TEST_CASE_INDEX == 3
TEST_CASE("Question 3.3 - path and helper") {
    std::vector<Point2D> path{{0, 0}, {3, 4}, {3, 8}}; REQUIRE(segmentLength(path[0], path[1]) == 5.0); REQUIRE(distance(path) == 9.0);
}

#elif TEST_CASE_INDEX == 4
TEST_CASE("Question 3.4 - short path") {
    REQUIRE(distance(std::vector<Point2D>{{1, 1}}) == 0.0);
}
#else
#error "TEST_CASE_INDEX must select an existing case"
#endif
