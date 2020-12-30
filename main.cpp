#include <iostream>
#include "puzzle.h"
#include "bfs.h"
#include "dfs.h"
#include <ctime>

void show(int *  &);

int getInv(int *  &);

int main()
{
    std::cout<<"Welcome to puzzle!"<<std::endl;
    int c{};
    int ch;
    char y='y';
    while(y=='y')
    {
        std::cout<<"If you want to enter your puzzle please select 1:\n";
        std::cout<<"If you want to see the solution of random puzzle please select 2:\n";
        std::cin>>ch;
        switch(ch)
        {
            case 1:
            {
                int * p={new int[9]};
                p[0]=0;
                p[1]=0;
                p[2]=0;
                p[3]=0;
                p[4]=0;
                p[5]=0;
                p[6]=0;
                p[7]=0;
                p[8]=0;
                show(p);
                int c;
                for(size_t i{};i<9;i++)
                {
                    std::cout<<"Please enter the number"<<i+1<<": \n";
                    std::cin>>c;
                    p[i]=c;
                    show(p);
                }
                if(getInv(p)%2==0)
                {
                    std::cout<<"Puzzle is Solvable\n";
                    std::cout<<"Select the Algorithm?\n";
                    std::cout<<"BFS?-->1\n";
                    std::cout<<"DFS?-->2\n";
                    std::cin>>c;
                    switch(c)
                    {
                    case 1:
                    {
                        Node a(p);
                        Bfs y;
                        std::vector<Node*> u=y.BFS(&a);
                        if(u.size()>0)
                        {
                            for(size_t i{};i<u.size();i++)
                            {
                                u[i]->show_puzzle();
                                std::cout<<"$$$$$$"<<std::endl;
                            }
                        }
                        else 
                        {
                            std::cout<<"No Path!";
                        }
                        std::cout<<"Number of States: "<<u.size()<<std::endl;
                        break;
                    }
                    case 2:
                    {
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
                        std::cout<<"Number of States: "<<t.size()<<std::endl;
                        break;
                    }
                    default :
                    {
                        break;
                    }
                    }
                }
                else
                {
                    std::cout<<"Sorry Puzzle is not solvable!\n";
                }
                
                break;
            }
            case 2:
            {
                srand(time(0));
                int *p={new int[9]};
                size_t i=0;
                while(i<9)
                {
                    p[i]=(rand()%9);
                    for(size_t j{};j<i;j++)
                    {
                        if(p[i]==p[j])
                        {
                            i--;
                            break;
                        }
                    } 
                    i++;
                }
                show(p);
                if(getInv(p)%2==0)
                {
                    std::cout<<"Puzzle is Solveble\n";
                    std::cout<<"Select the Algorithm?\n";
                    std::cout<<"BFS?-->1\n";
                    std::cout<<"DFS?-->2\n";
                    std::cin>>c;
                    switch(c)
                    {
                        case 1:
                        {
                            Node a(p);
                            Bfs y;
                            std::vector<Node*> u=y.BFS(&a);
                            if(u.size()>0)
                            {
                                for(size_t i{};i<u.size();i++)
                                {
                                    u[i]->show_puzzle();
                                    std::cout<<"$$$$$$"<<std::endl;
                                }
                            }
                            else 
                            {
                                std::cout<<"No Path!";
                            }
                            std::cout<<"Number of States: "<<u.size()<<std::endl;
                            break;
                        }
                        case 2:
                        {
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
                            std::cout<<"Number of States: "<<t.size()<<std::endl;
                            break;
                        }
                        default:
                        {
                            break;
                        }
                    }
                }
                else
                {
                    std::cout<<"Sorry Puzzle is not solvable!\n";
                }
                    break;
            }
            default:
            {
                break;
            }
        }
        std::cout<<"Do you want to continue?(y or n)";
        std::cin>>y;
        if(y!='y')
        {
            std::cout<<"Thank you so much!!\n";
            break;
        }
    }
return 0;
}

void show(int * &p)
{
    int x{};
    for (size_t i{};i<3;i++)
    {
        for (size_t j{};j<3;j++)
        {
            std::cout<<p[x]<<" ";
            x++;
        }
        std::cout<<std::endl;
    }
}

int getInv(int *  &p)
{
    int cunt=0;
    for (int i = 0; i <8; i++) 
    {
        for (int j = i+1; j < 9; j++)
        {
            if (p[j] && p[i] &&  p[i] > p[j]) 
            cunt++;
        }
    }
    return cunt;
}
