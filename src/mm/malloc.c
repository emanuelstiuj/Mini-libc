// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	if (size == 0) {
		return NULL;
	}

	void *ret = mmap(NULL, size, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);

	if (ret == MAP_FAILED) {
		return NULL;
	}

	mem_list_add(ret, size);

	return ret;
}

void *calloc(size_t nmemb, size_t size)
{
	if (size == 0) {
		return NULL;
	}

	void *ret = mmap(NULL, size, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);

	if (ret == MAP_FAILED) {
		return NULL;
	}

	char *p = (char *)ret;
	while (nmemb) {
		*p = 0;
		nmemb--;
		p++;
	}

	mem_list_add(ret, size);

	return ret;
}

void free(void *ptr)
{
	struct mem_list *item = mem_list_find(ptr);

	if (item == NULL) {
		return;
	}

	int length = item->len;
	mem_list_del(ptr);
	munmap(ptr, length);
}

void *realloc(void *ptr, size_t size)
{
	if (ptr == NULL) {
		return malloc(size);
	}

	if (size == 0) {
		free(ptr);
		return NULL;
	}

	struct mem_list *item = mem_list_find(ptr);

	int old_size = item->len;

	long new_addr = (long) mremap(ptr, old_size, size, -1);
	if (new_addr < 0) {
		return ptr;
	}

	if ((void *)new_addr == ptr) {
		item->len = size;
		return ptr;
	}

	mem_list_del(ptr);
	munmap(ptr, old_size);

	mem_list_add((void *)new_addr, size);

	return (void *)new_addr;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	if (nmemb * size < nmemb || nmemb * size < size) {
		return NULL;
	}

	return realloc(ptr, nmemb * size);
}
