#include "Philosopher.hpp"

Philosopher::Philosopher(int index, Info &info)
    : index_(index), info_(info), times_of_finished_meal_(0) {
  int i = index - 1;
  left_ = &info.forks[i];
  right_ = &info.forks[(i + info.philo_num - 1) % info.philo_num];
}

millisec Philosopher::outputLog(const char *str) {
  millisec time;

  // time = getTime();
  // if (!is_dead(p) && !is_fullfilled(p)) {
  //   pthread_mutex_lock(&p->info->print);
  //   printf("%ld %d%s\n", time, p->index, str);
  //   pthread_mutex_unlock(&p->info->print);
  // }
  return (time);
}

void Philosopher::update_lastmeal_time(millisec time) {
  access_to_last_meal_.lock();
  last_meal_time_ = time;
  access_to_last_meal_.unlock();
}
