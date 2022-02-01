#ifndef PHILOSOPHERS_PLUS_INCLUDES_PHILOSOPHERS_HPP
#define PHILOSOPHERS_PLUS_INCLUDES_PHILOSOPHERS_HPP

#define TAKEN_FORK " has taken a fork"
#define EATING " is eating"
#define SLEEPING " is sleeping"
#define THINKING " is thinking"

#include <sys/time.h>

#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

using millisec = long;

struct Info {
  int params[5];
  int philo_num;
  millisec time_die;
  millisec time_eat;
  millisec time_sleep;
  int limit_times;
  int fullfill_num;
  bool is_dead;
  bool is_odd;
  std::vector<std::mutex> forks;
  std::mutex print;

  Info() {}
  ~Info() {}

  Info(int argc, const char *argv);
};

#endif /* PHILOSOPHERS_PLUS_INCLUDES_PHILOSOPHERS_HPP */
