#include<iostream>
#include<cstring>
#include<fstream>
#include<stdio.h>
#include<unistd.h>
#include<thread>
#include<chrono>
#include"project.h"
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define BOLD "\033[1m"
using namespace std;




int main()
{
  intro();
   
 do{   
    
  cout<<"\n\n\n\n\n\n\n"<<RESET<<BOLD;
  
  cout<<"\n\n\t\t\tChoose login option\n\n\t\t"<<RESET;
  
  cout<<"\n\n\t\t\t1."<<RESET<<BOLD<<GREEN<<" Admin\n\t\t\t"<<RESET<<"2."<<BOLD<<GREEN<<" Employee\n\t\t\t"<<RESET<<"3."<<BOLD<<GREEN<<" Student"<<RESET<<"\n\t\t\t4."<<BOLD<<GREEN<<" Exit\n\t\t\t";
   
  int choice;
  cin>>choice;
  
  switch(choice)
  {
     case 1:
     
     intro_admin();
     admin_login();
     clrscr();
     
     break;
     
     case 2:
     
     cout<<"\n\t\tEmployee";
     employee_login();
     break;
     
     case 3:
     
     cout<<"\n\t\tStudent";
     student_login();
     break;
     
     case 4:
 
     exit(0);
     
     
     default:
     
     cout<<RESET<<RED<<BOLD<<"\n\n\tInvalid choice! Select again."<<flush;
   //  usleep(300000);
     clrscr();
     intro_home();
  }    
   
  
  
 }while(1); 
  
 cout<<"\n\n\n\n\n\n\n";
 
  
  return 0;
  
}  


