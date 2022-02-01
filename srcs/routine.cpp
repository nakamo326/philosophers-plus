#include "Info.hpp"
#include "Philosopher.hpp"

void philo_routine(Philosopher *philo, Info *info) {
  philo->setLastmealTime(getTime());

  if (info->philo_num == 1) {
    philo->outputLog(TAKEN_FORK);
    return;
  }
  // if (philo->index_ % 2 == 0)
  //   myUsleep(1);
  while (!info->isDead() && !info->isFullfilled()) {
    philo->shakeForks();
    philo->eatMeal();
    philo->releaseForks();
    philo->sleepWell();
    philo->think();
  }
  return;
}

void doctor_routine(Philosopher *philo, Info *info) {
  long now;
  long lasttime;

  while (!info->isDead() && !info->isFullfilled()) {
    myUsleep(1);
    now = getTime();
    lasttime = philo->readLastmealTime();
    info->print.lock();
    if (now - lasttime >= info->time_die && !info->is_dead) {
      std::cout << now << " " << philo->index_ << " died" << std::endl;
      info->is_dead = true;
    }
    info->print.unlock();
  }
  return;
}
