//
// Created by Fatma on 2/1/2025.
//
#include "Sparse_array_matrix/Array_Linked_List.h"
#include <iostream>

void test1(){

    Array_Linked_List arr (10);
    arr.set_val(50,5);
    arr.set_val(20,2);
    arr.set_val(70,7);
    arr.set_val(40,4);
    arr.print_arr();
    arr.print_arr_with_nonzero();
    cout<<arr.get_val(7)<<'\n';

    Array_Linked_List arr2(10);
    arr2.set_val(1,4);
    arr2.set_val(3,7);
    arr2.set_val(4,6);

    arr.add(arr2);
    arr.print_arr();


}



int main(){

   test1();
   cout<<"NO RTE\n";

   cout<<"You are great";

}
