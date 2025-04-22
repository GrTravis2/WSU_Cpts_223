
#include "ma4.hpp"
#include <functional>
#include <queue>
#include <vector>

void insertionSort(std::vector<int> &arr) {
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

void quickSort(std::vector<int> &arr) {

    //int pivot = bidirectionalScan(arr); // partition before quick sort

//}

//void quickSortHelper(std::vector<int>& arr) {

    int pivot = bidirectionalScan(arr); // get pivot
    std::vector<int> vec;

    if(pivot > 0) { // call recursively on arr range below pivot
        for(int i = 0; i < pivot; i++) { vec.push_back(arr[i]); }
        quickSortHelper(vec);
        vec.clear();
    }
    if(pivot < arr.size()) { // call recursively on arr range above pivot
        for(int i = arr.size() - 1; i > pivot; i--) { vec.push_back(arr[i]); }
        quickSortHelper(vec);
        vec.clear();
    }
}

int bidirectionalScan(std::vector<int>& arr) {

    // pick a random element as pivot
    int size = arr.size();
    int pivot = std::rand() % size; // note that std::srand seeds before call...
    int i = 0;
    int j = size - 1; // get left and right pointers
    int buff = 0;

    while(i <= j) { // continue loop until i crosses j!
        if (arr[i] > arr[pivot] && arr[j] < arr[pivot]) { // make the swap!
            buff = arr[i], arr[i] = arr[j], arr[j] = buff;
            i++;
            j--;
        }
        while(i < size && arr[i] <= arr[pivot]) { i++; }
        while(j > -1   && arr[j] >= arr[pivot]) { j--; }
    }

    // should be in correct order for algo, just swap pivot and i
    buff = arr[i], arr[i] = arr[pivot], arr[pivot] = buff;

    return i; // return pivot index for quicksort
}

void shellSort(std::vector<int> &arr) {
    nSort(arr, 7); // -> start recursive process, use increment seq 7, 5, 3, 1
}

void nSort(std::vector<int>& arr, int n) {

    // base case!
    if(n > 0) {
        // temp variables
        int size = arr.size(); 
        int index = -1;
        std::vector<int> vec;

        // created floor(size / n) vectors and sort in place before emptying
        for(int i = 0; i < n; i++) {
            index = i;
            while(index < size) {
                vec.push_back(arr[index]);
                index += n;
            }
            insertionSort(vec);
            vec.clear();
        }

        // repeat with reduced increment sequence
        nSort(arr, n - 2);
    }
}

void heapSort(std::vector<int> &arr) {
    // create min heap and load with input data
    std::priority_queue<int, std::vector<int>, std::greater<int> > minHeap;
    for (auto i : arr) { minHeap.push(i); }

    // remove from min heap until empty -> data should be sorted!
    int i = 0;
    while(!minHeap.empty()) {
        arr[i] = minHeap.top();
        minHeap.pop();
    }
}

// sorting helper functions

inline void isSorted(std::vector<int>& arr) {
    //bool ok = true;
    int size = arr.size();

    for (int i = 1; i < size; i++) {
        //if(arr[i - 1] > arr[i]) { ok = false; }
        assert(!(arr[i - 1] > arr[i]));
    }
}

// benchmark helper functions

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
    //const int N = 10000;
    const int N = 10; // -> smaller N for testing...
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
        isSorted(data); // extra check to validate

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