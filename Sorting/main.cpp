#include "quicksort.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include <list>

int main(int argc, const char *argv[])
{
    std::vector<int> numbers1{3, 5, 1, 9, 0, 7, 6, 2, 4, 8};
    std::vector<int> numbers2 = numbers1;

    std::cout << "Unsorted:\t\t";
    std::for_each(numbers1.cbegin(), numbers1.cend(), [] (const int& i) {
        std::cout << i << " ";
    });
    std::cout << std::endl;

    std::cout << "std::sort():\t";
    std::sort(numbers1.begin(), numbers1.end());
    for (int number : numbers1)
        std::cout << number << " ";
    std::cout << std::endl;

    std::cout << "Binna::sort():\t";
    Binna::sort(numbers2.begin(), numbers2.end());
    for (int number : numbers2)
        std::cout << number << " ";
    std::cout << std::endl;

    return 0;
}
