#ifndef LOGIN_H
#define LOGIN_H


class Login
{
    public:
    Login();

int EmployeeID;// number(4)
  char password[10];//Employee Password string(10)
char Name[50];//Employee Name string(50)
  char Dep[10];//Department string(10)
long Mobile;//Mobile Number number(10)
char email[30];//email string(30)
char Skype[20];//Skype ID string(20)
int Lid();
};

#endif // LOGIN_H
