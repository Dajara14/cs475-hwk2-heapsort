#include <stdio.h>
#include "employee.h"
#include "heap.h"

int main(int argc, char *argv[])
{
	//TODO
	//initialize our array
	Employee employees[MAX_EMPLOYEES]; 
	for(int i=0;i<MAX_EMPLOYEES;i++){
		//get user input for both employee name and salary
		Employee newEmployee;
		printf("Please enter an employee name\n");
		char *input;
		input = fgets(newEmployee.name, MAX_NAME_LEN, stdin);
		  while ( getchar() != '\n' );
		printf("Please enter a salary integer\n");
		int salary;
		scanf("%d",&salary);
		  while ( getchar() != '\n' );
		newEmployee.salary = salary;
		//add it to the employee array
		employees[i] = newEmployee;
	}
	//sort it and print it
	heapSort(employees,MAX_EMPLOYEES);
	printList(employees,MAX_EMPLOYEES);
	return 0;
}
