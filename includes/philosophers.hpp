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

#include "Philosopher.hpp"

using millisec = long;

void philo_routine(Philosopher &philo);
void doctor_routine(Philosopher &philo);

#endif /* PHILOSOPHERS_PLUS_INCLUDES_PHILOSOPHERS */
