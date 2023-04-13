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
	(void)obj;
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

bool	RPN::_is_operation(std::string chr)
{
	return (chr.size() == 1 && (chr[0] == '+' || chr[0] == '-' || chr[0] == '*' || chr[0] == '/'));
}

void	RPN::eval(std::string expr)
{
	int		a, b;
	size_t	pos = 0, start = 0;

	_trim_str(expr);

	while ((pos = expr.find(' ', start)) && start != expr.size())
	{
		if (!_is_operation(expr.substr(start, pos - start)))
		{
			if (!_is_str_digit(expr.substr(start, pos - start)))
				throw std::invalid_argument("Error: non-numeric arguments");
			_stack.push(atoi(expr.substr(start, pos - start).c_str()));
		}
		else
		{
			if (_stack.size() != 2)
				throw std::invalid_argument("Error: too many operands");
			a = _stack.top();
			_stack.pop();
			b = _stack.top();
			_stack.pop();
			_do_operation(_stack, a, b, expr.substr(start, pos - start)[0]);
		}
		start = pos + 1;
		while (expr[start] == ' ')
			start++;
		if (pos == std::string::npos)
			break;
	}
}

void	RPN::display_result()
{
	if (_stack.size() != 1)
		throw std::invalid_argument("Error: too many operands");
	std::cout << _stack.top() << std::endl;
}
