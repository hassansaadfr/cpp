#ifndef BASE_H
# define BASE_H

# include <iostream>

class Base
{
	public:
		virtual ~Base(void);
};

class A : public Base
{};

class B : public Base
{};

class C : public Base
{};


#endif
