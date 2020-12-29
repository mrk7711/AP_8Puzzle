#include <iostream>
#include "puzzle.h"
#include "bfs.h"
#include "dfs.h"
int main()
{
    int * p={new int[9]};
    p[0]=1;
    p[1]=2;
    p[2]=3;
    p[3]=4;
    p[4]=5;
    p[5]=0;
    p[6]=6;
    p[7]=7;
    p[8]=8;
    Node a(p);

    
    Dfs x;
    std::vector<Node*> t=x.DFS(&a);
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
    // std::cout<<t.size();
    // Bfs y;
    // std::vector<Node*> u=y.BFS(&a);
    // if(u.size()>0)
    // {
    //     for(size_t i{};i<u.size();i++)
    //     {
    //         u[i]->show_puzzle();
    //         std::cout<<"$$$$$$"<<std::endl;
    //     }
    // }
    // else 
    // {
    //     std::cout<<"No Path!";
    // }
    // // std::cout<<t.size();
    return 0;

} 