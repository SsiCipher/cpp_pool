#include "RPN.hpp"

RPN::RPN(void)
{
}

RPN::~RPN()
{
}

RPN::RPN(const RPN &obj)
{
	*this = obj;
}

RPN &RPN::operator=(const RPN &obj)
{
	_stack = obj._stack;
	return (*this);
}

void	RPN::_trim_str(std::string &str)
{
	size_t s, e;

	for (s = 0; str[s] == ' ' || str[s] == '\t'; s++);
	for (e = str.size() - 1; str[e] == ' ' || str[e] == '\t'; e--);
	str.erase(e + 1);
	str.erase(0, s);
}

bool	RPN::_is_str_digit(std::string str)
{
	for (size_t i = 0; i < str.size(); i++)
		if (!isdigit(str[i]))
			return (false);
	return (true);
}

void	RPN::_do_operation(t_stack &stack, int a, int b, char op)
{
	if (op == '/' && b == 0)
		throw std::invalid_argument("\033[1;31mError:\033[0m division by zero is invalid");
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
}

bool	RPN::_is_operation(char op_char)
{
	return (op_char == '+' || op_char == '-' || op_char == '*' || op_char == '/');
}

void	RPN::eval(std::string expr)
{
	int	a, b;

	_trim_str(expr);
	if (expr.empty())
		throw std::invalid_argument("\033[1;31mError:\033[0m empty argument");
	for (size_t i = 0; i < expr.size(); i++)
	{
		if (expr[i] == ' ')
			continue;
		if (_is_operation(expr[i]))
		{
			a = _stack.top();
			_stack.pop();
			b = _stack.top();
			_stack.pop();
			_do_operation(_stack, b, a, expr[i]);
		}
		else
		{
			if (!isdigit(expr[i]))
				throw std::invalid_argument("\033[1;31mError:\033[0m non-numeric arguments");
			_stack.push(expr[i] - '0');
		}
	}
}

void	RPN::display_result()
{
	if (_stack.size() != 1)
		throw std::invalid_argument("\033[1;31mError:\033[0m invalid expression");
	std::cout << "Result: [ " << _stack.top() << " ]" << std::endl;
}
