#include <sys/inotify.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
int main(int argc, char const *argv[])
{
    int inotify_fd  = inotify_init();
    
    // fcntl(inotify_fd,F_SETFL,O_NONBLOCK);
    inotify_add_watch(inotify_fd,"./",IN_CREATE);
    int buf[100];
    
    //count 指定最多读取的字节数
    
    read(inotify_fd,(void *)buf,100);
    // while(1){
    //     read(inotify_fd,(void *)buf,100);
    // }
    // ((struct inotify_envet *)buf)
    // printf("%s",)

    return 0;
}
