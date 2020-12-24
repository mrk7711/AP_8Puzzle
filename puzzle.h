#ifndef PUZZLE_H
#define PUZZLE_H
#include <iostream>
#include <vector>
class Node
{
public:
    Node(int* p);
    // ~Node();
    std::vector<Node> children;
    Node Parent();
    int* puzzle=new int[9];
    int x{};
    void set_puzzle(int *);
    bool goal_test();


};


#endif