#ifndef WHATEVER_H
# define WHATEVER_H

template <typename T>
T	max(T const &x, T const &y)
{
	return x >= y ? x : y;
}

template <typename T>
T	min(T const &x, T const &y)
{
	return x >= y ? y : x;
}

template <typename T>
void	swap(T &x, T &y)
{
	T	tmp;

	tmp = x;
	x = y;
	y = tmp;
}

#endif
