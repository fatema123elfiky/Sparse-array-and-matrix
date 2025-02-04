//
// Created by Fatma on 2/1/2025.
//

#include "Array_Linked_List.h"
#include <cassert>
#include <iostream>

Array_Linked_List::Array_Linked_List(int length) {

    assert(length>0);
    this->length=length;
}

void Array_Linked_List::set_val(int data, int idx) {

    if(idx>length-1||idx<0)
        assert(false);

    Node* item=new Node(data,idx);
    //add_node(item);

    if(length_nodes==0) {
        head = tail = item;
        add_node(item);
    }
    else{
        insert_sorted(item);
    }
}

void Array_Linked_List::add_node(Node *node) {
    length_nodes++;
    vec_debug.push_back(node);
}

void Array_Linked_List::insert_sorted(Node *node) {

    if(node->idx < head->idx)
        insert_front(node);
    else if(node->idx > tail->idx)
        insert_end(node);
    else{

        for (Node* cur = head; cur ; cur=cur->next) {

            if(cur->idx>=node->idx){

                if(cur->idx>node->idx){
                    link(cur->prev, node);
                    link(node, cur);
                    add_node(node);
                }else{
                    cur->data=node->data;
                    delete node;// added
                }

                break;
            }

        }

    }

}

void Array_Linked_List::insert_front(Node *node) {

    link(node,head);
    head=node;
    add_node(node);

}

void Array_Linked_List::insert_end(Node *node) {

    link(tail,node);
    tail=node;
    add_node(node);
}

void Array_Linked_List::link(Node *first, Node *second) {
    if(first)
        first->next=second;
    if(second)
        second->prev=first;
}

int Array_Linked_List:: get_val(int idx){

    assert(idx>=0&&idx<length);

    for (Node* cur = head; cur ; cur=cur->next) {
        if(cur->idx==idx)
            return cur->data;
    }

    return 0;

}

void Array_Linked_List::print_arr_with_nonzero() {
    for (Node* cur = head; cur ; cur=cur->next) {
        cout<<cur->data<<' ';
    }
    cout<<'\n';
}

void Array_Linked_List::print_arr(){




    // version 2
    int len=0;
    for (Node * node = head ; len<length ; len++) {

        if(node&&node->idx==len){
            cout<<node->data;
            node=node->next;
        }else
            cout<<0;

        if(len==length-1)
            cout<<'\n';
        else
            cout<<' ';

    }


}

void Array_Linked_List::add(const Array_Linked_List &arr) {

// version 1
    /*for (Node* cur = arr.head; cur ; cur=cur->next ) {

        bool is_found=false;
        for (Node* node = head; node ; node=node->next) {
            if(cur->idx==node->idx){
                node->data+=cur->data;
                is_found=true;
                break;
            }
        }
        if(!is_found&&cur->idx<length)
            set_val(cur->data,cur->idx);

    }*/
   //version 2
    Node* curr, *r_repersent;
   for ( curr = arr.head,r_repersent=head ; curr&&r_repersent; ){
                if(curr->idx==r_repersent->idx){

                  r_repersent->data+=curr->data;
                  curr=curr->next;
                  r_repersent=r_repersent->next;

                }else if(/*curr->idx<length&&*/curr->idx<r_repersent->idx){
                  set_val(curr->data,curr->idx);
                  curr=curr->next;
                }
                else {
                  //set_val(curr->data,curr->idx);
                  r_repersent=r_repersent->next;
                }
                  
   }
   while(curr&&curr->idx<length){
       set_val(curr->data,curr->idx);
       curr=curr->next;
   }
}

// revise
Array_Linked_List::~Array_Linked_List(){

    for (Node* cur = head; cur ; ) {
        Node* node= cur;
        cur=cur->next;
        delete node;
    }
    //cout<<"The Arraylist is destroyed\n";
}

// changes
Array_Linked_List::Array_Linked_List(const Array_Linked_List &list) {


    if(list.head){

        head=new Node(list.head->data,list.head->idx);
        //tail=new Node(list.tail->data,list.tail->idx);

        Node * cur;
        for ( cur = head; cur->next ; cur=cur->next) {
        Node* node = new Node (cur->next->data,cur->next->idx);
        link(cur,node);
        }
        tail=cur;
    
    }
    

    length=list.length;
    length_nodes=list.length_nodes;
    for (int i = 0; i < list.vec_debug.size(); ++i) {
        Node* node=new Node(list.vec_debug[i]->data,list.vec_debug[i]->idx);
        vec_debug.push_back(node);
    }

}

Array_Linked_List& Array_Linked_List:: operator=(const Array_Linked_List& list){


    //self assignment
    if(this==&list)
        return *this;

    while (head){
        Node *cur=head->next;
        delete head;
        head=cur;
    }
    head= nullptr;
    tail= nullptr;

    for (int i = 0; i < vec_debug.size() ; ++i)
        delete vec_debug[i];

    vec_debug.clear();



    if(list.head){

        head=new Node(list.head->data,list.head->idx);
        //tail=new Node(list.tail->data,list.tail->idx);

        Node * cur;
        for ( cur = head; cur->next ; cur=cur->next) {
            Node* node = new Node (cur->next->data,cur->next->idx);
            link(cur,node);
        }
        tail=cur;


    }
    

    length=list.length;
    length_nodes=list.length_nodes;
    for (int i = 0; i < list.vec_debug.size(); ++i) {
        Node* node=new Node(list.vec_debug[i]->data,list.vec_debug[i]->idx);
        vec_debug.push_back(node);
    }

    return *this;



}


Node* Array_Linked_List::get_head(){

    return head;
}

