#ifndef UNTITLED_STRING_H
#define UNTITLED_STRING_H

#define MAX_STRING_SIZE 100
#define MAX_N_WORDS_IN_STRING 100
#define MAX_WORD_SIZE 20

#include <stdio.h>
#include <stdbool.h>

typedef struct WordDescriptor {
    char *begin;
    char *end;

} WordDescriptor;

size_t strlen_(const char *begin);

char* find(char *begin, char *end, int ch);

char* findNonSpace(char *begin);

char* findSpace(char *begin);

char* findNonSpaceReverse(char *rbegin, const char *rend);

char* findSpaceReverse(char *rbegin, const char *rend);

int strcmp(const char *lhs, const char *rhs);

char* copy(const char *beginSource, const char *endSource, char *beginDestination);

char* copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int));

char* copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int));

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

void test_copy();

void test_copyIf();

void test_copyIfReverse();

void tests_find_str();

void removeNonLetters(char *s);

void assertString(const char *expected, char *got, char const *fileName, char const *funcName, int line);

void test_removeNonLetters();

void removeExtraSpaces(char *s);

void test_removeExtraSpaces_1();

void removeAdjacentEqualLetters(char *s);

void test_removeAdjacentEqualLetters();

char* copy_if_not_extra_spaces(char *beginSource, const char *endSource, char *beginDestination);

void removeExtraSpaces(char *s);

void test_removeExtraSpaces_1();

void test_removeExtraSpaces_2();

void test_removeExtraSpaces_3();

void removeAdjacentEqualLetters(char *s);

void test_removeAdjacentEqualLetters();

int getWord(char *beginSearch, WordDescriptor *word);

void digitToStart(WordDescriptor word);

void digitToEnd(WordDescriptor word);

void digitToEndAndReverse(WordDescriptor word);

void digits_to_end(char *string);

void digits_to_end_and_reverse(char *string);

void letters_to_end(char *string);

void test_WordDescriptor();


#endif