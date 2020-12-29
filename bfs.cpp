#include "bfs.h"

std::vector<Node*> Bfs::BFS(Node* root)
{
    std::vector<Node*> Trace;
    std::vector<Node*> Start;
    std::vector<Node*> Stop;
    Start.push_back(root);
    bool goalFound=false;
    while(Start.size()>0 && goalFound!=true)
    {
        Node* current=Start[0]; 
        Stop.push_back(current);  //its our BFS
        Start.erase(Start.begin());
        current->allmoves();
        for (size_t i{};i<current->children.size();i++)
        {
            Node* child1=(current->children[i]);
            if(child1->goal_test())
            {
                std::cout<<"Goal Found"<<std::endl;
                goalFound=true;
                show_trace(Trace,child1);
            }
            if(!Contains(Start,child1)&&!Contains(Stop,child1))
            {
                Start.push_back(child1);
            }
        }
    }

    return  Trace;
}

bool Bfs::Contains(std::vector<Node*> &list,Node* c)
{
    bool contains=false;
    for (size_t i{};i<list.size();i++)
    {
        if(list[i]->isthesame_puzzle(c->puzzle))
        {
            contains=true;
        }
    }
    return contains;
}

void Bfs::show_trace(std::vector<Node*>&trace,Node* c)
{
    std::cout<<"Routing...\n";
    Node* current=c; 
    trace.push_back(current);
    while(current->Parent!=nullptr)
    {
        current=current->Parent;
        trace.push_back(current);
    }
}