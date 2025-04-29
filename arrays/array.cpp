#include <iostream>

using std::cout;
using std::endl;

int main()
{
    unsigned int capacity = 12;
    int* array = new int[capacity];


    int i = 0;
    while (i <= capacity)
    {
        array[i] = i * 2;
        i++;
    }

    int j= 0;
    while (j <= capacity + 200000)
    {
        cout << "At index [" << j << "] : " << array[j] << endl;
        j++;
    }

    // cout << (int) array << endl;
    // cout << (int) array * 2 << endl;

}