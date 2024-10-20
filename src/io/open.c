// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <syscall.h>
#include "../include/internal/arch/x86_64/syscall_list.h"
#include <stdarg.h>
#include <errno.h>

int open(const char *filename, int flags, ...)
{
	/* TODO: Implement open system call. */

	return -1;
}