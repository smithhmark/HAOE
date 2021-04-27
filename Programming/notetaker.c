#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#include "hacking.h"

#define SEP "\n"

void usage(char *prog_name, char *filename) {
    printf("usage: %s <data to add to %s>\n", prog_name, filename);
    exit(0);
}

void fatal(char *);
void *ec_malloc(unsigned int);

int main(int argc, char *argv[]) {
    int userid, fd;
    char *buffer, *datafile;

    buffer = (char *) ec_malloc(100);
    datafile = (char *) ec_malloc(20);
    strcpy(datafile, "/tmp/notes");

    if (argc < 2) 
        usage(argv[0], datafile);
    strcpy(buffer, argv[1]);

    printf("[DEBUG] buffer   @ %p: \'%s\'\n", buffer, buffer);
    printf("[DEBUG] datafile @ %p: \'%s\'\n", datafile, datafile);

    strncat(buffer, "\n", 1);

    fd = open(datafile, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    if (fd == -1)
        fatal("in main() while opening file");
    printf("[DEBUG] file descriptor is %d\n", fd);

    userid = getuid(); //get real user id

    if ( write(fd, &userid, 4 ) == -1 )
        fatal("in main() while writing uid to file");
    write(fd, SEP, 1);
    if ( write(fd, buffer, strlen(buffer) ) == -1 )
        fatal("in main() while writing note to file");
    write(fd, SEP, 1);
    if ( close(fd) == -1 )
        fatal("in main() while closing file");
    printf("Note has been saved\n");
    free(buffer);
    free(datafile);
}
