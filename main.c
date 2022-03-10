#include<stdio.h>
#include<stdlib.h>

#include "files.h"

int
main (int argc, char **argv)
{
    if (argc != 2) {
        printf("Invalid Usage\n");
        printf("try: files folder_name\n");
        return 1;
    }
    int counter;
    File* files = init();
    walk_dir(argv[1],&counter,files);
    //printf("%d Total Files",counter);
    // for(int i=0;i<=counter ;i++){
    //     printf("Name: %s Size: %s \n",files[i].name,files[i].size);
    // }
    return  0;
}
