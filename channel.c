#include "channel.h"

void channel_init(struct receiver* recv, struct sender* sender, size_t msg_sz) { 
    if (!recv || !sender) { return; }

    // rece and sender have same size 
    recv->msg_sz = msg_sz;
    sender->msg_sz = msg_sz;

    // file descriptor on stack 
    int fd[2] = {-1}; 
    int ret = pipe(fd);
    if (ret != 0 ) { 
        puts("cannot pipe"); 
        return; 
    }

    recv->receiver_fd = fd[0]; // read end 
    sender->sender_fd = fd[1]; // write end 
}

void channel_get(struct receiver* channel, void* data) { 
    if (!channel) { return; }

    // retrieve data exists in channel
    ssize_t nread = read(channel->receiver_fd, data, channel->msg_sz); 

    if (nread == -1) { 
        // perror("read pipe failed");
        return; 
    }

    return;
}

void channel_send(struct sender* channel, void* data) {  
    if (!data || !channel) { return; }

    // send data to receiver
    ssize_t nwritten = write(channel->sender_fd, data, channel->msg_sz); 

    if (nwritten == -1) { 
        puts("written pipe failed"); 
        return; 
    }

    return; 
}

void sender_dup(struct sender* dest, struct sender* src) {
    if (!dest || !src) { return; }

    // duplicate all fields relsted to sender and return a copy 
    dest->msg_sz = src->msg_sz;
    dest->sender_fd = src->sender_fd;

}

void channel_destroy(struct receiver* recv, struct sender* sender) { 
    if (!recv || !sender) { return; }
	
    // close pipe
    close(recv->receiver_fd);
    close(sender->sender_fd);
}

