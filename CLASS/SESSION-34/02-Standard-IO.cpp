#include <iostream>
#include <cstdlib>

// std::ostream -> class | std::cout -> Object of class std::ostream
// std::istream -> class | std::cin  -> Object of class std::istream

int main()
{
    std::cout << "Enter the integer number:";
    int num;
    std::cin >> num;

    std::cout << "Enter a floating point number:";
    float f_num;
    std::cin >> f_num;

    std::cout << "Value(num) :" << num <<", Value(f_num) : " << f_num << std::endl;

    return EXIT_SUCCESS;
}