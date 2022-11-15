#!/usr/bin/bash

CLASS_NAME=${1^}

if [[ -n $CLASS_NAME ]]; then
	touch $(pwd)/$CLASS_NAME.{hpp,cpp}
	echo "Created files $CLASS_NAME.cpp & $CLASS_NAME.hpp"

cat << EOF > $(pwd)/$CLASS_NAME.hpp
#ifndef ${CLASS_NAME^^}_HPP
#define ${CLASS_NAME^^}_HPP

#include <iostream>

class $CLASS_NAME
{
	private:

	public:
		$CLASS_NAME(void);
		~$CLASS_NAME(void);
		$CLASS_NAME(const $CLASS_NAME &obj);
		$CLASS_NAME &operator=(const $CLASS_NAME &obj);
};

#endif
EOF
	echo "Added class definition to $CLASS_NAME.hpp"

cat << EOF > $(pwd)/$CLASS_NAME.cpp
#include "$CLASS_NAME.hpp"

$CLASS_NAME::$CLASS_NAME(void)
{
	std::cout << "[$CLASS_NAME] Constructor has been called!" << std::endl;
}

$CLASS_NAME::~$CLASS_NAME()
{
	std::cout << "[$CLASS_NAME] Destructor has been called!" << std::endl;
}

$CLASS_NAME::$CLASS_NAME(const $CLASS_NAME &obj)
{
	*this = obj;
	std::cout << "[$CLASS_NAME] Copy constructor has been called!" << std::endl;
}

$CLASS_NAME &$CLASS_NAME::operator=(const $CLASS_NAME &obj)
{
	std::cout << "[$CLASS_NAME] Copy assignment operator has been called!" << std::endl;
	if (this != &obj)
	{
	}
	return (*this);
}
EOF
	echo "Added class declaration to $CLASS_NAME.cpp"
fi
