#ifndef CALCULATE_H
#define CALCULATE_H

#include"StringHandler.h"
#include<string>
#include<stack>
#include<queue>

class Calculate
{
public:
	Calculate(std::string a,std::queue<double> q)
	{
		operator_stack.push('\0');
		while(q.size()>0)
		{
			que.push(q.front());
			q.pop();
		}
		for(auto item:a)
			ini_expression.push_back(item);
		reverse_polish();
	}

	~Calculate()
	{

	}
	

	double getResult() const;
private:
	void reverse_polish();
	int getPrecedence(char ch, bool inSstack) const;
	std::string ini_expression;
	std::string reverse_polish_expression;
	double result;
	std::stack<char> operator_stack;
	std::stack<double> data_stack;
	std::queue<double> que;
};

#endif

