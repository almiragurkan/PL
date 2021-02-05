#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdio.h>
typedef struct {
    int empId;
    char name[20];
    char empDep[20];
    int birthYear;
    int salary;
}emp;
void menu();
void convertTextFile(FILE *fPtr);
void addRecord(FILE *fPtr);
void deleteRecord(FILE *fPtr);
void updateRecord(FILE *fPtr);
void showRecords(FILE *fPtr);

int main(){
    while(1){
        menu();
    }
}

void menu(){
    FILE *fp= fopen("employee.bin","rb+");
    printf("\nEMPLOYEE RECORD SYSTEM\n");
    printf("\n1- Add new record \n2- Update record\n3- Delete record\n4- Print all records\n5- Save as txt file\n6- End program");
    printf("\nENTER A CHOICE =>\n");
    int choice;
    scanf("%d", &choice);
    printf("\n");
    switch(choice){
        case 1:
            addRecord(fp);
            break;
        case 2:
            updateRecord(fp);
            break;

        case 3:
            deleteRecord(fp);
            break;
        case 4:
            showRecords(fp);
            break;
        case 5:
          convertTextFile(fp);
          break;
        case 6:
          exit(0);
    }
    fclose(fp);
    printf("\n\n**********************************\n");
}

void showRecords(FILE *fPtr){
  printf("%-8s %-20s %-20s %-15s %-10s\n","ID No","Emplyee","NameDepartment","Birth Year","Salary");
    for(int a=0;a<100;a++){
        emp employee1;
        fread(&employee1,sizeof(emp),1,fPtr);
        if(employee1.empId!=0)
        printf("%-8d %-20s %-20s %-15d %-10d\n", employee1.empId,employee1.name,employee1.empDep,employee1.birthYear,employee1.salary);
    }
}

void addRecord(FILE* fPtr){
  int id;
  printf("Please enter ID: ");
  scanf("%d",&id);

  emp employee;
  fseek(fPtr, sizeof(emp) * (id-1), SEEK_SET);
  fread(&employee.empId, sizeof(id), 1, fPtr);
  if(employee.empId!=0){
    printf("#%d already exist!!", id);
    return;
  }

 
  printf("Enter the name: ");
  scanf("%s", employee.name);
  printf("Enter the department: ");
  scanf("%s", employee.empDep);
  printf("Enter the birth year: ");
  scanf("%d", &employee.birthYear);
  printf("Enter the salary: ");
  scanf("%d", &employee.salary);

  fseek(fPtr, sizeof(emp) * (employee.empId-1), SEEK_SET);
  fwrite(&employee, sizeof(employee), 1, fPtr);
}

void deleteRecord(FILE *fPtr){
    int id;
    printf("Please enter ID: ");
    scanf("%d",&id);

    emp currentEmployee;
    fseek(fPtr, sizeof(emp) * (id-1), SEEK_SET);
    fread(&currentEmployee.empId, sizeof(id), 1, fPtr);
    if(currentEmployee.empId==0){
      printf("#%d doesn't exist!!", id);
      return;
    }

    fseek(fPtr, -sizeof(id), SEEK_CUR);
    memset(&currentEmployee,0, sizeof(currentEmployee));
    fwrite(&currentEmployee, sizeof(currentEmployee), 1, fPtr);
    printf("%d is deleted!", id);
}

void updateRecord(FILE *fPtr){
  int id;
  printf("Please enter ID: ");
  scanf("%d",&id);
  emp employee;
  fseek(fPtr, sizeof(emp) * (id-1), SEEK_SET);
  fread(&employee, sizeof(employee), 1, fPtr);
  if(employee.empId==0){
      printf("#%d doesn't exist!!", id);
      return;
  }
  printf("%-8s %-20s %-20s %-15s %-10s\n","ID No","Emplyee","NameDepartment","Birth Year","Salary");
  printf("%-8d %-20s %-20s %-15d %-10d\n\n", employee.empId,employee.name,employee.empDep,employee.birthYear,employee.salary);
  printf("Enter the salary percentage: ");
  int salaryPerc;
  scanf("%d",&salaryPerc);
  employee.salary+=(employee.salary*salaryPerc*0.01);
  printf("%-8s %-20s %-20s %-15s %-10s\n","ID No","Emplyee","NameDepartment","Birth Year","Salary");
  printf("%-8d %-20s %-20s %-15d %-10d\n", employee.empId,employee.name,employee.empDep,employee.birthYear,employee.salary);
  fseek(fPtr,-sizeof(employee.salary), SEEK_CUR);
  fwrite(&employee.salary,sizeof(employee.salary),1,fPtr);
}


void convertTextFile(FILE* fPtr){
  FILE* textFile=fopen("employee.txt", "w");
   fprintf(textFile, "%-8s %-20s %-20s %-15s %-10s\n","ID No","Emplyee","NameDepartment","Birth Year","Salary");
    for(int a=0;a<100;a++){
        emp employee1;
        fread(&employee1,sizeof(emp),1,fPtr);
        if(employee1.empId!=0)
        fprintf(textFile,"%-8d %-20s %-20s %-15d %-10d\n", employee1.empId,employee1.name,employee1.empDep,employee1.birthYear,employee1.salary);
    }
    fclose(textFile);
    printf("employee.txt file is ready!\n");
}