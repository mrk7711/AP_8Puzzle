#ifndef PUZZLE_H
#define PUZZLE_H
#include <iostream>
#include <vector>

class Node
{
public:
    Node(int* p);
    ~Node()=default;
    std::vector<Node*> children;
    Node* Parent;
    int* puzzle{new int[9]};
    int x{};
    void set_puzzle(int *);
    void copy_puzzle(int *,int*);
    bool goal_test();
    void movetoRight(int*,int);
    void movetoLeft(int*,int);
    void movetoUp(int*,int);
    void movetoDown(int*,int);
    void allmoves();
    void show_puzzle();
    bool isthesame_puzzle(int*);
    friend void swap(int &,int &);

};
#endif