// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	void *memory;
	mem_list_init();
	memory = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (memory == MAP_FAILED)
	{
		return NULL;
	}

	if (mem_list_add(memory, size) != 0)
	{
		munmap(memory, size);
		return NULL;
	}

	return memory;
}

void *calloc(size_t nmemb, size_t size)
{
	size_t total_size = nmemb * size;

	void *memory = malloc(total_size);
	if (memory == NULL)
	{
		return NULL;
	}

	memset(memory, 0, total_size);

	return memory;
}

void free(void *ptr)
{
	struct mem_list *item;

	item = mem_list_find(ptr);
	if (item == NULL)
	{
		return;
	}

	mem_list_del(ptr);

	munmap(ptr, item->len);
}

void *realloc(void *ptr, size_t size)
{
	if (ptr == NULL)
	{
		return malloc(size);
	}

	if (size == 0)
	{
		free(ptr);
		return NULL;
	}
	struct mem_list *item = mem_list_find(ptr);
	if (item == NULL)
	{
		return NULL;
	}

	void *new_ptr = malloc(size);
	if (new_ptr == NULL)
	{
		return NULL;
	}

	size_t copy_size = item->len < size ? item->len : size;
	memcpy(new_ptr, ptr, copy_size);

	free(ptr);

	return new_ptr;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	size_t total_size = nmemb * size;

	if (nmemb != 0 && total_size / nmemb != size)
	{
		return NULL;
	}

	if (ptr == NULL)
	{
		return calloc(nmemb, size);
	}

	if (nmemb == 0 || size == 0)
	{
		free(ptr);
		return NULL;
	}

	return realloc(ptr, total_size);
}
