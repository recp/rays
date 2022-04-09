/*
 * Copyright (C) Recep Aslantas
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef src_common_h
#define src_common_h

#include "../include/rays/common.h"
#include "../include/rays/assets.h"
#include <stdlib.h>
#include <stdio.h>

#include <cglm/cglm.h>

#define RAYS_ARRAY_LEN(ARR) (sizeof(ARR) / sizeof(ARR[0]))

#ifdef __GNUC__
#  define RAYS_DESTRUCTOR  __attribute__((destructor))
#  define RAYS_CONSTRUCTOR __attribute__((constructor))
#else
#  define RAYS_DESTRUCTOR
#  define RAYS_CONSTRUCTOR
#endif

#ifdef RAYS_WINAPI
/*
 #  define WIN32_LEAN_AND_MEAN
 #  include <windows.h>
 */
#  define strncasecmp _strnicmp
#  define strcasecmp  _stricmp
#endif

#define RAYS__UNUSED(X) (void)X

#endif /* src_common_h */
