#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
int main(){
    int fd;
    char *str;
    int filesize=200*1024*1024;
    str = (char*)malloc(filesize);
    
    for(int i=0;i<filesize/sizeof(char);i++){
    	str[i]='0';
    }

    fd=open("file1.txt",O_CREAT | O_RDWR);
    write(fd,str,filesize/sizeof(char));
    close(fd);
    free(str);


    return 0;	
    
}

