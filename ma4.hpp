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

// sorting functions

void insertionSort(std::vector<int>& arr);
void quickSort(std::vector<int>& arr);
void shellSort(std::vector<int>& arr);
void heapSort(std::vector<int>& arr);

// benchmark helper functions

void printStatistics(const std::vector<double> &durations); // -> print timing data
void sortBenchmark(void(*func)(std::vector<int>&)); // -> runs tests given sorting function

#endif