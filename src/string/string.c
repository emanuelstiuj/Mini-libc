// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	char *p1 = destination;
	char *p2 = (char *) source;

	while (*p2 != '\0') {
		*p1 = *p2;
		p1++;
		p2++;
	}

	*p1 = '\0';

	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	char *p1 = destination;
	char *p2 = (char *) source;

	while (len) {
		*p1 = *p2;
		p1++;
		p2++;
		len--;
	}

	return destination;
}

char *strcat(char *destination, const char *source)
{
	char *p1 = destination;

	while (*p1 != '\0') {
		p1++;
	}

	char *p2 = (char *) source;

	while (*p2 != '\0') {
		*p1 = *p2;
		p1++;
		p2++;
	}

	*p1 = '\0';

	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	char *p1 = destination;

	while (*p1 != '\0') {
		p1++;
	}

	char *p2 = (char *) source;

	while (len) {
		*p1 = *p2;
		p1++;
		p2++;
		len--;
	}

	*p1 = '\0';

	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	if (strlen(str1) > strlen(str2)) {
		return 1;
	}
	if (strlen(str1) < strlen(str2)) {
		return -1;
	}

	char *p1 = (char *) str1;
	char *p2 = (char *) str2;

	while (*p1 != '\0') {
		if (*p1 > *p2) {
			return 1;
		}
		if (*p1 < *p2) {
			return -1;
		}
		p1++;
		p2++;
	}

	return 0;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	char *p1 = (char *) str1;
	char *p2 = (char *) str2;

	while (len) {
		if (*p1 > *p2) {
			return 1;
		}
		if (*p1 < *p2) {
			return -1;
		}
		p1++;
		p2++;
		len--;
	}

	return 0;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	char *p = (char *) str;

	while (*p != c && *p != '\0') {
		p++;
	}

	if (*p == '\0') {
		return NULL;
	}

	return p;
}

char *strrchr(const char *str, int c)
{
	char *p = (char *) str;
	int true = 0;

	while (*p != '\0') {
		if (*p == c) {
			true = 1;
		}
		p++;
	}

	if (!true) {
		return NULL;
	}

	while (*p != c) {
		p--;
	}

	return p;
}

char *strstr(const char *haystack, const char *needle)
{
	char *p_haystack = (char *) haystack;

	while (strlen(p_haystack) > strlen(needle)) {
		if (strncmp(p_haystack, needle, strlen(needle)) == 0) {
			return p_haystack;
		}
		p_haystack++;
	}

	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	char *p_haystack = (char *) haystack;
	int true = 0;

	while (strlen(p_haystack) > strlen(needle)) {
		if (strncmp(p_haystack, needle, strlen(needle)) == 0) {
			true = 1;
		}
		p_haystack++;
	}

	if (!true) {
		return NULL;
	}

	while(strncmp(p_haystack, needle, strlen(needle)) != 0) {
		p_haystack--;
	}

	return p_haystack;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	char *p = (char *) destination;
	char *value = (char *) source;

	while (num)
	{
		*p = *value;
		p++;
		value++;
		num--;
	}

	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	char *p_dest, *p_src;

	if (destination > source + num) {
		p_dest = (char *) destination + num - 1;
		p_src = (char *) source + num - 1;
		while (num) {
			*p_dest = *p_src;
			p_dest--;
			p_src--;
			num--;
		}

		return destination;
	}

	p_dest = (char *) destination;
	p_src = (char *) source;

	while (num)
	{
		*p_dest = *p_src;
		p_dest++;
		p_src++;
		num--;
	}

	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	char *p1 = (char *) ptr1;
	char *p2 = (char *) ptr2;

	while (num) {
		if (*p1 > *p2) {
			return 1;
		}
		if (*p1 < *p2) {
			return -1;
		}
		p1++;
		p2++;
		num--;
	}

	return 0;
}

void *memset(void *source, int value, size_t num)
{
	char character = (char) value;
	char *p = (char *) source;

	while (num) {
		*p = character;
		num--;
		p++;
	}

	return source;
}

