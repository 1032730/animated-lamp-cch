#include<iostream>
#define max 999
using namespace std;
struct addressbooks;
void showpersons(addressbooks *abc);
int deleteperson(addressbooks *abc,string name);
void Isexist(addressbooks *abc,string name);
void findperson(addressbooks *abc);
void modifyperson(addressbooks *abc);
void cleanaddressbooks(addressbooks *abc);
//选项显示函数
void showmenu()
{
cout << "*****--------------------*****" << endl;
cout << "*****-----添加联系人-----*****" << endl;
cout << "*****-----显示联系人-----*****" << endl;
cout << "*****-----删除联系人-----*****" << endl;
cout << "*****-----查找联系人-----*****" << endl;
cout << "*****-----修改联系人-----*****" << endl;
cout << "*****-----清空联系人-----*****" << endl;
cout << "*****-----退出通讯录-----*****" << endl;
cout << "*****--------------------*****" << endl;}
//联系人信息结构体
struct persons
{
//名字
string Aname;
//性别
 string Asex;
//年龄
 int Aage;
//电话
 string Aphone;
//住址
string Aaddress;
 

};
//通讯录数组
struct addressbooks
{
//联系人信息结构体数组
struct persons personsarray[max];
//联系人数量
int size;
};
//创建添加联系人函数
void addpersons(addressbooks * abc)
{

if (abc->size==max)
{
 cout << "通讯录已满" << endl;
}
else
{  
   string name;
   cout << "请输入联系人姓名" << endl;
   cin >> name;
   abc->personsarray[abc->size].Aname=name;

sexpart:
cout << "请输入"<<abc->personsarray[abc->size].Aname<<"的性别(男、女或人妖)" << endl;
string sex;
cin >>sex;
if(sex=="男"||sex=="女"||sex=="人妖")
{
abc->personsarray[abc->size].Asex=sex;
}
else
{
cout << "输入错误，请重试" << endl;
goto sexpart;
}
agepart:
int age=0;
cout << "请输入"<<abc->personsarray[abc->size].Aname<<"的年龄(1~100岁)" << endl;
cin >>age;
if(age>0&&age<=100)
{
abc->personsarray[abc->size].Aage=age;
}
else
{
cout << "您输入的年龄超出范围，请重试" << endl;
goto agepart;
}
cout << "请输入"<<abc->personsarray[abc->size].Aname<<"的电话" << endl;
string phone;
cin >> phone;
abc->personsarray[abc->size].Aphone=phone;

cout << "请输入"<<abc->personsarray[abc->size].Aname<<"的地址" << endl;
string address;
cin >>address;
abc->personsarray[abc->size].Aaddress=address;

cout <<abc->personsarray[abc->size].Aname<<"已添加成功" << endl;
abc->size++;

}
}


int main()
{ 
//显示选项
  showmenu();
//通讯录变量初始化
struct addressbooks abc;
   abc.size=0;

   
    


  for(int k=0;k<max;k++)
  {
   
   person:
    cout << "请选择选项:\n";
    cout << "A.添加联系人  ";
    cout << "B.显示联系人  ";
    cout << "C.删除联系人  ";
    cout << "D.查找联系人  ";
    cout << "E.修改联系人  ";
    cout << "F.清空联系人  ";
    cout << "G.退出通讯录"<<endl;
    
    
    string inputs;
    cin >> inputs;
   if(inputs=="A")
    {
    addpersons(&abc);
    goto person;
    }
    else if(inputs=="B")
    {
    showpersons(&abc);
    goto person;
    }
    else if(inputs=="C")
    {
    cout << "输入要删除的联系人" << endl;
    string name;
    cin >> name;
    deleteperson(&abc,name);
    Isexist(&abc,name);    
    goto person;
    }
    
    else if(inputs=="D")
    {

    findperson(&abc);
    goto person;
    
    }
    else if(inputs=="E")
    {
    modifyperson(&abc);
    goto person;
    }
    else if(inputs=="F")
   {
    cleanaddressbooks(&abc);
    goto person;
   
    }
    else if(inputs=="G")
    {
    goto inputsout;
    }
    else 
    {
    cout << "超出选项范围，请重试" << endl;
    goto person;
    }
    
   }
inputsout:
int a;
 }

void showpersons(addressbooks *abc)
{
    if(abc->size==0)
    {
    cout << "联系人为空" << endl;
    
    }
    else
    {
    for(int j=0;j<abc->size;j++)
    {
    cout << "\n姓名:" <<abc->personsarray[abc->size-1].Aname<<endl;
    cout << "性别:" <<abc->personsarray[abc->size-1].Asex<<endl;
    cout << "年龄:" <<abc->personsarray[abc->size-1].Aage<<endl;
    cout << "电话:" <<abc->personsarray[abc->size-1].Aphone<<endl;
    cout << "住址:" <<abc->personsarray[abc->size-1].Aaddress<<"\n"<<endl;
    }
     }
    
}

