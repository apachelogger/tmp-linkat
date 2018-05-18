#define _GNU_SOURCE

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int fd = open("/tmp", O_RDWR|O_DIRECTORY|O_CLOEXEC|O_TMPFILE);

    char pro_fd[PATH_MAX];
    sprintf(pro_fd, "/proc/self/fd/%i", fd);

    printf("opened fd: %i [%s]\n", fd, pro_fd);

    ssize_t size = write(fd, "hello there", sizeof("hello there"));
    if (size < 0) {
        perror("write failed");
        return -1;
    }
    printf("writing works\n");

    int err = linkat(AT_FDCWD, pro_fd,
                     AT_FDCWD, "/tmp/okular_DHqFKd.ps",
                     AT_SYMLINK_FOLLOW);
    if (err != 0) {
        perror("linkat failed");
        return -1;
    }
    printf("linkat success\n");

    return 0;
}
