// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	if (size == 0)
	{
		return NULL;
	}

	size_t page_size = getpagesize();
	size_t aligned_size = (size + page_size - 1) & ~(page_size - 1);

	void *ptr = mmap(NULL, aligned_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

	if (ptr == MAP_FAILED)
	{
		return NULL;
	}

	if (mem_list_add(ptr, aligned_size) != 0)
	{
		munmap(ptr, aligned_size);
		return NULL;
	}
	return ptr;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	return NULL;
}

void free1(void *ptr)
{
	/* TODO: Implement free(). */
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
	return NULL;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	return NULL;
}
