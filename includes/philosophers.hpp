#ifndef PHILOSOPHERS_PLUS_INCLUDES_PHILOSOPHERS
#define PHILOSOPHERS_PLUS_INCLUDES_PHILOSOPHERS

#define TAKEN_FORK " has taken a fork"
#define EATING " is eating"
#define SLEEPING " is sleeping"
#define THINKING " is thinking"

#include <sys/time.h>

#include <iostream>
#include <limits>
#include <mutex>
#include <thread>
#include <vector>

class Philosopher;
struct Info;

using millisec = long;

millisec getTime();
void myUsleep(millisec milliseconds);

void philo_routine(Philosopher *philo, Info *info);
void doctor_routine(Philosopher *philo, Info *info);

#endif /* PHILOSOPHERS_PLUS_INCLUDES_PHILOSOPHERS */
