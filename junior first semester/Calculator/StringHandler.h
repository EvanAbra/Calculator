#ifndef STRINGHANDLER
#define STRINGHANDLER

#include<queue>
#include<string>

class StringHandler
{
public:
	StringHandler(std::string a)
	{
		for(auto item:a)
		{
			raw_string.push_back(item);
		}
		init();
	}

	StringHandler()
	{

	}

	void initialize(std::string a)
	{
		for(auto item:a)
		{
			raw_string.push_back(item);
		}
		init();
	}

	~StringHandler()
	{
		raw_string.clear();
		handled_string.clear();
	}
	
	double getTheNumber();
	std::queue<double> getTheQ() const;
	std::string getTheHandledString() const;
private:
	void init();
	std::queue<double> q;
	std::string raw_string;
	std::string handled_string;
};
#endif
