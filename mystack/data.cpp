#include<iostream>
#include<ctime>
#include<fstream>
#include<cstdlib>

using namespace std;

int main()
{
    srand(time(0));
    fstream inout("date1.txt",ios::out);
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
    pout.close();

}
