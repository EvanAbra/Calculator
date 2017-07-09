#include"Calculate.h"
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<stack>

using namespace std;

double Calculate::getResult() const
{
	return result;
}

int Calculate::getPrecedence(char ch, bool inStack) const
{
	int precedence=0;
	switch(ch)
	{
	case '-':
	case '+':
		inStack?precedence=3:precedence=2;
		break;
	case '*':
	case '/':
	case '%':
		inStack?precedence=5:precedence=4;
		break;
	case '^':
		inStack?precedence=7:precedence=6;
	case ')':
	case '）':
		inStack?precedence=8:precedence=1;
	case '(':
	case '（':
		inStack?precedence=1:precedence=8;
		break;
	case '#':
		precedence=0;
	case '\0':
	default:
		precedence=-1;
		break;
	}
	return precedence;
}

void Calculate::reverse_polish()
{
	for(auto item:ini_expression)
	{
		if(item=='#')
			reverse_polish_expression.push_back(item);
		else		switch(item)
			{
			case '+':
			case '-':
			case '*':
			case '/':
			case '^':
			case '%':
				if(operator_stack.size()==0)
					operator_stack.push(item);
				else if(getPrecedence(item,false)>getPrecedence(operator_stack.top(),true))
					operator_stack.push(item);
				else
				{
					while(getPrecedence(item,false)<getPrecedence(operator_stack.top(),true))
					{
						reverse_polish_expression.push_back(operator_stack.top());
						operator_stack.pop();
					}	
					operator_stack.push(item);
				}
				break;
			case '(':
				operator_stack.push(item);
			break;
			case ')':
				if(operator_stack.size()==0)
					operator_stack.push(item);
				else{
					while((operator_stack.top()!='(')&&(operator_stack.size()>0))
					{
						reverse_polish_expression.push_back(operator_stack.top());
						operator_stack.pop();
					}
				operator_stack.pop();
				}
				break;
		}
	}
	while(operator_stack.size()>0)
	{
		reverse_polish_expression.push_back(operator_stack.top());
		operator_stack.pop();
	}
	//calculate the reverse polish expression
	for(auto item:reverse_polish_expression)
	{
		double temp=0;
		int temp_result=0;//used to handle the operation in %
		if(item=='#')
		{
			data_stack.push(que.front());
			que.pop();
		}
		else switch(item)
		{
			case '+':
				temp=data_stack.top();
				data_stack.pop();
				data_stack.top()+=temp;
			break;
		case'-':
			temp=data_stack.top();
			data_stack.pop();
			data_stack.top()-=temp;
			break;
		case'*':
			temp=data_stack.top();
			data_stack.pop();
			data_stack.top()*=temp;
			break;
		case '%':
			temp=data_stack.top();
			data_stack.pop();
			temp_result=(int)((static_cast<int>(data_stack.top()))/temp);
			data_stack.top()-=temp_result*temp;
			break;
		case '^':
			temp=data_stack.top();
			data_stack.pop();
			data_stack.top()=pow(data_stack.top(),temp);
			break;
		case '/':
			if(data_stack.top()!=0)
			{
				temp=data_stack.top();
				data_stack.pop();
				data_stack.top()/=temp;
				break;
			}
			else
			{
				cout<<"The divisor can't be zero, we replace it with '1'"<<endl;
				data_stack.pop();
				break;
			}
		}
	}
	result=data_stack.top();
}


