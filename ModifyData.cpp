#include "ModifyData.h"
#include<iostream>
#include<fstream>
#include<string>
#include <cstdio>
#include <regex>
#include <cstring>
ModifyData::ModifyData(){
}
using namespace std;
string inputstr1(){
string str;
regex regex_int("^.{1,50}$");
do{
    cout<<"Input length must be between 1 to 50 only: ";
    getline(cin,str);
}
while(!regex_match(str,regex_int));
return str;
}


void delete_line(const string& idNr,int PId,int EId,char Description[50],char date[80],int duration,char Depat[50],char Group[50]) {
ifstream list;
ofstream outFile("temp.txt");
string readFile, id;
char choice;string cDepat, cGroup,cDescription;
list.open("projects.txt", ios::app);
if (list.is_open()) {
    while (getline(list, readFile)) {
        int pos = readFile.find(',');
        id = readFile.substr(0, pos);
        if (idNr != id) {
            outFile << readFile;
            outFile<<"\n";
        }
        else{
                 cout<<"1. FOR DEPARTMENT \n2. FOR GROUP \n3. FOR DESCRIPTION \n4. FOR EXIT"<<endl;
        cout<<"ENTER YOUR CHOICE"<<endl;
cin>>choice;
switch(choice){
case '1':
    cout<<"ENTER UPDATED DATA \n";
    cDepat=inputstr1();

             outFile<<PId<<","<<EId<<","<<Description<<","<<date<<","<<duration<<","<<cDepat<<","<<Group<<endl;
             cout<<"DATA UPDATED\n";
    break;
    case '2':
    cout<<"ENTER UPDATED DATA \n";
    cGroup=inputstr1();

             outFile<<PId<<","<<EId<<","<<Description<<","<<date<<","<<duration<<","<<Depat<<","<<cGroup<<endl;
             cout<<"DATA UPDATED\n";
    break;
    case '3':
    cout<<"ENTER UPDATED DATA \n";
    cDescription=inputstr1();

             outFile<<PId<<","<<EId<<","<<cDescription<<","<<date<<","<<duration<<","<<Depat<<","<<Group<<endl;
             cout<<"DATA UPDATED\n";
    break;
    case '4':
    cout<<"Exit \n";
    outFile<<PId<<","<<EId<<","<<Description<<","<<date<<","<<duration<<","<<Depat<<","<<Group<<endl;
    break;
    default:
        cout<<"invalid input \n";
}

            // outFile<<PId<<","<<EId<<","<<cDescription<<","<<date<<","<<duration<<","<<Depat<<","<<Group<<endl;
        }
    }
}
list.close();
outFile.close();
remove("projects.txt");
rename("temp.txt","projects.txt");
}
void ModifyData::CheckPId(int loginid){
 int PId;//Project ID number(4) auto increment
int EId;//Created By number(4) = Employee ID of login Employee
char Description[50];//Project Description string(50)
char date[80];//Create Date date (DD/MM/YYYY format) = today’s date
int duration;//Project Duration int(2) = number of months
char Depat[50];//Department string(50)
char Group[50];
int id;
cout<<"ENTER PROJECT ID : \n";
cin>>id;
ifstream read;
read.open("projects.txt");
string ch;
bool flag=0;
while(!read.eof())
{
 getline(read,ch);
while(sscanf(ch.c_str(), "%d,%d,%100[^,],%100[^,],%d,%100[^,],%100[^,],%*[\n]",&PId,&EId,Description,date,&duration,Depat,Group)==7)
    {
       getline(read,ch);
        if (PId == id && loginid==EId) {
                       cout<<id<<"Id "<<endl;
                       flag=1;
                       read.close();
              delete_line(to_string(id),PId,EId,Description,date,duration,Depat,Group);
       break;
}

}
}
read.close();

if(flag==1){

   // cout<<"Updated"<<endl;
}
else{
    cout<<"SORRY YOU CAN NOT MODIFY DATA PROJECT IS NOT CREATED BY YOU !! or PROJECT ID DOES NOT EXISTS"<<endl;
}
//return 0;
}
