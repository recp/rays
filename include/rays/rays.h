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

#ifndef rays_rays_h
#define rays_rays_h

#include "common.h"
#include "assets.h"

typedef struct ray_t {
  vec3  pos; /* origin                                        */
  vec3  dir; /* direction (normalized)                        */
  float min; /* distance at which intersection testing starts */
  float max; /* distance at which intersection testing ends   */
} ray_t;

/*
 ray function 𝐏(𝑡)=𝐀+𝑡𝐛
 */
RAYS_INLINE
void
rays_ray_at(ray_t * __restrict ray, float t, vec3 point) {
  vec3 dst;
  glm_vec3_scale(ray->dir, t, dst);
  glm_vec3_add(ray->pos, dst, point);
}

RAYS_EXPORT
void
rays_render_start(const char * __restrict outpath/* TODO: params (take object, options)... */);

#endif /* rays_rays_h */
