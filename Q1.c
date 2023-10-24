#include <stdio.h>
// Write a C program that accepts an employee's ID, total worked hours in a month and
// the amount received per hour. Print the ID and salary (with two decimal places) of the
// employee for a particular month.
int main(){
  int employeeID;
  float hours_worked, hourly_pay, salary;
  
  printf("Enter employee's ID:");
  scanf("%d", &employeeID);
  
  printf("Enter hours worked:");
  scanf("%f", &hours_worked);
  
  printf("Enter hourly pay:");
  scanf("%f", &hourly_pay);
  
  salary = hourly_pay * hours_worked;
  
  printf("Employee's ID:%d", employeeID);
  printf("Your salary is:%.2fRupees", salary);
  
  return 0;
  
  
  
  
}