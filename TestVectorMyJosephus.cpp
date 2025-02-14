
#include "TestVectorMyJosephus.hpp"

void TestVectorMyJosephus::runSimulation() {

    // set up log file writing and check its open
    std::ofstream results("VectorResults.log");
    if (results.is_open()) {// -> start sim!
        float elapsedTimes[MAX_N];
        clock_t start, end;
        std::srand(time(0));
        int M = -1;

        for (int N = 1; N < MAX_N + 1; N++) {
            M = std::rand() % N;
            int* elimSequence = nullptr;

            // time stamp start -> simulate Josephus -> time stamp end -> write line
            start = clock();
            elimSequence = VectorMyJosephus(M, N).run();
            end = clock();
            elapsedTimes[N-1] = (float)(end - start)/CLOCKS_PER_SEC;
            results << "input " 
                    << "M=" << M
                    << ", N=" << N
                    << " finished with elapsed time: " << elapsedTimes[N-1]
                    << ", elimination sequence: "; 
            // output elim sequence + end line
            for (int i = 0; i < N - 1; i++) { results << elimSequence[i] << ", ";}
            results << "\n";
            delete elimSequence;
        }

        // compute average for all elapsed times
        double sum = 0.0;
        for (int i = 0; i < MAX_N; i++) { sum += elapsedTimes[i]; }
        results << "average elapsed time: " << sum / MAX_N;
        results.close();
    } else {
        std::cout << "error opening file" << std::endl;
    }
}

// ppt example M = 2, N = 5
void TestVectorMyJosephus::testExample() {
    VectorMyJosephus t(2, 5);
    // first step -> remove 2
    t.eliminateDestination();
    assert(!t.contains(2));

    // 2nd step -> remove 0
    t.eliminateDestination();
    assert(!t.contains(0));

    // 3rd step -> remove 4
    t.eliminateDestination();
    assert(!t.contains(4));

    // 4th step -> remove 1
    t.eliminateDestination();
    assert(!t.contains(1));

    // final -> one destination remaining -> should be 3
    assert(t.getCurrentSize() == 1 && t.contains(3));

    // evil test case
    //VectorMyJosephus t2(16, 21);
    //t2.run();
}