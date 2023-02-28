#include "NumberList.h"
#include <iostream>
void NumberList::Init() // count will be 0
{
    count = 0;
}

bool NumberList::Add(int x) // adds X to the numbers list and increase the data member count.
{
    if (count >= 10) return false;
    else
    {
        numbers[count++] = x;
    }
}  // if count is bigger or equal to 10, the function will return false

void NumberList::Sort() // will sort the numbers vector
{
    for (int i = 0; i < count-1; i++)
        for (int j = i+1; j < count; j++)
            if (numbers[i] > numbers[j])
            {
                int aux = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = aux;
            }
}
void NumberList:: Print()         // will print the current vector
{
    for (int i = 0; i < count; i++)
        printf("%d\n", numbers[i]);
}