// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int ftruncate(int fd, off_t length)
{
	if (length < 0)
	{
		errno = EINVAL;
		return -1;
	}

	if (fd < 0)
	{
		errno = -fd;
		return -1;
	}

	int final = syscall(__NR_ftruncate, fd, length);

	if (final == -1)
	{
		return -1;
	}

	return 0;
}
