//
//  Barrier.h
//  KR3
//
//  Created by Nikita-Mac on 09.05.17.
//  Copyright © 2017 Nikita-Mac. All rights reserved.
//

#ifndef Barrier_h
#define Barrier_h

#include <pthread.h>
#include <errno.h>

typedef int pthread_barrierattr_t;

typedef struct
{
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    int count;
    int tripCount;
} pthread_barrier_t;

int pthread_barrier_init(pthread_barrier_t *barrier, const pthread_barrierattr_t *attr, unsigned int coun);

int pthread_barrier_destroy(pthread_barrier_t *barrier);

int pthread_barrier_wait(pthread_barrier_t *barrier);

#endif /* Barrier_h */
