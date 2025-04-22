
#include "ma4.hpp"

void insertionSort(std::vector<int> &arr)
{
    for (size_t i = 1; i < arr.size(); ++i)
    {
        int key = arr[i];
        size_t j = i;
        while (j > 0 && arr[j - 1] > key)
        {
            arr[j] = arr[j - 1];
            --j;
        }
        arr[j] = key;
    }
}

void quickSort(std::vector<int> &arr)
{
    std::cout << "TODO: Implement quicksort" << std::endl;
    // You might have to create another function to properly implement quicksort. This is ok
}

void shellSort(std::vector<int> &arr)
{
    std::cout << "TODO: Implement shell sort" << std::endl;
}

void heapSort(std::vector<int> &arr)
{
    std::cout << "TODO: Implement heap sort" << std::endl;
}

void printStatistics(const std::vector<double> &durations)
{
    double minTime = *min_element(durations.begin(), durations.end());
    double maxTime = *max_element(durations.begin(), durations.end());
    double avgTime = accumulate(durations.begin(), durations.end(), 0.0) / durations.size();

    double variance = 0.0;
    for (double t : durations)
    {
        variance += (t - avgTime) * (t - avgTime);
    }
    double stdDev = sqrt(variance / durations.size());

    std::cout << "\n=== Statistics ===\n";
    std::cout << "Min Time: " << minTime << " ms\n";
    std::cout << "Max Time: " << maxTime << " ms\n";
    std::cout << "Average Time: " << avgTime << " ms\n";
    std::cout << "Standard Deviation: " << stdDev << " ms\n";
}

void sortBenchmark(void(*func)(std::vector<int>&)) {
    // Size of the collection
    const int N = 10000;
    // Max limit for the random generation
    const int MAX_VAL = 100000;
    // Total trial (use the same for other sorting algorithms)
    const int TRIALS = 10;

    srand(static_cast<unsigned>(time(nullptr)));

    std::vector<double> durations;

    for (int trial = 0; trial < TRIALS; ++trial)
    {
        std::vector<int> data(N);
        // Generate 10,000 random numbers and populate data
        for (int i = 0; i < N; ++i)
        {
            data[i] = rand() % (MAX_VAL + 1);
        }

        auto start = std::chrono::high_resolution_clock::now();
        func(data); // sort data
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double, std::milli> elapsed = end - start;
        durations.push_back(elapsed.count());

        std::cout << "Trial " << trial + 1 << " duration: " << elapsed.count() << " ms\n";
    }

    printStatistics(durations);
}

/*
int main()
{
    

    

    return 0;
}
*/