#include <stdio.h>
#include "employee.h"
#include "heap.h"

int main(int argc, char *argv[])
{
	//TODO
	Employee employees[MAX_EMPLOYEES]; 
	for(int i=0;i<MAX_EMPLOYEES;i++){
		Employee newEmployee;
		printf("Please enter an employee name");
		char *input;
		input = fgets(newEmployee.name, MAX_NAME_LEN, stdin);
		  while ( getchar() != '\n' );
		printf("Please enter a salary integer");
		int salary;
		scanf("%d",&salary);
		  while ( getchar() != '\n' );
		newEmployee.salary = salary;
		employees[i] = newEmployee;
	}
	heapSort(employees,MAX_EMPLOYEES);
	printList(employees,MAX_EMPLOYEES);
	return 0;
}
