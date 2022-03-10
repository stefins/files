typedef struct{
    char* name;
    char* size;
    char* path;
}File;

File* init();

int walk_dir(char*,int*,File*);
