#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char* argv[]) {
    int fd;
    int size = 0;
    char buf[256];

    if(argc != 2) {
        printf("usage: %s <file>\n", argv[0]); // expects one argument as the file path
        exit(1);
    }

    struct stat stat_data;
    if (stat(argv[1], &stat_data) < 0) {  // to get information about this file
        fprintf(stderr, "Cannot be started %s: %s\n", argv[1], strerror(errno));
        exit(1);
    }

    if(stat_data.st_uid == 0) // checks the file you spcified, own by the root
    {
        fprintf(stderr, "File %s Permisson Denied!\nFile is a root file\n", argv[1]);
        exit(1);
    }

    fd = open(argv[1], O_RDONLY); // if it is not own by the root
    
    if(fd <= 0)
    {
        fprintf(stderr, "File cannot be open %s\n", argv[1]);
        exit(1);
    }

    do { // reading from the file and write to output
        size = read(fd, buf, 256);
        write(1, buf, size);
    } while(size>0); 
}