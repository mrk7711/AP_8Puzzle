#include "dfs.h"

std::vector<Node*> Dfs::DFS(Node* root)
{
    std::vector<Node*> Trace;
    std::vector<Node*> Start;
    std::vector<Node*> Visited;
    Start.push_back(root);
    bool goalFound=false;
    while(Start.size()>0 && goalFound!=true)
    {
        Node * current=Start[Start.size()-1];
        Visited.push_back(current);  //its out DFS
        Start.erase(Start.begin()+Start.size()-1);
        current->allmoves();
        for(size_t i{};i<current->children.size();i++)
        {
            Node* child1=current->children[i];  
            if(child1->goal_test())
            {
                std::cout<<"Goal Found"<<std::endl;
                goalFound=true;
                show_trace(Trace,child1);
            }
            if(!Contains(Start,child1)&&!Contains(Visited,child1))
            {
                Start.push_back(child1);
            }
        }
    }
    return Trace;
}

bool Dfs::Contains(std::vector<Node*> &list,Node* c)
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

void Dfs::show_trace(std::vector<Node*>&trace,Node* c)
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
