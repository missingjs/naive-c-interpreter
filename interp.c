#include <stdio.h>
#include <stdlib.h>

#include <fcntl.h>
#include <unistd.h>

int token;
char *src, *old_src;
int poolsize;
int line;

void next() {
    token = *src++;
}

void expression(int level) {
}

void program() {
    next();
    while (token > 0) {
        if (token == ' ') {
            printf("token is SPACE\n");
        } else if (token == '\n') {
            printf("token is LF\n");
        } else {
            printf("token is: %c\n", token);
        }
        next();
    }
}

int eval() {
    return 0;
}

int main(int argc, char** argv)
{
    int i, fd;

    --argc;
    ++argv;

    poolsize = 256 * 1024;
    line = 1;

    if ((fd = open(*argv, 0)) < 0) {
        printf("could not open(%s)\n", *argv);
        return -1;
    }

    if (!(src = old_src = malloc(poolsize))) {
        printf("could not malloc(%d) for source area\n", poolsize);
        return -1;
    }

    if ((i = read(fd, src, poolsize-1)) <= 0) {
        printf("read() return %d\n", i);
        return -1;
    }
    src[i] = 0;
    close(fd);

    program();

    return eval();
}
