#ifndef LIBDC_POSIX_DC_STRING_H
#define LIBDC_POSIX_DC_STRING_H

/*
 * Copyright 2021-2021 D'Arcy Smith.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "dc_posix_env.h"
#include <stddef.h>
#if __has_include(<locale.h>)
#include <locale.h>
#endif
#if __has_include(<xlocale.h>)
#include <xlocale.h>
#endif

void *dc_memccpy(const struct dc_posix_env *env, void *restrict s1, const void *restrict s2, int c, size_t n);
void *dc_memchr(const struct dc_posix_env *env, const void *s, int c, size_t n);
int dc_memcmp(const struct dc_posix_env *env, const void *s1, const void *s2, size_t n);
void *dc_memcpy(const struct dc_posix_env *env, void *restrict s1, const void *restrict s2, size_t n);
void *dc_memmove(const struct dc_posix_env *env, void *s1, const void *s2, size_t n);
void *dc_memset(const struct dc_posix_env *env, void *s, int c, size_t n);
char *dc_stpcpy(const struct dc_posix_env *env, char *restrict s1, const char *restrict s2);
char *dc_stpncpy(const struct dc_posix_env *env, char *restrict s1, const char *restrict s2, size_t n);
char *dc_strcat(const struct dc_posix_env *env, char *restrict s1, const char *restrict s2);
char *dc_strchr(const struct dc_posix_env *env, const char *s, int c);
int dc_strcmp(const struct dc_posix_env *env, const char *s1, const char *s2);
int dc_strcoll(const struct dc_posix_env *env, const char *s1, const char *s2);
int dc_strcoll_l(const struct dc_posix_env *env, const char *s1, const char *s2, locale_t locale);
char *dc_strcpy(const struct dc_posix_env *env, char *restrict s1, const char *restrict s2);
size_t dc_strcspn(const struct dc_posix_env *env, const char *s1, const char *s2);
char *dc_strdup(const struct dc_posix_env *env, struct dc_error *err, const char *s);
char *dc_strerror(const struct dc_posix_env *env, struct dc_error *err, int errnum);
int dc_strerror_r(const struct dc_posix_env *env, int errnum, char *strerrbuf, size_t buflen);
size_t dc_strlen(const struct dc_posix_env *env, const char *s);
char *dc_strncat(const struct dc_posix_env *env, char *restrict s1, const char *restrict s2, size_t n);
int dc_strncmp(const struct dc_posix_env *env, const char *s1, const char *s2, size_t n);
char *dc_strncpy(const struct dc_posix_env *env, char *restrict s1, const char *restrict s2, size_t n);
char *dc_strndup(const struct dc_posix_env *env, struct dc_error *err, const char *s, size_t n);
size_t dc_strnlen(const struct dc_posix_env *env, const char *s, size_t maxlen);
char *dc_strpbrk(const struct dc_posix_env *env, const char *s1, const char *s2);
char *dc_strrchr(const struct dc_posix_env *env, const char *s, int c);
char *dc_strsignal(const struct dc_posix_env *env, int signum);
size_t dc_strspn(const struct dc_posix_env *env, const char *s1, const char *s2);
char *dc_strstr(const struct dc_posix_env *env, const char *s1, const char *s2);
char *dc_strtok(const struct dc_posix_env *env, char *restrict s, const char *restrict sep);
char *dc_strtok_r(const struct dc_posix_env *env, char *restrict s, const char *restrict sep, char **restrict state);
size_t dc_strxfrm(const struct dc_posix_env *env, struct dc_error *err, char *restrict s1, const char *restrict s2, size_t n);
size_t dc_strxfrm_l(const struct dc_posix_env *env, struct dc_error *err, char *restrict s1, const char *restrict s2, size_t n, locale_t locale);


#endif // LIBDC_POSIX_DC_STRING_H
