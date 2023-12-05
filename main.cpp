#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>


struct Node{
    double data;
    char sym=' ';
    Node* left= nullptr;
    Node* right= nullptr;
    Node(){}
    Node(double data):data(data){}
};
bool sort_of_up(Node* first,Node* second){
    if(first->data!=second->data)
        return first->data>second->data;
    return first->sym>second->sym;
}
bool sort_of_down(Node* first,Node* second){
    if(first->data!=second->data)
        return first->data<second->data;
    return first->sym<second->sym;
}

class Haffman{
private:
    std::string text;
    std::vector<std::pair<char,int>> abc;
    std::vector<Node*> probability_of_abc;
    Node* start_of_tree_of_haffman;
    std::map<char,int> replace_code;
    /*Структура необходимая для кучи приоритетов*/
    struct compare
    {
        bool operator()(Node* left, Node* right)
        {
            return (left->data > right->data);
        }
    };


    /*Считывание изначального сообщения*/
    void _get_text(){
        std::cin>>text;
    }
    /*Создание словаря с количеством повторений в сообщения символа*/
    void _create_abc(){
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
    }
    /*Создание словаря с вероятностями*/
    void _create_probability_of_abc() {
        probability_of_abc.resize(abc.size());
        for (int i = 0; i < abc.size(); i++) {
            probability_of_abc[i]=new Node;
            probability_of_abc[i]->sym = abc[i].first;
            probability_of_abc[i]->data = (double) abc[i].second / text.size();
        }
    }
    /*Создание словаря закодированных символов*/
    void _encode(){
        std::priority_queue<Node*, std::vector<Node*>, compare> heap;
        for (int i = 0; i < probability_of_abc.size(); ++i)
        {
            heap.push(probability_of_abc[i]);
        }
        while (heap.size() != 1)
        {
            Node* left= heap.top();heap.pop();
            Node* right=heap.top();heap.pop();
            Node* top = new Node(left->data + right->data);
            top->left = left;
            top->right = right;
            heap.push(top);
        }
        start_of_tree_of_haffman=heap.top();
        _create_replace_code(start_of_tree_of_haffman,"");
    }
    /*Нахождение длины кодового слова для символов(составление алфавита замен)*/
    void _create_replace_code(Node* root,std::string code){
        if(root== nullptr)
            return;
        if(root->left== nullptr && root->right== nullptr){
            replace_code.insert(std::pair<char,int>(root->sym,code.size()));
        }
        _create_replace_code(root->left,code+"0");
        _create_replace_code(root->right,code+"1");
    }
    /*Нахождение длинны закодированного сообщения*/
    int _length_of_encode_message(){
        int sum=0;
        for(char i:text){
            sum+=replace_code[i];
        }
        return sum;
    }
public:
    Haffman(){
        _get_text();
    }
    void create_abc(){
        _create_abc();
    }
    void create_probability_of_abc(){
        _create_probability_of_abc();
    }
    void  encode(){
        _encode();
    }
    void length_of_encode_message(){
        std::cout<<_length_of_encode_message();
    }
};


int main(){
    Haffman code;
    code.create_abc();
    code.create_probability_of_abc();
    code.encode();
    code.length_of_encode_message();
    return 0;
}