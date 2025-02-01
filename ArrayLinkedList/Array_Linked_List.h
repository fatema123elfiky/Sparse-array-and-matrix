//
// Created by Fatma on 2/1/2025.
//

#ifndef SELF_DATASTRUCTURE_ARRAY_LINKED_LIST_H
#define SELF_DATASTRUCTURE_ARRAY_LINKED_LIST_H

#include <vector>
using namespace std;

struct Node {
    int data{};
    int idx{};
    Node*next{};
    Node*prev{};
    Node(int data,int idx):data(data) , idx(idx){}
};

class Array_Linked_List {
private:
    Node *head{};
    Node *tail{};
    int length{};

    int length_nodes{};

    vector<Node*>vec_debug;
    void add_node(Node* node);

    void insert_sorted(Node*node);
    void insert_front(Node*node);
    void insert_end(Node*node);

    void link(Node*first,Node*second);

public:

    Array_Linked_List(int length=0);//
    void set_val(int data , int idx);//
    int get_val(int idx);//
    void print_arr();
    void print_arr_with_nonzero();//
    void add(const Array_Linked_List & arr);


    Array_Linked_List(const Array_Linked_List& list)=delete;
    Array_Linked_List& operator=(const Array_Linked_List& list)=delete;

};


#endif //SELF_DATASTRUCTURE_ARRAY_LINKED_LIST_H
