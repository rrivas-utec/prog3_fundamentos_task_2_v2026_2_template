#pragma once

#include "catch.hpp"
#include "book_search.h"

#if TEST_CASE_INDEX == 1
TEST_CASE("Question 2.1 - title ignores case") {
    std::vector<Book> books{{"Clean Code", 2008}, {"Algorithms", 1990}, {"Code Complete", 2004}}; REQUIRE(findBooks(books, "CODE").size() == 2);
}

#elif TEST_CASE_INDEX == 2
TEST_CASE("Question 2.2 - inclusive years") {
    std::vector<Book> books{{"A", 2000}, {"B", 2010}, {"C", 2011}}; REQUIRE(findBooks(books, 2000, 2010).size() == 2);
}

#elif TEST_CASE_INDEX == 3
TEST_CASE("Question 2.3 - combined filters") {
    std::vector<Book> books{{"Clean Code", 2008}, {"Code Complete", 2004}}; auto result = findBooks(books, "code", 2005, 2010); REQUIRE(result.size() == 1); REQUIRE(result[0].title == "Clean Code");
}

#elif TEST_CASE_INDEX == 4
TEST_CASE("Question 2.4 - input stays intact") {
    std::vector<Book> books{{"Code", 2000}, {"Other", 2001}}; (void)findBooks(books, "code"); REQUIRE(books.size() == 2);
}
#else
#error "TEST_CASE_INDEX must select an existing case"
#endif
