// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>
#include <stdio.h>

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

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
	while (len && *source != '\0')
	{
		*aux = *source;
		aux++;
		source++;
		len--;
	}

	*aux = '\0';

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

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
	char *aux = (char *)str;
	while (*aux != '\0')
	{
		if (*aux == c)
		{
			return (char *)aux;
		}
		aux++;
	}
	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	char *aux = (char *)str;
	while (*aux != '\0')
	{
		aux++;
	}
	while (aux != str)
	{
		if (*aux == c)
		{
			return (char *)aux;
		}
		aux--;
	}
	return NULL;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
	if (*needle == '\0')
	{
		return (char *)haystack;
	}
	const char *aux;
	// iteram prin sirul in care cautam
	for (aux = haystack; *aux != '\0'; aux++)
	{
		const char *current = aux;
		const char *auxNeedle = needle;
		// daca elementul current este egal cu cel din sirul
		// principal continuam cautarea pana cand
		// dam de '\0'
		// daca s-a ajuns la '\0' in auxNeedle inseamna
		//  ca s-a gasit subsirul pe care il cautam
		while (*auxNeedle != '\0' && *auxNeedle == *current)
		{
			auxNeedle++;
			current++;
		}
		if (*auxNeedle == '\0')
		{
			return (char *)aux;
		}
	}
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	if (*needle == '\0')
	{
		return (char *)haystack;
	}
	const char *aux;
	// strlen implementat
	// folosesc acelasi principiu ca la strstr
	// fac doar for-ul invers
	for (aux = haystack + strlen(haystack) - strlen(needle); aux >= haystack; aux--)
	{
		const char *current = aux;
		const char *auxNeedle = needle;
		// daca elementul current este egal cu cel din sirul
		// principal continuam cautarea pana cand
		// dam de '\0'
		// daca s-a ajuns la '\0' in auxNeedle inseamna
		//  ca s-a gasit subsirul pe care il cautam
		while (*auxNeedle != '\0' && *auxNeedle == *current)
		{
			auxNeedle++;
			current++;
		}
		if (*auxNeedle == '\0')
		{
			return (char *)aux;
		}
	}
	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	// am castat la char pt ca un char ocupa un octet
	const char *src = (const char *)source;
	char *dest = (char *)destination;
	for (size_t i = 0; i < num; i++)
	{
		dest[i] = src[i];
	}
	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	char buffer[3000];
	strcpy(buffer, source);
	char *dest = (char *)destination;
	for (size_t i = 0; i < num; i++)
	{
		dest[i] = buffer[i];
	}
	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	const char *p1 = (const char *)ptr1;
	const char *p2 = (const char *)ptr2;
	size_t i = 0;
	while (i < num)
	{
		if (p1[i] != p2[i])
		{
			int ok = p1[i] - p2[i];
			return ok;
		}
		i++;
	}
	return 0;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	char *src = (char *)source;
	for (size_t i = 0; i < num; i++)
	{
		src[i] = (char)value;
	}
	return source;
}
