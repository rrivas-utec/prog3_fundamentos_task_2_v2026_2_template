#pragma once

#include "catch.hpp"
#include "permission_gray_image.h"
#include <stdexcept>

#if TEST_CASE_INDEX == 1
TEST_CASE("Question 6.1 - permission union") {
    PermissionMask permissions = PermissionMask(PermissionMask::Read) | PermissionMask(PermissionMask::Write); REQUIRE(permissions.has(PermissionMask::Read)); REQUIRE(permissions.has(PermissionMask::Write));
}

#elif TEST_CASE_INDEX == 2
TEST_CASE("Question 6.2 - permission intersection") {
    PermissionMask read(PermissionMask::Read), write(PermissionMask::Write); REQUIRE_FALSE((read & write).has(PermissionMask::Read));
}

#elif TEST_CASE_INDEX == 3
TEST_CASE("Question 6.3 - inversion preserves source") {
    GrayImage source(2, 1); source(0, 0) = 0; source(0, 1) = 120; GrayImage inverted = !source; REQUIRE(inverted(0, 0) == 255); REQUIRE(inverted(0, 1) == 135); REQUIRE(source(0, 1) == 120);
}

#elif TEST_CASE_INDEX == 4
TEST_CASE("Question 6.4 - copy and bounds") {
    GrayImage first(1, 1); first(0, 0) = 12; GrayImage copy = first; copy(0, 0) = 20; REQUIRE(first(0, 0) == 12); REQUIRE_THROWS_AS(first(1, 0), std::out_of_range);
}
#else
#error "TEST_CASE_INDEX must select an existing case"
#endif
