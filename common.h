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

#ifndef rays_common_h
#define rays_common_h

#ifndef _USE_MATH_DEFINES
#  define _USE_MATH_DEFINES       /* for windows */
#endif

#ifndef _CRT_SECURE_NO_WARNINGS
#  define _CRT_SECURE_NO_WARNINGS /* for windows */
#endif

#include <stdint.h>
#include <stddef.h>
#include <math.h>
#include <float.h>
#include <stdbool.h>

#if defined(_MSC_VER)
#  ifdef RAYS_STATIC
#    define RAYS_EXPORT
#  elif defined(RAYS_EXPORTS)
#    define RAYS_EXPORT __declspec(dllexport)
#  else
#    define RAYS_EXPORT __declspec(dllimport)
#  endif
#  define RAYS_INLINE __forceinline
#else
#  define RAYS_EXPORT __attribute__((visibility("default")))
#  define RAYS_INLINE static inline __attribute((always_inline))
#endif

#endif /* rays_common_h */
