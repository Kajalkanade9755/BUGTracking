#include "Login.h"
#include<iostream>
#include<fstream>
#include<string>
#include <cstdio>
#include <cstdio>
#include <cstring>
using namespace std;
Login::Login()
{
}
int Login::Lid()
{
int EmployeeID;// number(4)
  char password[10];//Employee Password string(10)
char Name[50];//Employee Name string(50)
  char Dep[10];//Department string(10)
long Mobile;//Mobile Number number(10)
char email[30];//email string(30)
char Skype[20];//Skype ID string(20)
int loginid;char pass[10];
cout<<"enter login id: \n";
cin>>loginid;
cout<<"enter password: \n";
cin>>pass;

ifstream read;
read.open("Employees.txt");
string ch;
bool flag=0;
while(!read.eof())
{
 getline(read,ch);
while(sscanf(ch.c_str(),"%d,%100[^,],%100[^,],%100[^,],%ld,%100[^,],%100[^,],%*[\n]",
             &EmployeeID,password,Name,Dep,&Mobile,email,Skype)==7)
    {
       getline(read,ch);
        if (EmployeeID == loginid && (strcmp(password,pass)==0)) {
                       cout<<loginid<<"Id "<<endl;
                      // return loginid;
                      flag=1;
                       read.close();
              //delete_line(to_string(id));
       break;
}

}
}
read.close();

if(flag==1){
return loginid;
}else{
cout<<"Invalid Employee ID or password"<<endl;
return 0;
}
//return loginid;
}
