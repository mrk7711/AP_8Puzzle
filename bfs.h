#ifndef BFS_H
#define BFS_H
#include <iostream>
#include <vector>
#include "puzzle.h"
class Bfs
{
public:
    Bfs()=default;
    std::vector<Node*> BUS(Node*);
    bool Contains(std::vector<Node*>,Node* );
    void show_trace(std::vector<Node*>,Node* );
};
#endif