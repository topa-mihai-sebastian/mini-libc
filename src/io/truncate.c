// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>
#include <sys/stat.h>

int truncate(const char *path, off_t length)
{
	if (length < 0)
	{
		errno = EINVAL;
		return -1;
	}
	int final = syscall(__NR_truncate, path, length);

	if (final == -1)
	{
		return -1;
	}

	return 0;
}
