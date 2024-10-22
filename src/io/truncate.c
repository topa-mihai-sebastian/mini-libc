// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>
#include <sys/stat.h>

int truncate(const char *path, off_t length)
{

	int final = syscall(__NR_truncate, path, length);

	if (final < 0)
	{
		errno = -final;
		return -1;
	}

	return final;
}
