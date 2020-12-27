#include <iostream>
#include "puzzle.h"
#include "bfs.h"
int main()
{
    int * p={new int[9]};
    p[0]=1;
    p[1]=3;
    p[2]=4;
    p[3]=7;
    p[4]=0;
    p[5]=2;
    p[6]=5;
    p[7]=8;
    p[8]=6;
    Node a(p);

    Bfs x;
    std::vector<Node*> t=x.BFS(&a);
    if(t.size()>0)
    {
        for(size_t i{};i<t.size();i++)
        {
            t[i]->show_puzzle();
            std::cout<<"$$$$$$"<<std::endl;
        }
    }
    else 
    {
        std::cout<<"No Path!";
    }
    return 0;
} 