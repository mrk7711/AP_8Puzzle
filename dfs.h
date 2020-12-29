#ifndef DFS_H
#define DFS_H
#include <iostream>
#include <vector>
#include "puzzle.h"
class Dfs
{
public:
    Dfs()=default;
    std::vector<Node*> DFS(Node*);
    bool Contains(std::vector<Node*> &,Node* );
    void show_trace(std::vector<Node*> &,Node* );
};




#endif