// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <fcntl.h>
#include <errno.h>

int stat(const char *restrict path, struct stat *restrict buf)
{
	/* TODO: Implement stat(). */

	int st = (int)syscall(__NR_stat, path, buf);
	if (st == -1)
	{
		if (errno == ENOENT)
		{
			// test_stat_non_existent_file
			return -1;
		}
		return -1;
	}
	return 0;
}
