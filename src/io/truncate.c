// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int truncate(const char *path, off_t length)
{
	/* TODO: Implement truncate(). */
	int final = syscall(__NR_truncate, path, length);

	if (final == -1)
	{
		return -1;
	}

	return 0;
}
