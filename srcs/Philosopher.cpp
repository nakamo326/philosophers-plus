#include "Philosopher.hpp"

Philosopher::Philosopher() {}

Philosopher::~Philosopher() {}

millisec Philosopher::outputLog(const char *str) {
  millisec time;

  time = getTime();
  if (!is_dead(p) && !is_fullfilled(p)) {
    pthread_mutex_lock(&p->info->print);
    printf("%ld %d%s\n", time, p->index, str);
    pthread_mutex_unlock(&p->info->print);
  }
  return (time);
}