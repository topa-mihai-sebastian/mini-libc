// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
	char *aux = destination;
	while (*source != '\0')
	{
		*destination = *source;
		destination++;
		source++;
	}
	*destination = '\0';
	return aux;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	char *aux = destination;

	while (len && *source)
	{
		*destination++ = *source++;
		len--;
	}

	while (len)
	{
		*destination++ = '\0';
		len--;
	}

	return aux;
}

char *strcat(char *destination, const char *source)
{
	int i = 0, j = 0;
	while (destination[i] != '\0')
	{
		i++;
	}

	while (source[j] != '\0')
	{
		destination[i] = source[j];
		i++;
		j++;
	}
	destination[i] = '\0';

	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	char *aux = destination;
	while (*aux != '\0')
	{
		aux++;
	}
	while (len && *source)
	{
		*aux = *source;
		aux++;
		source++;
		len--;
	}
	// if source is < len
	while (len)
	{
		*aux = '\0';
		aux++;
		len--;
	}
	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	while (*str1 && *str2)
	{
		// daca caracterele sunt diferite se returneaza -1 daca str1 este mai mic
		// si 1 daca str1 este mai mare
		if (*str1 != *str2)
		{
			int a = *(unsigned char *)str1 - *(unsigned char *)str2;
			if (a < 0)
				return -1;
			return 1;
		}
		str1++;
		str2++;
	}
	int a = *(unsigned char *)str1 - *(unsigned char *)str2;
	if (a < 0)
		return -1;
	else if (a > 0)
		return 1;
	return 0;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	while (len && (*str1 && *str2))
	{
		if (*str1 != *str2)
		{
			int a = *(unsigned char *)str1 - *(unsigned char *)str2;
			if (a < 0)
				return -1;
			return 1;
		}
		str1++;
		str2++;
		len--;
	}
	if (len == 0)
		return 0;

	int a = *(unsigned char *)str1 - *(unsigned char *)str2;
	if (a < 0)
		return -1;
	else if (a > 0)
		return 1;
	return 0;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	return NULL;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	return -1;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	return source;
}
