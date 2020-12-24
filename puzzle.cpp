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
    
}