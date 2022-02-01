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

typedef enum e_arg_index {
  NUM_OF_PHILOS,
  TIME_TO_DIE,
  TIME_TO_EAT,
  TIME_TO_SLEEP,
  LIMIT_TIMES_TO_DIE,
} t_arg_index;

struct Info {
  int params[5];
  int fullfill_num;
  bool is_dead;
  bool is_odd;
  std::vector<std::mutex> forks;
  std::mutex print;

  Info(){};
  Info() {}
};

#endif /* PHILOSOPHERS_PLUS_INCLUDES_PHILOSOPHERS_HPP */
