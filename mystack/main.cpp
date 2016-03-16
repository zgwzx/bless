#include <iostream>
#include<fstream>
#include<ctime>
#include<cstdlib>
#include "mystack.h"

using namespace std;

int main()
{
    srand(time(0));
    /*fstream inout("date1.txt",ios::out);
    int i;
    for(i=1;i<=20;i++)
    {
        inout<<rand()%100<<" ";
    }
    inout.close();
    fstream pout("date2.txt",ios::out);
    int j;
    for(j=1;j<=20;j++)
    {
        inout<<rand()%100<<" ";
    }
    pout.close();*/





    mystack<int> s1,s2,s3,s4,s5,s6;
    int num1[20],num2[20];
    int k;
    for(k=0;k<20;k++)
    {
        num1[k]=rand()%100;
        num2[k]=rand()%100;
    }

    for(k=0;k<20;k++)
    {
        s1.push(num1[k]);
        s2.push(num2[k]);
    }
    int y,x;
    s4=s1;
    s5=s2;
    cout<<"list1:"<<endl;
    while(!s1.empty())
    {
        s1.get_top(x);
        cout<<x<<" ";
        s1.pop();
    }
    cout<<endl;


    cout<<"list2:"<<endl;
    while(!s2.empty())
    {
        s2.get_top(y);
        cout<<y<<" ";
        s2.pop();
    }
    cout<<endl;


    cout<<"gather_list:"<<endl;

    while(s5.empty() !=true)
    {
        s5.get_top(y);
        s4.push(y);
        s5.pop();
    }
    s6=s4;
    while(s4.empty()!=true)
    {
        s4.get_top(y);
        cout<<y<<" ";
        s4.pop();
    }
    cout<<endl;
    cout<<"paixuhou1"<<endl;
   while(s6.empty()!=true)
   {
       s6.get_top(x);
       s6.pop();
       s3.get_top(y);
       while(s3.empty ()!=true && (y<x))
       {
           s3.get_top(y);
           s6.push(y);
           s3.pop();
       }
       s3.push(x);
   }

   while(s3.empty()!=true)
   {
       s3.get_top(x);
       s3.pop();
       cout<<x<<" ";
   }

    /*
    while(s2.empty()!=true)
    {
        s2.get_top(x);
        cout<<x<<" ";
        s2.pop();
    }*/




}
