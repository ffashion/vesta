#include <pthread.h>
#include <stdio.h>
#include <errno.h>
// #include <threads.h>
void add(){

    printf("this is an new thread tid: %d\n",pthread_self());
    // printf("getid",)
    fflush(NULL);

}
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t dy_mutex;
pthread_mutexattr_t mutex_attr;
pthread_cond_t mutex_cond = PTHREAD_COND_INITIALIZER;
int i = 0;
//线程id
pthread_t worker[100];
int main(int argc, char const *argv[]){
    
    //-------------one--------
    // for (size_t i = 0; i <= 4 ;i++){   
    //     pthread_create(&worker[i],NULL,add,NULL); 
        
    // }

    // for (size_t i = 0; i <= 4; i++){
    //     //等待worker[i]表示的线程结束 此worker[i]线程必须时joinable的(当然默认就是)
    //     pthread_join(worker[i],NULL);
    // }

    //------------two-------------
    //设置线程终止自动清理 主线程退出 他还是会死亡
    // pthread_detach(worker[0]);


    //--------three-----------
    //判断tid 是否相等
    // pthread_equal(worker[0],worker[1]);

    
    //---------four--------------
    // pthread_mutex_lock(&mutex);
    // for(;i<=99;i++){
    //     pthread_create(&worker[i],NULL,main,NULL);
    //     printf("helloworld:%d\n",i);

    // }
    // pthread_mutex_unlock(&mutex);


    //----------five-------------
    /**
     * 初始化mutex 变量并设置属性
     * @return 
    */
//    //设置mutex属性之一: 互斥量类型(一共三种互斥量类型) 这里的类型为进行错误检查
    // pthread_mutexattr_settype(&mutex_attr,PTHREAD_MUTEX_ERRORCHECK);
    

    // pthread_mutex_init(&dy_mutex,&mutex_attr);

//     //销毁互斥量
    // pthread_mutex_destroy(&dy_mutex);

    //----------six-----------
    /**
     * 条件变量使用
     * 1. 条件变量 就是可以把所在线程睡眠 然后接受信号 再次醒来
    */
   //给指定的条件变量发送信号 因为这个信号而睡眠的线程 可能会被唤醒
   //这个信号指挥发送一次 如果当前没有因为这个信号而睡眠的线程 那么就啥也不做
    // pthread_cond_signal(&mutex_cond);

    //堵塞本线程直到收到此条件变量的通知
    //cond_wait 调用所做的事情:(1)解锁互斥量 (2)堵塞进程 (3)重新锁定mutex
    // pthread_mutex_lock(&mutex);
    // while(condition){
    //     pthread_cond_wait(&mutex_cond,&mutex);
    // }
    // //do something

    // pthread_mutex_unlock(&mutex);

    //
    // pthread_cleanup_push(main,NULL);
    // pthread_cleanup_pop(0);

    
    



    return 0;
}
