#ifndef UNTITLED_STRING_H
#define UNTITLED_STRING_H
#include <stdio.h>

size_t strlen_(const char *begin);

char* find(char *begin, char *end, int ch);

char* findNonSpace(char *begin);

char* findSpace(char *begin);

char* findNonSpaceReverse(char *rbegin, const char *rend);

char* findSpaceReverse(char *rbegin, const char *rend);

int strcmp(const char *lhs, const char *rhs);

void test_find1();

void test_find2();

void test_find3();

void test_find4();

void test_find_nonspace1();

void test_find_nonspace2();

void test_find_nonspace3();

void test_find_nonspace4();

void test_find_space1();

void test_find_space2();

void test_find_space3();

void test_find_space4();

void test_find_non_space_reverse1();

void test_find_non_space_reverse2();

void test_find_non_space_reverse3();

void test_find_non_space_reverse4();

void test_find_space_reverse1();

void test_find_space_reverse2();

void test_find_space_reverse3();

void test_find_space_reverse4();

void tests_find_str();

void test_strcmp1();

void test_strcmp2();

void test_strcmp3();

#endif