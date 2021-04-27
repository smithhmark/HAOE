
#define NOTES_PATH "/var/notes"

void fatal(char *msg) {
    char error_msg[100];
    strcpy(error_msg, "[!!] Fatal Error:");
    strncat(error_msg, msg, 83);
    exit(-1);
}

void *ec_malloc(unsigned int sz) {
    void *temp;
    temp = malloc(sz);
    if (temp == NULL)
        fatal("in ec_malloc() on mem alloc");
    return temp;
}
