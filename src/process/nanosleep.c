// SPDX-License-Identifier: BSD-3-Clause

#include <internal/syscall.h>
#include <internal/io.h>
#include <stdlib.h>
#include <stdio.h>
#include <internal/types.h>

struct timespec
{
	long tv_sec;
	long tv_nsec;
};

int nanosleep(const struct timespec *req, struct timespec *rem)
{
	int result = syscall(__NR_nanosleep, req, rem);
	if (result == -1)
	{
		return -1;
	}
	return 0;
}