#pragma once

#include "catch.hpp"
#include "message_format.h"
#include <stdexcept>

#if TEST_CASE_INDEX == 1
TEST_CASE("Question 8.1 - plain format") {
    MessageView view; PlainFormat format; REQUIRE(view.show("Servidor listo", format) == "Servidor listo");
}

#elif TEST_CASE_INDEX == 2
TEST_CASE("Question 8.2 - uppercase format") {
    MessageView view; UppercaseFormat format("ALERTA: "); REQUIRE(view.show("Servidor listo", format) == "ALERTA: SERVIDOR LISTO");
}

#elif TEST_CASE_INDEX == 3
TEST_CASE("Question 8.3 - repository lookup") {
    FormatRepository repository; repository.add(std::make_unique<PlainFormat>()); REQUIRE(repository.find("plain").format("ok") == "ok");
}

#elif TEST_CASE_INDEX == 4
TEST_CASE("Question 8.4 - missing format") {
    FormatRepository repository; REQUIRE_THROWS_AS(repository.find("missing"), std::out_of_range);
}
#else
#error "TEST_CASE_INDEX must select an existing case"
#endif
