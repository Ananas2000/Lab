#include "string_.h"
#include <stdio.h>
#include <ctype.h>
#include <assert.h>

size_t strlen_(const char *begin) {
    const char *end = begin;
    while (*end != '\0')
        end++;
    return end - begin;
}

char* find(char *begin, char *end, int ch) {
    while (begin != end && *begin != ch)
        begin++;
        
    return begin;
}

char* findNonSpace(char *begin) {
    while (isspace(*begin) && *begin != '\0') {
        begin++;
    }
    return begin;
}

char* findSpace(char *begin) {
    while (!isspace(*begin) && *begin != '\0') {
        begin++;
    }
    return begin;
}

char *findNonSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin >= rend && isspace(*rbegin)) {
        rbegin--;
    }
    return rbegin;
}

char *findSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin >= rend && !isspace(*rbegin)) {
        rbegin--;
    }
    return rbegin;
}

void test_find1() {
    char string[] = "hello";

    assert(find(string, string + 5, 'e') == string + 1);
}

void test_find2() {
    char string[] = "hello";

    assert(find(string, string + 5, 'h') == string);
}

void test_find3() {
    char string[] = "hello";

    assert(find(string, string + 5, 'o') == string + 4);
}

void test_find4() {
    char string[] = "hello";

    assert(find(string, string + 5, 'g') == string + 5);
}

void test_find_nonspace1() {
    char string[] = "hello";

    assert(findNonSpace(string) == string);
}

void test_find_nonspace2() {
    char string[] = "  llo";

    assert(findNonSpace(string) == string + 2);
}

void test_find_nonspace3() {
    char string[] = "    o";

    assert(findNonSpace(string) == string + 4);
}

void test_find_nonspace4() {
    char string[] = "     ";

    assert(findNonSpace(string) == string + 5);
}

void test_find_space1() {
    char string[] = " ello";

    assert(findSpace(string) == string);
}

void test_find_space2() {
    char string[] = "he lo";

    assert(findSpace(string) == string + 2);
}

void test_find_space3() {
    char string[] = "hello";

    assert(findSpace(string) == string + 5);
}

void test_find_space4() {
    char string[] = "hell ";

    assert(findSpace(string) == string + 4);
}

void test_find_non_space_reverse1() {
    char string[] = "hello";

    assert(findNonSpaceReverse(string + 4, string) == string + 4);
}

void test_find_non_space_reverse2() {
    char string[] = "hel  ";

    assert(findNonSpaceReverse(string + 4, string) == string + 2);
}

void test_find_non_space_reverse3() {
    char string[] = "h    ";

    assert(findNonSpaceReverse(string + 4, string) == string);
}

void test_find_non_space_reverse4() {
    char string[] = "     ";

    assert(findNonSpaceReverse(string + 4, string) == string - 1);
}

void test_find_space_reverse1() {
    char string[] = "hello";

    assert(findSpaceReverse(string + 4, string) == string - 1);
}

void test_find_space_reverse2() {
    char string[] = "hel  ";

    assert(findSpaceReverse(string + 4, string) == string + 4);
}

void test_find_space_reverse3() {
    char string[] = "h   o";

    assert(findSpaceReverse(string + 4, string) == string + 3);
}

void test_find_space_reverse4() {
    char string[] = " ello";

    assert(findSpaceReverse(string + 4, string) == string);
}

void tests_find_str() {
    test_find1();
    test_find2();
    test_find3();
    test_find4();
    test_find_nonspace1();
    test_find_nonspace2();
    test_find_nonspace3();
    test_find_nonspace4();
    test_find_space1();
    test_find_space2();
    test_find_space3();
    test_find_space4();
    test_find_non_space_reverse1();
    test_find_non_space_reverse2();
    test_find_non_space_reverse3();
    test_find_non_space_reverse4();
    test_find_space_reverse1();
    test_find_space_reverse2();
    test_find_space_reverse3();
    test_find_space_reverse4();
}