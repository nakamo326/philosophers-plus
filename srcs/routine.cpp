#include "philosophers.hpp"

void philo_routine(Philosopher &philo, Info &info) {
  philo.setLastmealTime(getTime());

  if (info.philo_num == 1) {
    philo.outputLog(TAKEN_FORK);
    return;
  }
  if (philo.index_ % 2 == 0)
    myUsleep(1);
  while (!info.isDead() && !info.isFullfilled()) {
    philo.shakeForks();
    philo.eatMeal();
    philo.releaseForks();
    philo.sleepWell();
    philo.think();
  }
  return;
}

void doctor_routine(Philosopher &philo, Info &info) {
  long now;
  long lasttime;

  while (!info.isDead() && !info.isFullfilled()) {
    myUsleep(1000);
    info.print.lock();
    now = getTime();
    lasttime = philo.readLastmealTime();
    if (now - lasttime >= info.time_die && info.is_dead == false) {
      printf("%ld %d died\n", now, philo.index_);
      info.is_dead = true;
    }
    info.print.unlock();
  }
  return;
}
