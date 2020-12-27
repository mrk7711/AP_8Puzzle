#include <iostream>
#include "puzzle.h"
#include "bfs.h"
int main()
{
    int * p={new int[9]};
    p[0]=1;
    p[1]=2;
    p[2]=3;
    p[3]=4;
    p[4]=5;
    p[5]=6;
    p[6]=7;
    p[7]=0;
    p[8]=8;
    Node a(p);
    Bfs x;
    std::vector<Node*> t=x.BFS(&a);
    if(t.size()>0)
    {
        for(size_t i{};i<t.size();i++)
        {
            t[i]->show_puzzle();
        }
    }
    else 
    {
        std::cout<<"No Path!";
    }
    return 0;
} 