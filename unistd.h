#pragma once

#include <stddef.h>
#include <stdint.h>

///@defgroup unistd_file_management
int close(int fd);

int write(int fd, const void *buff, size_t count);