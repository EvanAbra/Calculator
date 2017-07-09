#pragma GCC diagnostic error "-std=c++11" 
#include<iostream>
#include"Calculate.h"

using namespace std;

int main()
{
	cout<<"A program for calculating. It can calculate the result of the + - * / ^ % with decimal arithmetic. It can also support the (), but make sure the bracket is in English."<<endl;
	cout<<"Now please enter the expression"<<endl;
	string a;
	while(cin>>a)
	{
		StringHandler sh(a);
		Calculate s(sh.getTheHandledString(),sh.getTheQ());
		cout<<"The result is"<<s.getResult()<<endl;


	}
	return 0;
}
