#!/usr/bin/bash

CLASSNAME_CAPITAL="$(tr '[:lower:]' '[:upper:]' <<< ${1:0:1})${1:1}"
CLASSNAME_UPPER=$(echo $1 | tr '[:lower:]' '[:upper:]')

if [[ -n $1 ]]; then
	touch $(pwd)/$CLASSNAME_CAPITAL.{hpp,cpp}
	echo "Created files $CLASSNAME_CAPITAL.cpp & $CLASSNAME_CAPITAL.hpp"

cat << EOF > $(pwd)/$CLASSNAME_CAPITAL.hpp
#ifndef ${CLASSNAME_UPPER}_HPP
#define ${CLASSNAME_UPPER}_HPP

#include <iostream>

class $CLASSNAME_CAPITAL
{
	private:

	public:
		$CLASSNAME_CAPITAL(void);
		~$CLASSNAME_CAPITAL(void);
		$CLASSNAME_CAPITAL(const $CLASSNAME_CAPITAL &obj);
		$CLASSNAME_CAPITAL &operator=(const $CLASSNAME_CAPITAL &obj);
};

#endif
EOF
		echo "Added class definition to $CLASSNAME_CAPITAL.hpp"

cat << EOF > $(pwd)/$CLASSNAME_CAPITAL.cpp
#include "$CLASSNAME_CAPITAL.hpp"

$CLASSNAME_CAPITAL::$CLASSNAME_CAPITAL(void)
{
	std::cout << "[$CLASSNAME_CAPITAL] Default constructor has been called!" << std::endl;
}

$CLASSNAME_CAPITAL::~$CLASSNAME_CAPITAL()
{
	std::cout << "[$CLASSNAME_CAPITAL] Destructor has been called!" << std::endl;
}

$CLASSNAME_CAPITAL::$CLASSNAME_CAPITAL(const $CLASSNAME_CAPITAL &obj)
{
	*this = obj;
	std::cout << "[$CLASSNAME_CAPITAL] Copy constructor has been called!" << std::endl;
}

$CLASSNAME_CAPITAL &$CLASSNAME_CAPITAL::operator=(const $CLASSNAME_CAPITAL &obj)
{
	std::cout << "[$CLASSNAME_CAPITAL] Copy assignment operator has been called!" << std::endl;
	if (this != &obj)
	{
	}
	return (*this);
}
EOF
	echo "Added class declaration to $CLASSNAME_CAPITAL.cpp"
fi
