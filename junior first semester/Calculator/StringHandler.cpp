#include"StringHandler.h"
#include<string>
#include<queue>
#include<vector>
#include<cmath>

using namespace std;

void StringHandler::init()
{
	bool flag=true;
	auto beg=raw_string.begin(),end=raw_string.end();
	while(beg!=end)
	{
		if(!isdigit(*beg))
		{
			handled_string.push_back(*beg);
			++beg;
		}
		else
		{
			handled_string.push_back('#');
			int digit=0;
			vector<int> num;
			queue<int> num_after_dot;
			double this_num=0;
			while(isdigit(*beg))
			{
				++digit;
				num.push_back((int)(*beg)-(int)'0');
				++beg;
				if(beg==end)
					break;
			}
			if((*beg)=='.')
			{
				++beg;
				while(isdigit(*beg))
				{
					num_after_dot.push((int)(*beg)-(int)'0');
					++beg;
					if(beg==end)
						break;
				}
			}//end if((*beg)=='.')
			
			int max_digit_multiply_ten=pow(10,digit-1);
			while(digit>0)
			{
				this_num+=(max_digit_multiply_ten*num.at(num.size()-digit));
				max_digit_multiply_ten/=10;
				--digit;
			}
			digit=-1;
			while(num_after_dot.size()>0)
			{
				this_num+=(pow(10,digit)*num_after_dot.front() );
				num_after_dot.pop();
				digit--;
			}

			q.push(this_num);
		}//end else
	}
}

std::queue<double> StringHandler::getTheQ() const
{
	return q;
}

double StringHandler::getTheNumber()
{	
	double number=q.front();
	q.pop();
	return number;
}

string StringHandler::getTheHandledString() const
{
	return handled_string;
}
