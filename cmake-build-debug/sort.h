//
// Created by dania on 23.11.2023.
//

#ifndef HAFFMAN_SORT_H
#define HAFFMAN_SORT_H
#include <iostream>
struct node_of_tree {
    char abc;
    int level;
    long double probability;
    node_of_tree *left_child = nullptr;
    node_of_tree *right_child = nullptr;
};
bool comp_of_sort(node_of_tree* first,node_of_tree* second){
    if(first->probability == second->probability)
        return first->abc < second->abc;
    return first->probability < second->probability;
}
void sort(std::vector<node_of_tree*>& mass,int left, int right){
    if(left>=right)return;
    node_of_tree* key=mass[left+(right-left)/2];
    int i=left,
        j=right;
    while(i<j){
        while(comp_of_sort(mass[i],key))i++;
        while(comp_of_sort(key,mass[j]))j--;
        if(i<=j)
            std::swap(mass[i++],mass[j--]);
    }
    if(j>left)sort(mass,left,j);
    if(i<right)sort(mass,i,right);
}
#endif //HAFFMAN_SORT_H
