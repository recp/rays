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
#ifdef __cplusplus
extern "C" {
#endif

#ifndef _USE_MATH_DEFINES
#  define _USE_MATH_DEFINES       /* for windows */
#endif

#ifndef _CRT_SECURE_NO_WARNINGS
#  define _CRT_SECURE_NO_WARNINGS /* for windows */
#endif

#ifndef _CRT_NONSTDC_NO_DEPRECATE
#  define _CRT_NONSTDC_NO_DEPRECATE /* for windows */
#endif

/* since C99 or compiler ext */
#include <stdint.h>
#include <stddef.h>
#include <float.h>
#include <stdbool.h>
#include <errno.h>
#include <stdlib.h>

#ifdef DEBUG
#  include <assert.h>
#  include <stdio.h>
#endif

#if defined(_MSC_VER) || defined(__MINGW32__) || defined(__MINGW64__)
#  define RAYS_WINAPI
#  pragma warning (disable : 4068) /* disable unknown pragma warnings */
#endif

#if defined(_MSC_VER) || defined(__MINGW32__) || defined(__MINGW64__)
#  ifdef RAYS_STATIC
#    define RAYS_EXPORT
#  elif defined(RAYS_EXPORTS)
#    define RAYS_EXPORT __declspec(dllexport)
#  else
#    define RAYS_EXPORT __declspec(dllimport)
#  endif
#  define RAYS_HIDE
#else
#  define RAYS_EXPORT   __attribute__((visibility("default")))
#  define RAYS_HIDE     __attribute__((visibility("hidden")))
#endif

#if defined(_MSC_VER)
#  define RAYS_INLINE   __forceinline
#  define RAYS_ALIGN(X) __declspec(align(X))
#else
#  define RAYS_ALIGN(X) __attribute((aligned(X)))
#  define RAYS_INLINE   static inline __attribute((always_inline))
#endif

#ifndef __has_builtin
#  define __has_builtin(x) 0
#endif

typedef enum RaysResult {
  RAYS_NOOP     =  1,     /* no operation needed */
  RAYS_OK       =  0,
  RAYS_ERR      = -1,     /* UKNOWN ERR */
  RAYS_EFOUND   = -1000,
  RAYS_ENOMEM   = -ENOMEM,
  RAYS_EPERM    = -EPERM,
  RAYS_EBADF    = -EBADF  /* file couldn't parsed / loaded */
} RaysResult;

#ifdef __cplusplus
}
#endif
#endif /* rays_common_h */
