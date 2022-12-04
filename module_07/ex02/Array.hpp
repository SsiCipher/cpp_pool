#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
	private:
		T							*_arr;
		unsigned int	_arr_size;

	public:
		Array(void)
		{
			_arr = NULL;
			_arr_size = 0;
		}

		Array(unsigned int n)
		{
			_arr = new T[n];
			_arr_size = n;
		}

		~Array(void)
		{
			if (_arr)
				delete[] _arr;
		}

		Array(const Array &obj)
		{
			if (!obj._arr)
			{
				this->_arr = NULL;
				this->_arr_size = 0;
			}
			else
			{
				this->_arr = new T[obj._arr_size];
				this->_arr_size = obj._arr_size;
				for (unsigned int i = 0; i < obj._arr_size; i++)
					this->_arr[i] = obj._arr[i];
			}
		}

		Array &operator=(const Array &obj)
		{
			if (this->_arr)
				delete[] this->_arr;
			if (!obj._arr)
			{
				obj._arr = NULL;
				obj._arr_size = 0;
			}
			else
			{
				this->_arr = new T[obj._arr_size];
				this->_arr_size = obj._arr_size;
				for (unsigned int i = 0; i < obj._arr_size; i++)
					this->_arr[i] = obj._arr[i];
			}
			return (*this);
		}

		T&	operator[](int i) const
		{
			if (i < 0 || (unsigned int)i >= this->_arr_size)
				throw outOfBoundException();
			return (this->_arr[i]);
		}

		unsigned int size(void) const
		{
			return (_arr_size);
		}

		class outOfBoundException: public std::exception
		{
			const char *what() const throw()
			{
				return ("The given index is out of bound");
			}
		};
};

#endif
