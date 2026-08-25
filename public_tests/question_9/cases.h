#pragma once

#include "catch.hpp"
#include "price_rule.h"
#include <stdexcept>

#if TEST_CASE_INDEX == 1
TEST_CASE("Question 9.1 - regular price") {
    Order order(10.0, 2); RegularPrice rule; REQUIRE(order.total(rule) == 20.0);
}

#elif TEST_CASE_INDEX == 2
TEST_CASE("Question 9.2 - student discount") {
    Order order(10.0, 2); StudentDiscount rule(20); REQUIRE(order.total(rule) == 16.0);
}

#elif TEST_CASE_INDEX == 3
TEST_CASE("Question 9.3 - bulk threshold") {
    BulkDiscount rule(5, 10); REQUIRE(Order(10.0, 4).total(rule) == 40.0); REQUIRE(Order(10.0, 5).total(rule) == 45.0);
}

#elif TEST_CASE_INDEX == 4
TEST_CASE("Question 9.4 - extensible repository") {
    PriceRuleRepository repository; repository.add(std::make_unique<ShippingPrice>(3)); REQUIRE(Order(10.0, 2).total(repository.find("shipping")) == 23.0); REQUIRE_THROWS_AS(Order(1.0, 0), std::invalid_argument);
}
#else
#error "TEST_CASE_INDEX must select an existing case"
#endif
