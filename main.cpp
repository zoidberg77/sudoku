#include "checker.cpp"
#include <string>
#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>

int main()
{

    using namespace std::chrono;
    Checker x;
    steady_clock::time_point t1 = steady_clock::now();
    x.check();

    steady_clock::time_point t2 = steady_clock::now();

    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

    std::cout << "It took me " << time_span.count() << " seconds.";
    std::cout << std::endl;

    
    return 0;
}
