//
// Created by fisher on 2022/12/22.
//

#ifndef HTTPSERVER_CHANNEL_MAP_H
#define HTTPSERVER_CHANNEL_MAP_H

struct channel_map {
    void ** entries;

    int nentries;

};
int map_make_space(struct *struct channel_map,int slot,int msize);

void map_init(struct channel_map *map);

void map_clear(struct channel_map *map);

#endif //HTTPSERVER_CHANNEL_MAP_H
