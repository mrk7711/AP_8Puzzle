#include <iostream>
#include "puzzle.h"
int main()
{
    int * p={new int[9]};
    for(size_t i{};i<9;i++)
    {
        p[i]=i;
    }
    Node a(p);
    a.allmoves();
    a.show_puzzle();
    return 0;
} 