#include "checker.h"
#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

Checker::Checker()
{
    cout << "Please enter Sudoku size, for example 9x9 as 9" << endl;
    cin >> size;
    cout << "Please enter the Sudoku as string" << endl;
    cin >> numbers;
    if (numbers.size() != size * size)
        throw runtime_error("something is wrong with the string");

}
void Checker::check()
{
    #pragma omp parallel sections
    #pragma omp parallel section {
        this->columeMaster();
    }
    #pragma omp parallel section {
        this->rowMaster();
    }
    #pragma omp parallel section{
        this->boxMaster();
    }
}
void Checker::columeMaster()
{
        for (size_t i = 1; i < size; i++)
        {
            this->columeSlave(i);
        }
void Checker::rowMaster()
{
        for (size_t i = 1; i < size+1; i++)
        {
            this->rowSlave(i);
        }
}
void Checker::boxMaster()
{
        for (size_t i = 1; i < size+1; i++)
        {
            this->boxSlave(i);
        }
}
void Checker::columeSlave(size_t i)
{
    string temp(1, numbers.at(i));
    for (size_t c{1}; c < size; c++)
    {
        temp += numbers.at(i + c * size);
    }
    set<char> a(temp.begin(), temp.end());
    if (a.size() != size)
        cout << "error in colume " << i << endl;
}
void Checker::rowSlave(size_t i)
{
    string temp = numbers.substr(i * size - size, size);
    set<char> a(temp.begin(), temp.end());
    if (a.size() != size)
        cout << "error in row " << i << endl;
}
void Checker::boxSlave(size_t i)
{
    size_t base = (i - 1) / (size / 3);
    string temp2 = numbers.substr(size * base * (size / 3), size * 3);
    string temp = temp2.substr(i * (size / 3) - (size / 3) - size * base, size / 3);
    for (size_t c{1}; c < size / 3; c++)
    {
        temp += temp2.substr(i * (size / 3) - (size / 3) - size * base + c * size, size / 3);
    }
    set<char> a(temp.begin(), temp.end());
    if (a.size() != size)
        cout << "error in box " << i << endl;
}
