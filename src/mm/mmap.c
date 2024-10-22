// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	/* TODO: Implement mmap(). */
	void *res = syscall(__NR_mmap, addr, prot, flags, fd, offset);

	if (res == MAP_FAILED)
	{
		return MAP_FAILED;
	}

	return res;
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags)
{
	/* TODO: Implement mremap(). */
	void *res = syscall(__NR_mremap, old_size, new_size, flags);

	if (res == MAP_FAILED)
	{
		return MAP_FAILED;
	}

	return res;
}

int munmap(void *addr, size_t length)
{
	/* TODO: Implement munmap(). */
	int res = syscall(__NR_munmap, length);
	if (res == -1)
	{
		return -1;
	}
	return 0;
}
