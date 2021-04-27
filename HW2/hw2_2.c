#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>

int main() {
    DIR *dir_ptr;
    struct dirent *dir;
    char dir_type[] = {"[directory]"};
    char find[]={"."};
    if(( dir_ptr = opendir(find)) == NULL) {
        fprintf(stderr, "Cannot Open %s Directory.\n",find);
        return -1;
    }

    while((dir = readdir(dir_ptr))!=NULL) {
        if(dir->d_type == 4) {
            printf("%s %s\n", dir->d_name, dir_type);
        }
        else {
            printf("%s\n", dir->d_name);
        }
    }
    closedir(dir_ptr);
    return 0;
}
