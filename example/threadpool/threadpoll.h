#ifndef __THREADPOLL_H__
#define __THREADPOLL_H__

#ifdef __cplusplus
extern "C"
{
#endif


typedef void * THREAD_POLL;

typedef void * (*TASK_NAME)(void *);

THREAD_POLL threadpoll_create(int min_thread_num, int max_thread_num, int max_task_queue_size);

int threadpoll_add_task(THREAD_POLL poll, TASK_NAME task_name, void *task_param);

int threadpoll_destroy(THREAD_POLL poll);

#define TIMER_DEFAULT           (10 * 1000) /*microseconds*/

#ifdef WIN32
static int gettimeofday(struct timeval *tp, void *tzp)
{
	time_t clock;
	struct tm tm;
	SYSTEMTIME wtm;
	GetLocalTime(&wtm);
	tm.tm_year = wtm.wYear - 1900;
	tm.tm_mon = wtm.wMonth - 1;
	tm.tm_mday = wtm.wDay;
	tm.tm_hour = wtm.wHour;
	tm.tm_min = wtm.wMinute;
	tm.tm_sec = wtm.wSecond;
	tm.tm_isdst = -1;
	clock = mktime(&tm);
	#ifdef WIN32
	tp->tv_sec = clock & 0xffffffff;//time_t/__int64(64bit) -> long(32bit)
	#else
	tp->tv_sec = clock;
	#endif
	tp->tv_usec = wtm.wMilliseconds * 1000;
	return (0);
}
#endif

typedef struct
{
    TASK_NAME task_name;
    void *task_param;
}threadpoll_task_t;

typedef struct
{
    int poll_state; //1,enable 0,disable

    /*describe the number of work thread*/
    int min_thread_num;
    int max_thread_num;
    int live_thread_num;
    int busy_thread_num;
    int wait_exit_thread_num;

    /*describe the task queue*/
    int max_task_queue_size;
    int task_queue_size;
    int task_queue_front;
    int task_queue_rear;
	threadpoll_task_t * task_queue;
    pthread_cond_t task_queue_not_full;
    pthread_cond_t task_queue_not_empty;

    pthread_t * work_tids;//set all work thread detached
    pthread_attr_t thr_attr;//detached

    pthread_t adjust_tid;//set adjust thread joinable

    pthread_mutex_t poll_lock;
	pthread_cond_t poll_not_enable;
	pthread_cond_t alive_thread_empty;

}threadpoll_t;

#ifdef __cplusplus
}
#endif

#endif