int deleteperson(addressbooks *abc,string name)
{
   for(int l=0;l<abc->size;l++)
   {
    if(abc->personsarray[l].Aname==name)
    {
     return l;
    }
   }
     return -1;

}

void Isexist(addressbooks *abc,string name)
{
int result= deleteperson(abc,name);
  if(result==-1)
  {
   cout << "查无此人,无法删除一个不存在的联系人\n" << endl;
  }
  else
  {
   for(int m=result;m<abc->size;m++)
   {
    abc->personsarray[m]=abc->personsarray[m+1];
   }
   abc->size--;
   cout << "删除成功" << endl;
  }
 
}
void findperson(addressbooks *abc)
{
cout << "请输入您要查找的联系人" << endl;
string name;
cin >> name;
int temp=deleteperson(abc,name);
if(temp!=-1)
{
cout << "姓名:" <<abc->personsarray[temp].Aname<< endl;
cout << "年龄:" <<abc->personsarray[temp].Aage<< endl;
cout << "性别:" <<abc->personsarray[temp].Asex <<endl;
cout << "电话:" <<abc->personsarray[temp].Aphone <<endl;
cout << "地址:" <<abc->personsarray[temp].Aaddress<< endl;
}
else
{;
cout << "查无此人\n" << endl;

}
}

void modifyperson(addressbooks *abc)
{
cout << "请输入要修改的联系人" << endl;
string name;
cin >> name;
int ret=deleteperson(abc,name);
if(ret!=-1)
{
cout << "请输入新姓名" << endl;
cin >> name;
abc->personsarray[ret].Aname=name;

cout << "原年龄:" <<abc->personsarray[ret].Aage<<endl;
tage:
cout << "请输入新年龄" << endl;
int age;
cin >>age ;
if(age<1||age>100)
{
cout << "您输入的不符合规范，请重试" << endl;
goto tage;
}
ageback:
cout << "您确定要更改吗？(yes或no)" << endl;
string judge;
cin >> judge;

if(judge=="yes")
{
abc->personsarray[ret].Aage=age;
}
else if(judge=="no")
{
cout << "您取消了对年龄的修改" << endl;
goto ageout;
}
else
{
cout << "输入不规范，请重新输入" << endl;
goto ageback;
}

ageout:
cout << "原性别:" <<abc->personsarray[ret].Asex<<endl;
sexof:
cout << "请输入新性别(男、女或人妖):" << endl;
string sex;
cin >> sex;
if(sex!="男"||sex!="女"||sex!="人妖")
{
cout<<"输入的不规范，请重新输入"<<endl;
goto sexof;
}
sexback:
cout << "您确定要修改吗？(yes或no)" << endl;
cin >> judge;
if(judge=="yes")
{
abc->personsarray[ret].Asex=sex;
}
else if(judge=="no")
{
cout << "您取消了对性别的修改" << endl;
goto sexout;
}
else
{
cout << "您输入的不符合要求，请重试" << endl;
goto sexback;
}
sexout:
cout << "原电话:" <<abc->personsarray[ret].Aphone<< endl;
cout << "请输入新电话(因系统缺陷，输入数字以外的字可能会报错)" << endl;
string phone;
cin >> phone;
phoneback:
cout << "您确定要修改吗？(yes或no)" << endl;
cin >> judge;
if(judge=="yes")
{
abc->personsarray[ret].Aphone=phone;
}
else if(judge=="no")
{
cout << "您已取消了对电话的修改" << endl;
goto phoneout;
}
else
{
cout << "输入不规范，请重试" << endl;
goto phoneback;
}
phoneout:
cout << "原地址:" <<abc->personsarray[ret].Aaddress<<endl;
cout << "请输入新地址" << endl;
string address;
cin >> address;
addressback:
cout << "您确定要修改吗？" << endl;
cin >> judge;
if(judge=="yes")
{
abc->personsarray[ret].Aaddress=address;
}
else if(judge=="no")
{
cout << "您取消了对地址的修改" << endl;
goto addressout;
}
else
{
cout << "您输入的不符合要求，请重试" << endl;
goto addressback;
}
addressout:
cout << "修改成功\n\n" << endl;
}
else
{
cout << "查无此人,您不可能修改一个不存在的联系人\n" << endl;
}
}
void cleanaddressbooks(addressbooks *abc)
{
cleanerback:
cout << "您确定要清空通讯录吗？yes或no(过后将无法找回)" << endl;
string judge;
cin >> judge;
if(judge=="yes")
{
abc->size=0;
cout << "通讯录已清空" << endl;
}
else if(judge=="no")
{
cout << "您已取消清空通讯录" << endl;
goto cleanerout;
}else
{
cout << "您输入的不符合要求,请重试" << endl;
goto cleanerback;
}
cleanerout:
int a;
}


    