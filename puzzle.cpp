#include "puzzle.h"

Node::Node(int * p)
{
    set_puzzle(p);
}

void Node::set_puzzle (int * p)
{
    for (size_t i{};i<9;i++)
    this->puzzle[i]=p[i];
}

bool Node::goal_test()
{
    
    bool is_goal=true;
    if(this->puzzle[0]!=1)
    {
        is_goal=false;
    }
    if(this->puzzle[1]!=2)
    {
        is_goal=false;
    }
    if(this->puzzle[2]!=3)
    {
        is_goal=false;
    }
    if(this->puzzle[3]!=4)
    {
        is_goal=false;
    }
    if(this->puzzle[4]!=5)
    {
        is_goal=false;
    }     
    if(this->puzzle[5]!=6)
    {
        is_goal=false;
    }
    if(this->puzzle[6]!=7)
    {
        is_goal=false;
    }
    if(this->puzzle[7]!=8)
    {
        is_goal=false;
    }
    if(this->puzzle[8]!=0)
    {
        is_goal=false;
    }                           
    return is_goal;
}

void Node::copy_puzzle(int * a,int* b )
{
    for(size_t i{};i<9;i++)
    {
        a[i]=b[i];
    }
}

void swap(int &a,int &b)
{
    int t{};
    t=b;
    b=a;
    a=t;
}

void Node::movetoRight(int* p,int i)
{
    if(i % 3 < 2)
    {
        int * c{new int[9]};
        copy_puzzle(c,p);
        swap(c[i],c[i+1]);
        Node* child=new Node(c);
        this->children.push_back(child);
        child->Parent=this;
        
    }
}

void Node::movetoLeft(int* p,int i)
{
    if(i % 3 > 0)
    {
        int * c{new int[9]};
        copy_puzzle(c,p);
        swap(c[i-1],c[i]);
        Node* child=new Node(c);
        this->children.push_back(child);
        child->Parent=this;
    }
}

void Node::movetoUp(int* p,int i)
{
    if(i > 2)
    {
        int * c{new int[9]};
        copy_puzzle(c,p);
        swap(c[i-3],c[i]);
        Node* child=new Node(c);
        this->children.push_back(child);
        child->Parent=this;
    }
}

void Node::movetoDown(int* p,int i)
{
    if(i < 6)
    {
        int * c{new int[9]};
        copy_puzzle(c,p);
        swap(c[i],c[i+3]);
        Node* child=new Node(c);
        this->children.push_back(child);
        child->Parent=this;
    }
}

void Node::show_puzzle()
{
    int x{};
    for (size_t i{};i<3;i++)
    {
        for(size_t j{};j<3;j++)
        {
            std::cout<<this->puzzle[x]<<" ";
            x++;
        }
        
        std::cout<<std::endl;

    }
}

bool Node::isthesame_puzzle(int* p)
{
    bool like=true;
    for(size_t i{};i<9;i++)
    {
        if(this->puzzle[i]!=p[i])
        {
            like=false;
        }
    }
    return like;
}

void Node::allmoves()
{
    for (size_t i{};i<9;i++)
    {
        if(this->puzzle[i]==0)
        {
            x=i;
        }
    }
    movetoRight(this->puzzle,x);
    movetoLeft(this->puzzle,x);
    movetoUp(this->puzzle,x);
    movetoDown(this->puzzle,x);
}