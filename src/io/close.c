// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int close(int fd)
{
	/* TODO: Implement close(). */
	int closeRes = syscall(__NR_close, fd);

	if (closeRes == -1)
		return -1; // fail
	return 0;	   // succes
}
