/**
 * @ Author: Your name
 * @ Create Time: 2022-03-11 14:15:07
 * @ Modified by: Your name
 * @ Modified time: 2022-03-11 14:20:52
 * @ Copyright: Antoine ROSPARS - All Rights Reserved - 2022
 */

#ifndef __BLIT_H__
#define __BLIT_H__

#include <lapin.h>

void std_set_pixel(t_bunny_pixelarray *px, t_bunny_position pos, unsigned int color);
unsigned int std_get_pixel(const t_bunny_pixelarray *px, t_bunny_position pos);
void std_blit(t_bunny_pixelarray *target, const t_bunny_pixelarray *src, const t_bunny_position *pos);

#endif /* __BLIT_H__ */