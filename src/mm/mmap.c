// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>

#ifndef MAP_FIXED
#define MAP_FIXED 0x10
#endif

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	/* TODO: Implement mmap(). */
	void *res = (void *)syscall(__NR_mmap, addr, length, prot, flags, fd, offset);

	if (res == MAP_FAILED)
	{
		return MAP_FAILED;
	}

	return res;
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags)
{
	/* TODO: Implement mremap(). */
	void *res = (void *)syscall(__NR_mremap, old_address, old_size, new_size, flags);

	if (res == MAP_FAILED)
	{
		return MAP_FAILED;
	}

	return res;
}

int munmap(void *addr, size_t length)
{
	/* TODO: Implement munmap(). */
	int res = (int)syscall(__NR_munmap, addr, length);
	if (res == -1)
	{
		return -1;
	}
	return 0;
}
