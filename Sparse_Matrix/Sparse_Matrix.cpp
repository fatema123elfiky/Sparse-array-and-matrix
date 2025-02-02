//
// Created by Fatma on 2/1/2025.
//

#include "Sparse_Matrix.h"
#include <cassert>

Sparse_Matrix::Sparse_Matrix(int row, int column) : row(row),column(column){}

Sparse_Matrix::~Sparse_Matrix() {
    for (node * cur = head; cur ; ) {
      node *nxt=cur->next;
      delete cur;
      cur=nxt;
    }
    cout<<"The Matrix is destructed \n";
}

void Sparse_Matrix::set_val(int val , int row, int column){
    
    if(row>=this->row||column>=this->column||row<0||column<0)
     assert(false);
    
    Array_Linked_List arr (this->column);
    if(!head){
       
       arr.set_val(val,column); 
       node * n_arraylist=new node (arr,row);

       head=tail=n_arraylist;
       add_node(n_arraylist);
    }else{
        
           for (node * cur = head ; cur; cur=cur->next){
            
             if(row==cur->idx){
                cur->data.set_val(val,column);
                return;
             }

           }
           
          
           arr.set_val(val,column);
           node * n_node =new node (arr,row);

           insert_sorted(n_node);
            
           add_node(n_node);
            
    }

}

void Sparse_Matrix::add_node(node * nodes){


    vec_debug.push_back(nodes);
    length_nodes++;

}

void Sparse_Matrix::insert_end(node *n_node){
    
    link(tail,n_node);
    tail=n_node;
}

void Sparse_Matrix::insert_front(node * n_node){
  link(n_node,head);
  head=n_node;
}

void Sparse_Matrix::link(node *first , node *second){
   
   if(first)
     first->next=second;
   if(second)
      second->prev=first;  
}

void Sparse_Matrix::insert_sorted(node * n_node){
  

   if(n_node->idx<head->idx)
    insert_front(n_node);
   else if(n_node->idx>tail->idx)
     insert_end(n_node);
   else{
      
      for (node* cur = head; cur; cur=cur->next){
         if(cur->idx>n_node->idx){
            link(cur->prev,n_node);
            link(n_node,cur);
            break;
         }
      }

   }  

  
}





