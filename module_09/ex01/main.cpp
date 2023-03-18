#include "RPN.hpp"

typedef std::vector<std::string> vertor_s;

vertor_s split_arg(std::string &str)
{
	vertor_s split_str;
	size_t		pos;

	while ((pos = str.find(' ')) != std::string::npos)
	{
		
	}

	return (split_str);
}

int	main(int argc, char const *argv[])
{
	size_t			start = 0;
	std::string		expr;
	std::stack<int>	stack;

	if (argc != 2)
		std::cerr << "Error: Invalid arguments" << std::endl;
	else
	{
		expr = argv[1];
		for (int i = 0; expr[i]; i++)
		{
			for (; expr[i] == ' '; i++);
			if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/')
			{
				std::cout << "==========" << std::endl;
				std::cout << stack.top() << std::endl;
				stack.pop();
				std::cout << stack.top() << std::endl;
				stack.pop();
				std::cout << "==========" << std::endl;
			}
			else if (expr[i] == ' ')
			{
				stack.push(atoi(expr.substr(start, i).c_str()));
				for (; expr[i] == ' '; i++);
				start = i + 1;
			}
		}
	}
	return (0);
}
