/* SPDX-License-Identifier: BSD-3-Clause */

#ifndef __STRING_H__
#define __STRING_H__ 1
#ifdef __cplusplus
extern "C"
{
#endif
#include <internal/types.h>
	struct timespec
	{
		long tv_sec;
		long tv_nsec;
	};
	int nanosleep(const struct timespec *req, struct timespec *rem);
	unsigned sleep(unsigned seconds);

#ifdef __cplusplus
}
#endif

#endif
