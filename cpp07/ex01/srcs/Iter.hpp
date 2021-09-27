#ifndef ITER_H
# define ITER_H

template < typename T >
void	iter(T *arr, int len, void (f)(T const &arr))
{
	for (int i = 0; i < len; i++)
		f(arr[i]);
}

#endif
