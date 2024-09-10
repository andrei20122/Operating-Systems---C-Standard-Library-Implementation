// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */
     if (size == 0) {
        return NULL;
    }

	void *aux = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (aux == MAP_FAILED) {
        return NULL;
    }

	mem_list_add(aux, size);
    return aux;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	return malloc(nmemb*size);
}

void free(void *ptr)
{
	/* TODO: Implement free(). */
    if(ptr == NULL)
        return;

	size_t size = mem_list_find(ptr)->len;
	munmap(ptr, size);
	mem_list_del(ptr);
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
	if (ptr == NULL) {
        return malloc(size);
    }

    if (size == 0) {
        free(ptr);
        return NULL;
    }

    void* new_ptr = malloc(size);
    if (new_ptr == NULL) {
        return NULL;
    }

    size_t copy_size = mem_list_find(ptr)->len;
    if (copy_size > size) {
        copy_size = size;
    }
    memcpy(new_ptr, ptr, copy_size);

    free(ptr);
    return new_ptr;
	//return NULL;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */

	return realloc(ptr, nmemb*size);
}
