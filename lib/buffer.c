//
// Created by fisher on 2022/12/22.
//
#define _GNU_SOURCE
#include "buffer.h"
#include "common.h"
#include <string.h>
const char *CRLF = "\r\n";

struct buffer *buffer_new() {
    struct buffer *buffer1 = (struct buffer*)malloc(sizeof(struct buffer));
    if (!buffer1) {
        return NULL;
    }
    buffer1->data = (char*)malloc(INIT_BUFFER_SIZE);
    buffer1->readIndex = 0;
    buffer1->writeIndex = 0;
    buffer1->total_size = INIT_BUFFER_SIZE;
    return buffer1;
}

void buffer_size(struct buffer *buffer1) {
    free(buffer1->data);
    free(buffer1);
}

int buffer_writeable_size(struct buffer *buffer) {
    return buffer->total_size - buffer->writeIndex;
}

int buffer_readable_size(struct buffer *buffer) {
    return buffer->writeIndex - buffer->readIndex;
}

int buffer_front_spare_size(struct buffer *buffer) {
    return buffer->readIndex;
}
// 提前申请一块空间
/*先判断当前大小是否足够，如果足够则无需继续，直接返回即可
     * 如果前面被读走的空余空间加还未写入的空间足够的话，无需重新申请内存，
     * 直接在当前的基础上将readIndex前移，凑出完整的空间
     * 如果当前空间不够，则重新申请一块空间
     * * */
void make_room(struct buffer *buffer, int size) {

    if (buffer_writeable_size(buffer) > size) {
        return;
    }
    if (buffer_front_spare_size(buffer) + buffer_writeable_size(buffer) > size) {
        int readable = buffer_readable_size(buffer);
        for (int i = 0; i < readable;i++) {
            memcpy(buffer->data + i,buffer->data + readable + i,1);
        }
        buffer->readIndex = 0;
        buffer->writeIndex = readable;
    } else {
        void *tmp = realloc(buffer->data,buffer->total_size + size);
        if (tmp = NULL) {
            return;
        }
        buffer->data = (char*)tmp;
        buffer->total_size += size;
    }
}
int buffer_append(struct buffer *buffer,void *data,int size) {
    if (data != NULL) {
        make_room(buffer,size);
        memcpy(buffer->data + buffer-> writeIndex,data,size);
        buffer->writeIndex +=size;
    }

}

int buffer_append_char(struct buffer *buffer,char data) {
    make_room(buffer,1);
    buffer->data[buffer->writeIndex++] = data;
}
int buffer_append_string(struct buffer *buffer,char *data) {
    if (data != NULL) {
        int size = strlen(data);
        buffer_append(buffer,data,size);
    }
}
// 从socket当中读数据写入到缓冲区当中
int buffer_socket_read(struct buffer *buffer,int fd) {
    char addtional_buffer[INIT_BUFFER_SIZE];
    struct iovec vec[2];
    int max_writable = buffer_writeable_size(buffer);
    vec[0].iov_base = buffer->data + buffer->writeIndex;
    vec[0].iov_len = max_writable;
    vec[1].iov_base = addtional_buffer;
    vec[1].iov_len = sizeof(addtional_buffer);
    int result = readv(fd,vec,2);
    if (result < 0) {
        return -1;
    } else if (result <= max_writable){
        buffer->writeIndex += result;
    } else {
        // writeIndex指向最后，后续的append还会继续将writeIndex指向正确的位置
        buffer->writeIndex = buffer->total_size;
        buffer_append(buffer,addtional_buffer,result - max_writable);
    }
    return result;
}
char buffer_read_char(struct buffer *buffer) {
    char c = buffer ->data[buffer->readIndex];
    buffer->readIndex++;
    return c;
}
char *buffer_find_CRLF(struct buffer *buffer) {
    char *crlf = (char*)memmem(buffer->data + buffer->readIndex, buffer_readable_size(buffer),CRLF,2);
    return crlf;
}