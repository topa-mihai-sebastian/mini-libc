// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

off_t lseek(int fd, off_t offset, int whence)
{
	/* TODO: Implement lseek(). */
	// 						sau 8
	off_t final = syscall(__NR_lseek, offset, whence);
	if (final == (off_t)-1)
	{
		return -1;
	}
	return final;
}