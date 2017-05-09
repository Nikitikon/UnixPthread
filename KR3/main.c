//
//  main.c
//  KR3
//
//  Created by Nikita-Mac on 08.05.17.
//  Copyright © 2017 Nikita-Mac. All rights reserved.
//


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include "Barrier.h"


double _pi;
double _exp;

pthread_barrier_t our_barrier;

void* Pi(){
    
    pthread_barrier_wait(&our_barrier);
    double const Const = 2 * sqrt(3);
    double result = 0;
    for (int i = 0; i < 10000; i++) {
        double temp = pow(-1, i) / pow(3, i);
        temp /= 2 * i + 1;
        result += temp * Const;
    }
    _pi = result;
    pthread_exit(0);
}

void* Exp(void* point){
    pthread_barrier_wait(&our_barrier);
    int x = (int) point;
    double parameter = -(double)(x * x)/2;
    double result = 1;
    int n = 1;

    for (int i = 1; i < 20; i++) {
        n *= i;
        result += pow(parameter, i) / n;
    }
    _exp = result;
    pthread_exit(0);
}

double F(){
    return _exp / sqrt(2 * _pi);
}

int main(){
    
    int x = 1;
    int ret = 0;
    
    pthread_t threadPi;
    pthread_t threadExp;
    
    pthread_barrier_init(&our_barrier, NULL, 2);
    
    ret = pthread_create(&threadPi, NULL, Pi, NULL);
    if (ret != 0) {
        perror("Pi create: ");
    }
    ret = pthread_create(&threadExp, NULL, Exp, x);
    if (ret != 0) {
        perror("Exp create: ");
    }
    
    ret = pthread_join(threadPi, NULL);
    if (ret != 0) {
        perror("Pi join: ");
    }
    ret = pthread_join(threadExp, NULL);
    if (ret != 0) {
        perror("Exp join: ");
    }
    pthread_barrier_destroy(&our_barrier);
    printf("F(x) = %f\n", F());
    
    return 0;
}
