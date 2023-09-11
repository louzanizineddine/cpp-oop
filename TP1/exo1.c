#include <iostream>
#include <iomanip>

void print_with_precesion(int prec, float number)
{

    int square = number * number;
    float diff = number * number - square  ;
    // std::cout << square;

    std::cout << square << std::setprecision(prec) << (diff) << std::endl;
}

int main()
{
    float number;
    std::cin.precision(1);
    std::cin >> number;

    for (int i = 2; i <= 20 ; i++)
    {
        print_with_precesion(i, number);
    }
    

    return (0);
}