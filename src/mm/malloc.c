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
	// initializam lista
	mem_list_init();

	// alocam memoria folosind mmap (rezervam memorie)
	memory = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

	if (memory == MAP_FAILED) //-1
	{
		return NULL;
	}
	// adaugam blocul alocat de memorie in lista de memorie
	int res = mem_list_add(memory, size);
	if (res != 0)
	{
		// daca a dat fail eliberam memoria alocata
		munmap(memory, size);
		return NULL;
	}

	return memory;
}

void *calloc(size_t nmemb, size_t size)
{
	// calculam marimea pe care o aloc
	// marimea unui elemet * nr de elemente
	size_t total_size = nmemb * size;
	// folosesc mallocapo setez toate valorile la 0 cu memset

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
	// verific daca se vrea sa se dea free la un pointer null
	if (ptr == NULL)
	{
		return;
	}

	struct mem_list *item;

	item = mem_list_find(ptr);
	if (item == NULL)
	{
		return;
	}

	// scot blocul de memorie din lista
	mem_list_del(ptr);

	// dau free cu munmap
	munmap(ptr, item->len);
}

void *realloc(void *ptr, size_t size)
{
	// verificari
	if (ptr == NULL)
	{
		return malloc(size);
	}

	if (size == 0)
	{
		free(ptr);
		return NULL;
	}
	// creez un nou element in lista si verifc sa fie totul ok
	struct mem_list *item = mem_list_find(ptr);

	if (item == NULL)
	{
		return NULL;
	}
	// creez un void* de marimea size
	void *new_ptr = malloc(size);
	if (new_ptr == NULL)
	{
		return NULL;
	}
	// vreau sa vad daca marimea noua este mai mare sau mai mica decat
	// cea veche
	size_t copy_size;

	if (item->len < size)
		copy_size = item->len;
	else
		copy_size = size;

	// copiez datele in noul void*
	memcpy(new_ptr, ptr, copy_size);
	// eliberez vechiul void*
	free(ptr);
	// returnez noul void*
	return new_ptr;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	size_t total_size = nmemb * size;
	// verific sa nu existe overflow
	// if (nmemb != 0 && total_size / nmemb != size)
	//{
	//	return NULL;
	//}
	// daca inputul ptr este NULL functia este un fel de calloc
	if (ptr == NULL)
	{
		return calloc(nmemb, size);
	}
	// daca marimea este 0
	if (nmemb == 0 || size == 0)
	{
		free(ptr);
		return NULL;
	}

	return realloc(ptr, total_size);
}
