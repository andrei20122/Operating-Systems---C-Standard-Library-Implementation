// SPDX-License-Identifier: BSD-3-Clause

#include <internal/io.h>
#include <internal/syscall.h>
#include <internal/types.h>

ssize_t write(int fd, const void *buf, size_t len)
{
	return syscall(1, fd, buf, len);
}

ssize_t read(int fd, void *buf, size_t len)
{
	return syscall(0, fd, buf, len);
}
