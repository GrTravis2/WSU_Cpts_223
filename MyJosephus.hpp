#ifndef MY_JOSEPHUS
#define MY_JOSEPHUS

class MyJosephus {
    protected:
        int M; // step move, where M lands that destination is removed from collection
        int N; // number of destinations read in from data

    public:
        // constructor
        MyJosephus(const int& M, const int& N);

        // destructor -> must override!
        virtual ~MyJosephus() = 0;

        // public abstract methods
        virtual void clear() = 0;
        virtual int getCurrentSize() = 0;
};


#endif