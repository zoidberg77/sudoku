#pragma once
#include<string>

using namespace std;

class Checker {
    private:
        size_t size;
        string numbers;
        void columeMaster();
        void columeSlave(size_t);
        void rowMaster();
        void rowSlave(size_t);
        void boxMaster();
        void boxSlave(size_t);
    public:
        Checker();
        void check();
};