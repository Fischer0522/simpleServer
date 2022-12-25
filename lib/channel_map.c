//
// Created by fisher on 2022/12/23.
//
#include <assert.h>
#include <stdlib.h>
#include "channel_map.h"

/*对当前的map进行扩容
 * 如果当前的size < slot 才进行扩容
 * 初始化大小为 32，每次扩容为原来的两倍
 * 对新扩容的位置将其设置为0*/
int map_make_space(struct channel_map *map,int slot,int msize) {
    if (map->nentries <= slot) {
        // 默认大小为32
        int nentries = map->nentries ? map->nentries : 32;
        while (nentries <= slot) {
            nentries <<= 1;
        }
        void **temp = (void **) realloc(map->entries,nentries * msize);
        if (temp == NULL) {
            return (-1);
        }
        map->nentries = nentries;
        map->entries = temp;

    }
    return (0);

}

void map_init(struct channel_map *map) {
    map->nentries = 0;
    map->entries = NULL;
}
void map_clear(struct channel_map *map) {
    if (map->entries != NULL) {
        for (int i = 0;i < map->nentries;i++) {
            if (map->entries[i] != NULL) {
                free(map->entries[i]);
            }
        }
        free(map->entries);
        map->entries = NULL;
    }
    map->nentries = 0;
}