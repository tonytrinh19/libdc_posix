#ifndef LIBDC_POSIX_DC_POSIX_ENV_H
#define LIBDC_POSIX_DC_POSIX_ENV_H


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


#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-macros"
#define __STDC_WANT_LIB_EXT1__ 1
#pragma GCC diagnostic pop
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>


#ifndef __STDC_LIB_EXT1__
typedef int errno_t;
#endif


/**
 * Error states.
 */
typedef enum
{
    DC_ERROR_NONE = 0,  /**< There is no error */
    DC_ERROR_ERRNO,     /**< The error is due to errno being set */
    DC_ERROR_SYSTEM,    /**< The error is from a library call that doesn't set errno */
    DC_ERROR_USER,      /**< The error is from a non-standard function */
} dc_error_type;


/**
 *
 */
struct dc_error
{
    char *message;              /**< the message for the error */
    const char *file_name;      /**< the file name that the error happened in */
    const char *function_name;  /**< the function name that the error happened in */
    size_t line_number;         /**< the line number that the error happened on */
    dc_error_type type;         /**< type type of error */

    union
    {
        errno_t errno_code;     /**< the value of errno, if the type is DC_ERROR_ERRNO */
        int     err_code;       /**< type value of the error, if the type is not DC_ERROR_ERRNO */
    };
};


#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpadded"
struct dc_posix_env
{
    bool zero_free;
    bool null_free;
    void (*error_reporter)(const struct dc_posix_env *env, const struct dc_error *err);
    void (*tracer)(const struct dc_posix_env *env, const char *file_name, const char *function_name, size_t line_number);
};
#pragma GCC diagnostic pop


/**
 *
 * @param env
 * @param error_reporter
 */
void dc_posix_env_init(struct dc_posix_env *env, void (*error_reporter)(const struct dc_posix_env *env, const struct dc_error *err));


/**
 *
 * @param env
 * @param err
 */
void dc_posix_default_error_reporter(const struct dc_posix_env *env, const struct dc_error *err);

/**
 *
 * @param env
 * @param file_name
 * @param function_name
 * @param line_number
 */
void dc_posix_default_tracer(const struct dc_posix_env *env, const char *file_name, const char *function_name, size_t line_number);


/**
 *
 * @param err
 */
void dc_error_init(struct dc_error *err);


/**
 *
 * @param err
 */
void dc_error_reset(struct dc_error *err);


/**
 *
 * @param err
 * @param file_name
 * @param function_name
 * @param line_number
 * @param err_code
 */
void dc_error_errno(struct dc_error *err, const char *file_name, const char *function_name, size_t line_number, errno_t err_code);


/**
 *
 * @param err
 * @param file_name
 * @param function_name
 * @param line_number
 * @param err_code
 */
void dc_error_system(struct dc_error *err, const char *file_name, const char *function_name, size_t line_number, const char *msg, int err_code);


/**
 *
 * @param err
 * @param file_name
 * @param function_name
 * @param line_number
 * @param err_code
 */
void dc_error_user(struct dc_error *err, const char *file_name, const char *function_name, size_t line_number, const char *msg, int err_code);


#define DC_REPORT_ERRNO(env, err, err_code) dc_error_errno((err), __FILE__, __func__, __LINE__, (err_code)); if((env)->error_reporter != NULL) (env)->error_reporter((env), (err))
#define DC_REPORT_SYSTEM(env, err, msg, err_code) dc_error_system((err), __FILE__, __func__, __LINE__, (msg), (err_code)); if((env)->error_reporter != NULL) (env)->error_reporter((env), (err))
#define DC_REPORT_USER(env, err, msg, err_code) dc_error_user((err), __FILE__, __func__, __LINE__, (msg), (err_code)); if((env)->error_reporter != NULL) (env)->error_reporter((env), (err))
#define DC_TRACE(env) if((env)->tracer != NULL) (env)->tracer((env), __FILE__, __func__, __LINE__)
#define DC_HAS_ERROR(err) (err)->type != DC_ERROR_NONE
#define DC_HAS_NO_ERROR(err) (err)->type == DC_ERROR_NONE
#define DC_ERROR_IS_ERRNO(err, code) ((err)->type == DC_ERROR_ERRNO) && ((err)->errno_code == (code))


#endif // LIBDC_POSIX_DC_POSIX_ENV_H