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
	std::string		expr;
	std::stack<int>	stack;
	int				a, b;
	size_t			pos, start;

	if (argc != 2)
		std::cerr << "Error: Invalid arguments" << std::endl;
	else
	{
		pos = -1;
		start = 0;
		expr = argv[1];
		while ((pos = expr.find(' ', pos + 1)))
		{
			if (expr.substr(start, pos - start) == "+")
			{
				a = stack.top();
				stack.pop();
				b = stack.top();
				stack.pop();
				stack.push(b + a);
				std::cout << b << " + " << a << " = " << b + a << std::endl;
			}
			else if (expr.substr(start, pos - start) == "-")
			{
				a = stack.top();
				stack.pop();
				b = stack.top();
				stack.pop();
				stack.push(b - a);
				std::cout << b << " - " << a << " = " << b - a << std::endl;
			}
			else if (expr.substr(start, pos - start) == "*")
			{
				a = stack.top();
				stack.pop();
				b = stack.top();
				stack.pop();
				stack.push(b * a);
				std::cout << b << " * " << a << " = " << b * a << std::endl;
			}
			else if (expr.substr(start, pos - start) == "/")
			{
				a = stack.top();
				stack.pop();
				b = stack.top();
				stack.pop();
				stack.push(b / a);
				std::cout << b << " / " << a << " = " << b / a << std::endl;
			}
			else
			{
				stack.push(atoi(expr.substr(start, pos - start).c_str()));
				std::cout << "[" << atoi(expr.substr(start, pos - start).c_str()) << "]" << std::endl;
			}
			start = pos + 1;
			if (pos == std::string::npos)
				break;
		}
	}

	std::cout << "Stack size: " << stack.size() << "  |  result: " << stack.top() << std::endl;

	return (0);
}
