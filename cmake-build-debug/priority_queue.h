//
// Created by dania on 22.11.2023.
//

#ifndef HAFFMAN_PRIORITY_QUEUE_H
#define HAFFMAN_PRIORITY_QUEUE_H
#include <iostream>
#include <vector>
#include "sort.h"




class priority_queue {
private:
    std::vector<node_of_tree*> heap;

public:
    //методы
    void cost_queue(std::vector<std::pair<char,long double>>& mass){
        heap.resize(mass.size());
        for(int i=0;i<mass.size();++i){
            node_of_tree* new_el=new node_of_tree;
            new_el->abc=mass[i].first;
            new_el->level=1;
            new_el->probability=mass[i].second;
            heap[i]=new_el;
        }
        sort(heap,0,heap.size()-1);
    }
    void show_queue(){
        for(int i=0;i<heap.size();++i){
            std::cout<<heap[i]->abc<<" "<<heap[i]->level<<" "<<heap[i]->probability<<"\n";
        }
    }
    void insert(node_of_tree* new_el){
        heap.push_back(new_el);
        sort(heap,0,heap.size()-1);
    }
    node_of_tree* extract_min(){
        node_of_tree* ans = heap[0];
        heap.erase(heap.begin());
        return ans;
    }
    bool isEmpty(){
        return heap.size()==0;
    }
    int size(){
        return heap.size();
    }
};


#endif //HAFFMAN_PRIORITY_QUEUE_H
