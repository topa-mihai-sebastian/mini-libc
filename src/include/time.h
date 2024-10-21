// SPDX-License-Identifier: BSD-3-Clause

#ifndef TIME_H
#define TIME_H

struct timespec
{
	long tv_sec;
	long tv_nsec;
};

int nanosleep(const struct timespec *req, struct timespec *rem);
unsigned sleep(unsigned seconds);

#endif
