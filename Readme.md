# Operating Systems - C Standard Library Implementation

This project involves reimplementing several key functions from the C standard library (e.g., `stdio`, `stddef`, `stat`) as part of the **Operating Systems** course. The goal was to build a deeper understanding of system-level programming by directly working with low-level system calls and recreating fundamental functionality.

## Key Features

- **Custom I/O Operations**: Reimplemented essential I/O functions such as `open`, `close`, `read`, `write`, `lseek`, and `puts`, enabling file manipulation at a lower level.
- **File Metadata**: Recreated functionality for working with file attributes using the `stat` structure.
- **Memory Management**: Developed custom memory allocation and deallocation functions (`malloc`, `free`) to manage heap space.
- **Error Handling**: Implemented error codes and managed exceptions in line with typical C library conventions.

## Project Structure

- **`io/`**: Contains functions for input/output operations such as `open`, `read_write`, `lseek`, `close`, and `truncate`.
- **`mm/`**: Handles memory management, including allocation (`malloc`) and deallocation (`free`).
- **`process/`**: Implements process control functionalities.
- **`crt/`**: Contains C runtime implementations.
- **`syscall.c`**: Direct interaction with system calls for various operations.
- **`errno.c`**: Custom error management.

## Technologies Used

- **Language**: C
- **System Programming**: Utilized Linux system calls to handle I/O, memory, and process operations directly.
- **Error Handling**: Comprehensive error reporting with custom implementation of `errno`.


LEAHU MORIE ROBERT ANDREI 331CB
Sources:
	-  blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/ pentru syscalls pt apeluri
	- labs and documentation man
	- I used for documentation this link https://www.gnu.org/software/libc/manual/html_mono/libc.html
	- and https://en.wikipedia.org/wiki/C_standard_library
