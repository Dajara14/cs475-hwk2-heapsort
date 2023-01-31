/*
 * heapsort.c
 *
 *  Created on: Jul 1, 2013
 *      Author:
 */
#include <stdio.h>
#include <stdlib.h>
#include "employee.h"
#include "heap.h"

/**
 * Sorts a list of n employees in descending order
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the heap
 */
void heapSort(Employee *A, int n)
{
	// TODO - BuildHeap on the heap

	// TODO - while n > 0:
	// TODO - swap A[n-1] with A[0], since A[0] is the smallest number.
	// TODO - A[n-1] now sorted in place, so decrement n
	// TODO - Heapify the elements from A[0] up to A[n-1] (which leaves the newly sorted element alone)
	buildHeap(A,n);
	printf("HEAP BUILT");
	printList(A,n);
	while(n>0){
		Employee *emp0= &A[0];
		Employee * empn= &A[n];
		swap(emp0,empn);
		n--;
		for(int i =0;i<n-1;i++){
			heapify(A,i,n);
		}
	}
}

/**
 * Given an array A[], we want to get A[] into min-heap property
 * We only need to run heapify() on internal nodes (there are floor(n/2) of them)
 * and we need to run it bottom up (top-down cannot build a heap)
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the heap
 */
void buildHeap(Employee *A, int n)
{
	printList(A,n);
	// TODO - heapify() every element from A[n/2] down-to A[0]
	for(int i = n/2; i>=0;i--){
		heapify(A,i,n);
	}
}

/**
 * We want to start with A[i] and percolate it downward
 * if it is greater than either left or right child.
 *
 * @param	*A	Pointer to the list of employees
 * @param	i	Index of current element to heapify
 * @param	n	Size of the heap
 */
void heapify(Employee *A, int i, int n)
{
	// TODO - get index of left child of element i
	// TODO - get index of right child of element i

	// TODO - determine which child has a smaller salary. We'll call the index of this
	//		element: "smaller"

	// TODO - recursively check if the salary at A[i] > the salary at A[smaller]. If it is, swap the two.
	//			Then recursively heapify A[smaller].
	// TODO - Continue recursion as long as i is within range AND either right_child and left_child are still within range.
	int left_child= 2*i+1;
	int right_child = 2*i+2;
	int smaller = -1;
	if(left_child<n){
		smaller=left_child;
		int indexSorted;
		if(right_child<n){
			smaller = A[left_child].salary<A[right_child].salary?left_child:right_child;
		}
		indexSorted=A[i].salary>A[smaller].salary?0:1;
	if(indexSorted==0){
		Employee * smallerEmpPtr = &A[smaller];
		Employee * rootEmpPtr = &A[i];
		swap(smallerEmpPtr,rootEmpPtr);
	}
		heapify(A,smaller,n);
	}
	

}

/**
 * Swaps the locations of two Employees
 * @param *e1 An Employee
 * @param *e2 Another Employee to swap with
 */
void swap(Employee *e1, Employee *e2)
{
	// TODO
	Employee temp = *e1;
	*e1=*e2;
	*e2=temp;

}

/**
 * Outputs an array of Employees
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the list
 */
void printList(Employee *A, int n)
{
	// TODO
	for(int i =0;i<n;i++){
		printf("\nName: %s, Salary:%d",A[i].name,A[i].salary);
	}
}
