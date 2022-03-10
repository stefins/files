#include<stdio.h>
#include<dirent.h>
#include<string.h>
#include<stdlib.h>

#include "utils.h"
#include "files.h"

int counter = 1;

File*
new_file(char* name, char* size,char* path,File* files){
    File file;
    file.name = malloc(strlen(name)+1);
    file.size = malloc(strlen(size)+1);
    file.path = malloc(strlen(path)+1);
    strcpy(file.name,name);
    strcpy(file.size,size);
    strcpy(file.path,path);
    files = realloc(files,sizeof(File)*counter);
    *(files + 1) = file;
    return files;
}

File* init()
{
    File* fils = malloc(sizeof(File));
    return fils;
}

int walk_dir(char* path ,int* total,File* files) 
{
    struct dirent *de;
    DIR *dr = opendir(path);
    if (dr == NULL)
    {
        printf("Could not open directory %s\n",path);
        return 0;
    }
    while ((de = readdir(dr)) != NULL){
        if (de->d_type == 4 ){
            if (!strcmp(de->d_name,".") || !strcmp(de->d_name,"..")){
                continue;
            }
            char *currentpath = malloc(strlen(path) + strlen("/") + strlen(de->d_name)+1);
            strcpy(currentpath,path);
            strcat(currentpath,"/");;
            strcat(currentpath,de->d_name);
            int temp = 0;
            walk_dir(currentpath,&temp,files);
            free(currentpath);
        } else if (de->d_type == 8){
            counter++;
            char *currentfile = malloc(strlen(path) + strlen("/") + strlen(de->d_name)+1);
            strcpy(currentfile,path);
            strcat(currentfile,"/");;
            strcat(currentfile,de->d_name);
            FILE *fp;
            fp = fopen(currentfile, "r");
            fseek(fp, 0L, SEEK_END);
            int sz = ftell(fp);
            fclose(fp);
            File* temp_file = new_file(de->d_name,humanSize(sz),currentfile,files);
            // files = realloc(files,sizeof(File)*(1100));
            if (files == NULL){
                printf("Cannot realloc!!");
                exit(0);
            }
            printf("%d ",counter);
            //files[counter] = temp_file;
            //printf("Name: %s Size: %s \n",files[counter].name,files[counter].size);

        }
    }
    // for(int i=0;i<counter ;i++){
    //     printf("Name: %s Size: %s \n",files[i].name,files[i].size);
    // }
    closedir(dr); 
    *total = counter;
    return 0;
}