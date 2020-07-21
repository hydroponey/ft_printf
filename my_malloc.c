#include <stdlib.h>

#ifndef MYMALLOC_INCLUDED
#define MYMALLOC_INCLUDED

void *my_malloc(size_t size)
{
	srandomdev();
	if (random() & 1)
		return (malloc(size));
	else
		return (NULL);
}
#endif