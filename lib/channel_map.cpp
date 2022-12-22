//
// Created by fisher on 2022/12/23.
//
#include <assert.h>
#include <cstdlib>
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
        if (temp == nullptr) {
            return (-1);
        }
        map->nentries = nentries;
        map->entries = temp;

    }
    return (0);

}

void map_init(struct channel_map *map) {
    map->nentries = 0;
    map->entries = nullptr;
}
void map_clear(struct channel_map *map) {
    if (map->entries != nullptr) {
        for (int i = 0;i < map->nentries;i++) {
            if (map->entries[i] != nullptr) {
                free(map->entries[i]);
            }
        }
        free(map->entries);
        map->entries = nullptr;
    }
    map->nentries = 0;
}