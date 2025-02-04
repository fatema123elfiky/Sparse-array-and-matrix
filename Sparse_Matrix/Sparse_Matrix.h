//
// Created by Fatma on 2/1/2025.
//

#ifndef SPARSE_MATRIX_H
#define SPARSE_MATRIX_H
#include "Array_Linked_List.h"
#include <iostream>

struct node{

    Array_Linked_List data{1};//????
    int idx{};// row and the column is with the data in the linked list
    node * next{};
    node * prev{};
    node(const Array_Linked_List& data , int idx): data(data),idx(idx){}
    /*~node(){
        cout<<"The node of ";data.print_arr();
        cout<<"is detstructed \n";
    }*/
};


class Sparse_Matrix {

private:
    node* head{};
    node* tail{};
    int row {};
    int column{};
    int length_nodes{};//row of determined integers

    vector<node*>vec_debug;
    
    void add_node(node * nodes);

    void insert_front(node * n_node);
    void insert_end(node * n_node);
    void insert_sorted(node * n_node);
    void link(node * first, node * second);

    void set_node(node * n_node);

public:

    Sparse_Matrix(int row , int column=1);
    ~Sparse_Matrix();

    Sparse_Matrix(const Sparse_Matrix & )=delete;
    Sparse_Matrix& operator=(const Sparse_Matrix & )=delete;

    void set_val(int val , int row, int column=0);
    void get_val(int row , int column);
    void print_matrix();
    void print_nonzero_matrix();
    void add(const Sparse_Matrix & matrix);



};


#endif //SPARSE_MATRIX_H
