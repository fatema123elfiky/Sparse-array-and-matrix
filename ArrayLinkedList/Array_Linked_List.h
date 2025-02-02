//
// Created by Fatma on 2/1/2025.
//

#ifndef ARRAY_LINKED_LIST_H
#define ARRAY_LINKED_LIST_H

#include<iostream>
#include <vector>
using namespace std;

// the ide of the prev or the double linked list
// was useful here as helped in the insert

// there is no need to do here a destructor as if you made that
// and delete the next and the prev nodes you are gonna make a trouble
// by deleting that node as in loop you gonna access it so it is not good to do that

struct Node {
    int data{};
    int idx{};
    Node*next{};
    Node*prev{};
    Node(int data,int idx):data(data) , idx(idx){}
   ~Node(){ cout<<"The Node "<<data<<"which is "<<this<<" is destruted\n";}

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
    Array_Linked_List(const Array_Linked_List& );//
    Array_Linked_List& operator=(const Array_Linked_List& list);

    void set_val(int data , int idx);//
    int get_val(int idx);//
    void print_arr();
    void print_arr_with_nonzero();//
    void add(const Array_Linked_List & arr);


     // I think that line deletes the copy constructor at all
    /*Array_Linked_List(const Array_Linked_List& )=delete;*/
   /*Array_Linked_List& operator=(const Array_Linked_List& )=delete;*/

    ~Array_Linked_List();
};


#endif //ARRAY_LINKED_LIST_H
