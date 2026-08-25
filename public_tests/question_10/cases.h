#pragma once

#include "catch.hpp"
#include "report_exporter.h"
#include <stdexcept>

#if TEST_CASE_INDEX == 1
TEST_CASE("Question 10.1 - text exporter") {
    SensorReport report; report.add("temperature", 23.5); report.add("humidity", 60.0); TextExporter exporter; REQUIRE(report.render(exporter) == "temperature: 23.5\nhumidity: 60\n");
}

#elif TEST_CASE_INDEX == 2
TEST_CASE("Question 10.2 - csv exporter") {
    SensorReport report; report.add("temperature", 23.5); report.add("humidity", 60.0); CsvExporter exporter; REQUIRE(report.render(exporter) == "name,value\ntemperature,23.5\nhumidity,60\n");
}

#elif TEST_CASE_INDEX == 3
TEST_CASE("Question 10.3 - json exporter") {
    SensorReport report; report.add("temperature", 23.5); JsonExporter exporter; REQUIRE(report.render(exporter) == "[{\"name\":\"temperature\",\"value\":23.5}]");
}

#elif TEST_CASE_INDEX == 4
TEST_CASE("Question 10.4 - repository and validation") {
    ExporterRepository repository; repository.add(std::make_unique<TextExporter>()); SensorReport report; REQUIRE(report.render(repository.find("text")).empty()); REQUIRE_THROWS_AS(report.add("bad name", 1.0), std::invalid_argument);
}
#else
#error "TEST_CASE_INDEX must select an existing case"
#endif
