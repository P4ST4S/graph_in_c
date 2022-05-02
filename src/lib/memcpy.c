/**
 * @file memcpy.c
 * @author Antoine ROSPARS (antoine.rospars@ecole-89.com)
 * @brief implementation of memcpy by me
 * @version 0.1
 * @date 02-05-2022
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "memcpy.h"

void std_memcpy(void *dest, void *src, size_t n)
{
    size_t loop;
    char *chain_src;
    char *chain_dest;

    loop = 0;
    chain_src = (char *)src;
    chain_dest = (char *)dest;
    while (loop < n)
    {
        chain_dest[loop] = chain_src[loop];
        loop++;
    }
}