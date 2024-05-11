#ifndef UNTITLED_FILES_H
#define UNTITLED_FILES_H

#define MAX_STRINGS_NUMBER 100
#define MAX_STRING_LENGTH 100

#include <stdio.h>
#include <stdbool.h>

bool assert_file(char *file_name, char **true_data);

void make_matrix_storage_by_columns(char *file_name);

void test_make_matrix_storage_by_columns();

void test_file1();

void represent_as_floating_point_numbers(char *file_name);

void test_represent_as_floating_point_numbers();

#endif