#include "RPN.hpp"

typedef	std::stack<int>	t_stack;

bool	is_operation(char chr)
{
	return (chr == '+' || chr == '-' || chr == '*' || chr == '/');
}

void	do_operation(t_stack &stack, int a, int b, char op)
{
	switch (op)
	{
		case '+':
			stack.push(a + b);
			break;
		case '-':
			stack.push(a - b);
			break;
		case '*':
			stack.push(a * b);
			break;
		case '/':
			stack.push(a / b);
			break;
		default:
			break;
	}
	std::cout << b << " " << op << " " << a << " = " << b + a << std::endl;
}


bool is_str_digit(std::string str)
{
	for (size_t i = 0; i < str.size(); i++)
		if (!isdigit(str[i]))
			return (false);
	return (true);
}

int	main(int argc, char const *argv[])
{
	t_stack		stack;
	std::string	expr;
	int			a, b;
	size_t		pos, start;

	if (argc != 2)
		std::cerr << "Error: Invalid arguments" << std::endl;
	else
	{
		pos = 0;
		start = 0;
		expr = argv[1];
		while ((pos = expr.find(' ', start)) && start != expr.size())
		{
			if (!is_operation(expr.substr(start, pos - start)[0]))
			{
				if (!is_str_digit(expr.substr(start, pos - start)))
				{
					std::cerr << "Error: non-numeric arguments" << std::endl;
					return (1);
				}
				stack.push(atoi(expr.substr(start, pos - start).c_str()));
				std::cout << "[" << atoi(expr.substr(start, pos - start).c_str()) << "]" << std::endl;
			}
			else
			{
				if (stack.size() != 2)
				{
					std::cerr << "Error" << std::endl;
					return (1);
				}
				a = stack.top();
				stack.pop();
				b = stack.top();
				stack.pop();
				do_operation(stack, a, b, expr.substr(start, pos - start)[0]);
			}
			start = pos + 1;
			while (expr[start] == ' ')
				start++;
			if (pos == std::string::npos)
				break;
		}
	}

	std::cout << "Stack size: " << stack.size() << "  |  result: " << stack.top() << std::endl;

	return (0);
}
