#ifndef UNTITLED_STRING_H
#define UNTITLED_STRING_H

#define MAX_STRING_SIZE 100
#define MAX_N_WORDS_IN_STRING 100
#define MAX_WORD_SIZE 20

#include <stdio.h>
#include <stdbool.h>

typedef struct WordDescriptor{
    char *begin;
    char *end;

} WordDescriptor;

typedef struct BagOfWords{
    WordDescriptor words[MAX_N_WORDS_IN_STRING];
    size_t size;

} BagOfWords;

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

void replace_digits_with_spaces(char *string);

void test_replace_digits_with_spaces();

bool are_two_words_equal(WordDescriptor a, WordDescriptor b);

void replace(char *source, char *w1, char *w2);

void test_replace();

bool are_two_words_ordered(WordDescriptor word1, WordDescriptor word2);

bool are_words_ordered(char *string);

void test_are_words_ordered();

void getBagOfWords(BagOfWords *bag, char *s);

void print_words_in_reversed_order(char *string);

void test_print_words_in_reversed_order();

int is_palindrome(char *begin, char *end);

int count_palindromes(char *string);

void test_count_palindromes();

void join_strings(char *string1, char *string2, char *result);

void test_join_strings();

void reverse_words_order(char *string);

void test_reverse_words_order();

#endif