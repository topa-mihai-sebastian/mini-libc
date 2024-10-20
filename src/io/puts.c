#include <stdio.h>
#include <string.h>
#include <unistd.h>

int puts(const char *str)
{

	if (write(1, str, strlen(str)) == -1)
	{
		return -1;
	}

	if (write(1, "\n", 1) == -1)
	{
		return -1;
	}

	return 0;
}
