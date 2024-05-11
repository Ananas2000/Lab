#ifndef UNTITLED_FILES_H
#define UNTITLED_FILES_H

#define MAX_STRINGS_NUMBER 100
#define MAX_STRING_LENGTH 100
#define MAX_ELEMENTS_NUMBER 100

#include <stdio.h>
#include <stdbool.h>

typedef struct polynomial {
    int power;
    int coefficient;
} polynomial;

bool assert_file(char *file_name, char **true_data);

void make_matrix_storage_by_columns(char *file_name);

void test_make_matrix_storage_by_columns();

void represent_as_floating_point_numbers(char *file_name);

void test_represent_as_floating_point_numbers();

void calculate_expression(char *file_name);

void test_calculate_expression();

void save_only_words_with_sequence(char *file_name, char *sequence);

void test_save_only_words_with_sequence();

void save_only_longest_word_in_string(char *file_name);

void test_save_only_longest_word_in_string();

void remove_polynomials_if_x_sqrt_root(char *file_name, int *size, int x);

void test_remove_polynomials_if_x_sqrt_root();

void sort_negative_after_positive(char *file_name, size_t size);

void test_sort_negative_after_positive();

void test_file1();

#endif