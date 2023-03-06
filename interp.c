#include <fcntl.h>
#include <unistd.h>

int main(int argc, char** argv)
{
    int i, fd;

    fd = open(*argv, 0);
    close(fd);
    return 0;
}
