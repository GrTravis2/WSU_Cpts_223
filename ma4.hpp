#ifndef MA4_H
#define MA4_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <queue>
#include <assert.h>

// sorting functions

void insertionSort(std::vector<int>& arr);
void quickSort(std::vector<int>& arr);
void shellSort(std::vector<int>& arr);
void heapSort(std::vector<int>& arr);

// sorting helper functions

inline void isSorted(std::vector<int>& arr);
inline void isBiScanSorted(std::vector<int>& arr, int pivotIndex);

void nSort(std::vector<int>& arr, int n);
int bidirectionalScan(std::vector<int>& arr, int start, int end);
void quickSortHelper(std::vector<int>& arr, int start, int end);

// benchmark helper functions

void printStatistics(const std::vector<double> &durations); // -> print timing data
void sortBenchmark(void (*func)(std::vector<int>&)); // -> runs tests given sorting function

// test cases
void testBidirectionalScan();
// 1, 8, 10, 3, 4

#endif