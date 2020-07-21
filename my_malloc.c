#include <stdlib.h>

void *my_malloc(size_t size)
{
	srandomdev();
	if (random() & 1)
		return (malloc(size));
	else
		return (NULL);
}