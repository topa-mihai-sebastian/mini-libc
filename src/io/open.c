// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int open(const char *filename, int flags, ...)
{
	mode_t mode = 0;

	// daca fisierul specificat nu exista, acesta trb creat
	if (flags & O_CREAT)
	{
		va_list args;
		va_start(args, flags);
		mode = va_arg(args, mode_t); // permisiunile
		va_end(args);
	}

	// dau syscall ca sa apelez openat cu AT_FDCWD ca sa se foloseasca folderul curent
	int fd = syscall(__NR_openat, AT_FDCWD, filename, flags, mode);

	if (fd == -1)
	{
		return -1;
	}

	return fd;
}
