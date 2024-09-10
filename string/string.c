/* SPDX-License-Identifier: BSD-3-Clause */

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
	char *aux = destination;// am folosit aux pt a indica inceputul lui destination

    while(*source){//copiez fiecare caracter de la source la destination prin diferentuere
        *aux++ = *source++;//incrementez ambii pointeri tot asa pt copierea fiecarui caract
    }
    *aux = '\0';//adaugam '\0' pt terminarea sirului la finalul lui destination 
    //bineinteles , dupa ce copia este completa
	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
	
    size_t i;

    for ( i = 0; i < len && source[i] != '\0'; i++) {//copiam fiecare caracter pana la len sau pana este != '\0'
        destination[i] = source[i];
    }
    //in cazul in care lungimea sirului sursa este mai mica decat lungimea specificata len
    //completez caracterele ramase in sirul de destinatie
    while (i < len) {
        destination[i++] = '\0';
    }

	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	char *aux = destination;

    while (*aux != '\0') {
        aux++;//iterez pana la intalnirea '\0'
    }

    //pentru a parcurge sirul sursa, copiez fiecare caracter la sfarsitul sirului de destinatie 
    //folosind pointerul aux pana cand se intalneste terminatorul nul "\0".
    while (*source != '\0') {
        *aux++ = *source++;
    }

    *aux = '\0';

	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	char *aux = destination;

    while (*aux != '\0') {
        aux++;
    }

    size_t i;
    for (i = 0; i < len && source[i] != '\0'; i++) {//acelasi lucru doar mai apare cond pana la lungimea len
        *aux++ = source[i];
    }

    *aux = '\0';

	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	for (size_t i = 0; str1[i] != '\0' || str2[i] != '\0' ; i++) {
        if (str1[i] < str2[i]) {
            return -1;
        } else if (str1[i] > str2[i]) {
            return 1;
        }
    }

	return 0;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
	
	for (size_t i = 0; (i<len) && (str1[i] != '\0' || str2[i] != '\0') ; i++) {
        if (str1[i] < str2[i]) {
            return -1;
        } else if (str1[i] > str2[i]) {
            return 1;
        }
    }

	return 0;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	while (str[i] != '\0') {
        ++i;
    }

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
	 while (*str != '\0') {
        if (*str == c) {
            return (char *) str;//returnez pointer ul acelui caract c
        }
        str++;
    }
    if (c == '\0') {
        return (char *) str;
    }

	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	const char *ptr = str;
    while (*ptr != '\0')
        ptr++;
    while (ptr >= str) {
        if (*ptr == (char)c)
            return (char *)ptr;
        ptr--;
    }

	return NULL;
}

char *strstr(const char *str1, const char *str2)
{
	/* TODO: Implement strstr(). */
	 if (*str2 == '\0') {
        return (char *)str1;
    }
    const char *h, *n;
    while (*str1 != '\0') {
        h = str1;
        n = str2;
        while (*n != '\0' && *h == *n) {
            h++;
            n++;
        }
        if (*n == '\0') {
            return (char *)str1;
        }
        str1++;
    }
	return NULL;
}

char *strrstr(const char *str1, const char *str2)
{
	/* TODO: Implement strrstr(). */
	size_t h = strlen(str1);
    size_t n = strlen(str2);

    if (n > h) {
        return NULL;
    }

    const char *p = str1 + h - n;

    while (p >= str1) {
        if (strncmp(p, str2, n) == 0) {
            return (char *) p;
        }
        p--;
    }

	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	char *d = (char *) destination;
    const char *s = (const char *) source;
    while (num--) {
        *d++ = *s++;
    }

	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	char *d = (char *) destination;
    const char *s = (const char *) source;

    if (s < d && s + num > d) {
        s += num;
        d += num;
        while (num--) {
            *--d = *--s;
        }
    } else {
        while (num--) {
            *d++ = *s++;
        }
    }

	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	const unsigned char *p1 = (const unsigned char *) ptr1;
    const unsigned char *p2 = (const unsigned char *) ptr2;

    for (size_t i = 0; i < num; i++) {
        if (p1[i] < p2[i]) {
            return -1;
        } else if (p1[i] > p2[i]) {
            return 1;
        }
    }

	return 0;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	unsigned char *p = (unsigned char *) source;

    for (size_t i = 0; i < num; i++) {
        p[i] = (unsigned char) value;
    }

	return source;
}
