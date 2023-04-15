#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN
{
	private:
		typedef	std::stack<int>	t_stack;

		t_stack _stack;

		void	_trim_str(std::string &str);
		bool	_is_str_digit(std::string str);
		void	_do_operation(t_stack &stack, int a, int b, char op);
		bool	_is_operation(char op_char);

	public:
		RPN(void);
		~RPN(void);
		RPN(const RPN &obj);
		RPN &operator=(const RPN &obj);

		void	eval(std::string expr);
		void	display_result();
};

#endif
