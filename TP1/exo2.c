#include <iostream>
#include <algorithm>
using namespace std;

int ajouter(int num1, int num2)
{
    return num1 + num2;
}

void min_max(int tab[], int size, int& max, int& min){
    min = std::min_element(std::begin(tab), std::end(tab));
    max = std::max_element(std::begin(tab), std::end(tab));
}

int main()
{
    int tab[3] = {1, 2, 3};
    int min;
    int max;

    min_max(tab, 3, &min, &max);
    return 0;
}