//
// Created by Fatma on 2/1/2025.
//

#include "Sparse_Matrix.h"
#include <cassert>

Sparse_Matrix::Sparse_Matrix(int row, int column) : row(row),column(column){
    assert(row>0&&column>0);
    this->row=row;
    this->column=column;
}

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
            
           
            
    }

}

void Sparse_Matrix::add_node(node * nodes){


    vec_debug.push_back(nodes);
    length_nodes++;

}

void Sparse_Matrix::insert_end(node *n_node){
    
    link(tail,n_node);
    tail=n_node;
    add_node(n_node);
}

void Sparse_Matrix::insert_front(node * n_node){
  link(n_node,head);
  head=n_node;
  add_node(n_node);
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
      add_node(n_node);

   }  


  
}

void Sparse_Matrix:: get_val(int row , int column){
    
    assert(row>=0&&row<this->row&&column>=0&&column<this->column);

    for (node* cur = head; cur;cur=cur->next){
        if(cur->idx==row){
            cout<<cur->data.get_val(column);
            return;
        }
    }
    
}

void Sparse_Matrix:: print_nonzero_matrix(){

     for (node* cur=head; cur; cur=cur->next){
        cur->data.print_arr_with_nonzero();
     }
     

}

void Sparse_Matrix::print_matrix(){

    int len=0;
    for (node * cur = head; len<row ;len++ ){
        if(cur&&len==cur->idx){
          cur->data.print_arr();
          cur=cur->next;
        }else{
            for (int i = 0; i < this->column; i++){
                cout<<0<<' ';
            }
            cout<<'\n';
            
        }
        if(len==row-1)
        cout<<'\n';
    }
    
}

void Sparse_Matrix::add(const Sparse_Matrix &matrix){


     node * repersent =head;
     for (node* cur = matrix.head; cur&&repersent; )
     {
        if(repersent->idx==cur->idx){

            repersent->data.add(cur->data);
            // that version we are gonna do there as time complexity is O(N) N-> is the max size of them
            /*
            for (Node* curr = cur->data.get_head(),*r_repersent=repersent->data.get_head(); curr&&r_repersent; ){
                
                if(curr->idx==r_repersent->idx){

                  r_repersent->data+=curr->data;
                  curr=curr->next;
                  r_repersent=r_repersent->next;

                }else if(curr->idx<r_repersent->idx)
                  curr=curr->next;
                else
                  r_repersent=r_repersent->next;  
             }*/
             
             cur=cur->next;
             repersent=repersent->next;

        }else if(repersent->idx>cur->idx){
            
            node * n_node=new node(cur->data,cur->idx);
            insert_sorted(n_node);
            cur=cur->next;
        }
            
        else
            repersent=repersent->next;
        
        
     }
     

}


