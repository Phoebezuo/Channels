#ifndef SRC_CHANNEL_H
#define SRC_CHANNEL_H

#include <stdlib.h>
#include <stdio.h> 
#include <unistd.h> 

struct sender {
    size_t msg_sz;
    int sender_fd; 
}; 

struct receiver {
    size_t msg_sz;
    int receiver_fd; 
}; 

void channel_init(struct receiver* recv, struct sender* sender, size_t msg_sz);

void channel_get(struct receiver* channel, void* data);

void channel_send(struct sender* channel, void* data);

void sender_dup(struct sender* dest, struct sender* src);

void channel_destroy(struct receiver* recv, struct sender* sender);

#endif
