// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <syscall.h>
#include "../include/internal/arch/x86_64/syscall_list.h"
#include <stdarg.h>
#include <errno.h>

int open(const char *filename, int flags, ...)
{
	mode_t mode = 0;
	va_list args;

	if (flags & O_CREAT)
	{
		va_start(args, flags);
		mode = va_arg(args, mode_t);
		va_end(args);
	}

	int fd = syscall(__NR_open, filename, flags, mode);

	if (fd == -1)
	{
		return -errno;
	}

	return fd;
}