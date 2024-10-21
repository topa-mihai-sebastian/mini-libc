// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

off_t lseek(int fd, off_t offset, int whence)
{
	if (fd < 0)
	{
		errno = EBADF;
		return (off_t)-1;
	}

	off_t final = syscall(__NR_lseek, fd, offset, whence);
	// cast
	if (final == (off_t)-1)
	{
		return (off_t)-1;
	}

	return final;
}