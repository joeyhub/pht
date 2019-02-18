#ifndef PHT_DEBUG_H
#define PHT_DEBUG_H

#if 0
# define pthread_mutex_lock(mut) \
    printf("A: %s (%s:%d)\n", #mut, __FILE__, __LINE__); \
    pthread_mutex_lock(mut);

# define pthread_mutex_unlock(mut) \
    printf("R: %s (%s:%d)\n", #mut, __FILE__, __LINE__); \
    pthread_mutex_unlock(mut);
#endif

#endif
