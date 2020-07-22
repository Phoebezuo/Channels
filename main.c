#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "channel.h"

#define MSG_SZ (100)

int main() {
    struct sender* s = malloc(sizeof(struct sender));
    struct receiver* r = malloc(sizeof(struct receiver));
    char data[20];
	ssize_t nread = read(0, data, 20);
	data[nread] = '\0';

    channel_init(r, s, strlen(data));

    channel_send(s, data);

    channel_get(r, data);
    printf("%s", data);

    return 0;
}
