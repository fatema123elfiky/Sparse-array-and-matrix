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
                }else
                    cur->data=node->data;

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

    //version 1
    /*if(head->idx){

        int cntr=head->idx+1;
        while (cntr--)
            cout<<0<<' ';
    }

    for (Node* node = head; node==tail ; node=node->next) {
        cout<<node->data<<' ';
        while ( node->next->idx - node->idx - 1 )
            cout<<0<<' ';
    }

    cout<<tail->data<<' ';

    while (length-1-tail->idx-1)
        cout<<0<<' ';

    cout<<'\n';

 */


    // version 2
    int len=0;
    for (Node * node = head ; len<length ; len++) {

        if(node->idx==len){
            cout<<node->data;
            node=node->next;
        }else
            cout<<0;

        if(len==length-2)
            cout<<'\n';
        else
            cout<<' ';

    }


}

void Array_Linked_List::add(const Array_Linked_List &arr) {

    for (Node* cur = arr.head; cur ; cur=cur->next ) {

        bool is_found=false;
        for (Node* node = head; node ; node=node->next) {
            if(cur->idx==node->idx){
                node->data+=cur->data;
                is_found=true;
                break;
            }
        }
        if(!is_found)
            set_val(cur->data,cur->idx);

    }
}