// SPDX-License-Identifier: BSD-3-Clause
#include <internal/syscall.h>
#include <internal/io.h>
#include <stdlib.h>
#include <stdio.h>
#include <internal/types.h>
#include "nanosleep.c"

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
