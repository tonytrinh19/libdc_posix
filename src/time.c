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
#include "dc_time.h"

// https://pubs.opengroup.org/onlinepubs/9699919799/functions/nanosleep.html
int dc_nanosleep(const struct dc_posix_env *env,
                 struct dc_error *          err,
                 const struct timespec *    rqtp,
                 struct timespec *          rmtp)
{
    int ret_val;

    DC_TRACE(env);
    errno   = 0;
    ret_val = nanosleep(rqtp, rmtp);

    if(ret_val == -1)
    {
        DC_ERROR_RAISE_ERRNO(err, errno);
    }

    return ret_val;
}
