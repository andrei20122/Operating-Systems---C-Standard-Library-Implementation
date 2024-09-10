#include <stdio.h>

int puts(const char *string)
{
	write(1, string, strlen(string));
    write(1, "\n", 1);

	return 0;
}