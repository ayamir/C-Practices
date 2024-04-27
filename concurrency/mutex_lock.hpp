#include <pthread.h>
#include <sched.h>

#define NON_COPYABLE(T)   \
    T(const T&) = delete; \
    T& operator=(const T&) = delete;

class MutexLock {
   public:
    MutexLock() { pthread_mutex_init(&mutex_, NULL); }
    ~MutexLock() { pthread_mutex_destroy(&mutex_); }

    void lock() { pthread_mutex_lock(&mutex_); }
    void unlock() { pthread_mutex_unlock(&mutex_); }

   private:
    NON_COPYABLE(MutexLock);
    pthread_mutex_t mutex_;
};

class MutexLockGuard {
   public:
    MutexLockGuard(MutexLock& mutex) : mutex_(mutex) { mutex_.lock(); }
    ~MutexLockGuard() { mutex_.unlock(); }

   private:
    MutexLock& mutex_;
};
