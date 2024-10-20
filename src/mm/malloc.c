// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	// Check for invalid size
	if (size == 0)
	{
		return NULL;
	}

	// Align size to system page size
	size_t page_size = getpagesize();
	size_t aligned_size = (size + page_size - 1) & ~(page_size - 1);

	// Allocate memory using mmap
	void *ptr = mmap(NULL, aligned_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (ptr == MAP_FAILED)
	{
		return NULL;
	}

	// Add the memory block to the mem_list
	if (mem_list_add(ptr, aligned_size) != 0)
	{
		// If we cannot track the allocation, free the memory
		munmap(ptr, aligned_size);
		return NULL;
	}

	// Return the pointer to the allocated memory
	return ptr;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	return NULL;
}

void free(void *ptr)
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
