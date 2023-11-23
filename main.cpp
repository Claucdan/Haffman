#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include "cmake-build-debug/priority_queue.h"

bool comp(std::pair<char,int>& first,std::pair<char,int>& second){
    if(first.second == second.second)
        return first.first<second.first;
    else
        return first.second<second.second;
}

class Haffman{
private:
    /*Контейнеры*/
    std::string text;
    std::vector<std::pair<char,int>> abc;
    std::vector<std::pair<char,long double>> probability_of_abc;
    std::vector<node_of_tree> graf_of_haffman;
    priority_queue selection_of_two_min;

    std::vector<std::vector<node_of_tree>> layer;




    /*Методы private секции*/
    void _abc_creat(){
        std::cin>>text;
        for(int i=0;i<text.size();++i){
            int j=0;
            for(;j<abc.size();++j){
                if(abc[j].first==text[i])
                    break;
            }
            if(j==abc.size()){
                abc.push_back(std::make_pair(text[i],1));
            }
            else{
                abc[j].second++;
            }
        }
        sort(abc.begin(),abc.end(), comp);
    }
    void _show_abc(){
        for(int i=0;i< abc.size();++i){
            std::cout<<abc[i].first<<" "<<abc[i].second<<"\n";
        }
    }
    void _probability_of_abc_creat(){
        probability_of_abc.resize(abc.size());
        for(int i=0;i<abc.size();++i){
            probability_of_abc[i]=std::make_pair(abc[i].first,(long double)abc[i].second/text.size());
        }
    }
    void _show_probability_of_abc(){
        for(int i=0;i<probability_of_abc.size();++i){
            std::cout<<probability_of_abc[i].first<<" "<<probability_of_abc[i].second<<"\n";
        }
    }
    void _selection_of_two_min_creat(){
        selection_of_two_min.cost_queue(probability_of_abc);
    }
    void _haffman_tree_creation(){
        while(selection_of_two_min.size()>1){
            node_of_tree* first=selection_of_two_min.extract_min();
            node_of_tree* second=selection_of_two_min.extract_min();
            node_of_tree* third_parent=new node_of_tree;
            third_parent->abc=std::max(first->abc,second->abc);
            third_parent->level= std::max(first->level,second->level)+1;
            third_parent->probability=first->probability+second->probability;
            third_parent->left_child=first;
            third_parent->right_child=second;
            std::cout<<third_parent->abc<<" "<<third_parent->level<<" "<<third_parent->probability<<"\n";
            selection_of_two_min.insert(third_parent);
        }
    }
    void _show_selection_of_two_min(){
        selection_of_two_min.show_queue();
    }
public:
    Haffman(){
        _abc_creat();
    }
    void probability_of_abc_creat(){
        _probability_of_abc_creat();
    }
    void show_probability_of_abc(){
        _show_probability_of_abc();
    }
    void selection_of_two_min_creat(){
        _selection_of_two_min_creat();
    }
    void show_selection_of_two_min(){
        _show_selection_of_two_min();
    }
    void huffman(){
        _haffman_tree_creation();
    }
};


int main() {
    //setlocale(LC_ALL, "");
    Haffman coding;
    coding.probability_of_abc_creat();
    coding.selection_of_two_min_creat();
    coding.show_selection_of_two_min();
    coding.huffman();

    priority_queue mass_of_layer;
    return 0;
}
