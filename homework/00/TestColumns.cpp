#include <iostream>
#include <chrono>
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
class Timer
{
    using clock_t = std::chrono::high_resolution_clock;
    using microseconds = std::chrono::microseconds;
public:
    Timer()
        : start_(clock_t::now())
    {
    }

    ~Timer()
    {
        const auto finish = clock_t::now();
        const auto us = 
            std::chrono::duration_cast<microseconds>
                (finish - start_).count();
        std::cout << us << " us" << std::endl;
    }

private:
    const clock_t::time_point start_;
};
unsigned long long  sumByRows(int i, int N, int ** matrix)
{
    unsigned long long sum(0);
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
            sum += matrix[i][j];
    }
    return sum;
}
unsigned long long sumByCols(int j, int N, int ** matrix)
{   
    unsigned long long sum(0);
    for(int j = 0; j < N; j++)
    {
        for(int i = 0; i < N; i++)
            sum += matrix[i][j];
    }
    return sum;
}
int main()
{
    int N = 100;
    int ** matrix = new int*[N];
    for(int i = 0; i < N; i++)
        matrix[i] = new int[N];
    srand(time(NULL));
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            matrix[i][j] = rand()%1000;
        }
    }
    Timer t;
    volatile unsigned long long res = sumByCols(N/2, N, matrix);
    //volatile unsigned long long res = sumByRows(N/2, N, matrix);
    //std::cout << "Hello world" << std::endl;
    //std::cout << sumByCols(N/2, N, matrix) << std::endl;
    //std::cout << sumByRows(N/2, N, matrix) << std::endl;
    return 0;
}