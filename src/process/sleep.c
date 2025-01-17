// SPDX-License-Identifier: BSD-3-Clause
#include <internal/syscall.h>
#include <internal/io.h>
#include <stdlib.h>
#include <stdio.h>
#include <internal/types.h>
#include <time.h>

int nanosleep(const struct timespec *req, struct timespec *rem)
{
	int result = syscall(__NR_nanosleep, req, rem);
	if (result == -1)
	{
		return result;
	}
	return 0;
}

unsigned sleep(unsigned seconds)
{
	struct timespec ts;
	ts.tv_sec = seconds;
	ts.tv_nsec = 0;

	if (nanosleep(&ts, NULL) == -1)
	{
		return seconds;
	}

	return 0;
}
