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

#include "../common.h"
#include "write.h"

RAYS_EXPORT
void
rays_writef_v3(FILE * __restrict file, vec3 color) {
  uint8_t out[3];
 
  out[0] = (uint8_t)(255.999 * color[0]);
  out[1] = (uint8_t)(255.999 * color[1]);
  out[2] = (uint8_t)(255.999 * color[2]);

  fwrite(out, 3, 1, file);
}

RAYS_EXPORT
void
rays_write_v3(uint8_t * __restrict * __restrict file, vec3 color) {
  uint8_t *p;
  p = *file;
  
  *p++ = (uint8_t)(255.999 * color[0]);
  *p++ = (uint8_t)(255.999 * color[1]);
  *p++ = (uint8_t)(255.999 * color[2]);
}
