//
// Created by Fatma on 2/1/2025.
//
#include "Array_Linked_List.h"
#include "Sparse_Matrix.h"
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

// test for the sparse

void test_col() {
	ColumnLinkedList collst(12);
	collst.set_value(10, 10);
	collst.set_value(5, 5);
	collst.set_value(2, 2);
	collst.set_value(7, 7);
	collst.set_value(4, 4);
	//collst.print_row();
	collst.print_row_nonzero();
	collst.add(collst);
	collst.print_row_nonzero();
}

void test_sparse() {
	Sparse_Matrix mat(10, 10);
	mat.set_val(5, 3, 5);
	mat.set_val(7, 3, 7);
	mat.set_val(2, 3, 2);
	mat.set_val(0, 3, 2);
	mat.set_val(6, 5, 6);
	mat.set_val(4, 5, 4);
	mat.set_val(3, 7, 3);
	mat.set_val(1, 7, 1);
	//mat.set_value(1, 70, 1);
	mat.print_matrix();
	mat.print_nonzero_matrix();
    cout<<"//////////////////////////////////\n";
	Sparse_Matrix mat2(10, 10);
	mat2.set_val(5, 1, 9);
	mat2.set_val(6, 3, 8);
	mat2.set_val(9, 9, 9);
	mat.add(mat2);
	mat.print_nonzero_matrix();
}



int main(){

    //test1();
   test_sparse();
   cout<<"NO RTE\n";

   cout<<"You are great";

}
