#pragma once
#include <iostream>

void merge(int arr[], int p, int q, int r);
void print_array(int arr[], int size);
void quick_sort(int arr[], int p, int r);
void quick_sort_r(int arr[], int p, int r);
int partition(int arr[], int p, int r);
int randomized_partition(int arr[], int p, int r);
int randomized_select(int arr[], int p, int r, int i);
void swap(int* a, int* b);
