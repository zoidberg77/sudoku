#pragma once
#include<string>

using namespace std;

class Checker {
    private:
        size_t size;
        string numbers;
    public:
       Checker();
       void columeMaster(string);
       size_t columeSlave(string, size_t);
       void rowMaser(string);
       size_t rowSlave(string, size_t);
       void sectionMaster(string);
       size_t sectionSlave(string, size_t);
};