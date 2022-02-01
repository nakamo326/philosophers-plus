#include "Philosopher.hpp"

Philosopher::Philosopher(int index, Info &info)
    : index_(index), info_(info), times_of_finished_meal_(0) {
  int i = index - 1;
  left_ = &info.forks[i];
  right_ = &info.forks[(i + info.philo_num - 1) % info.philo_num];
}

millisec Philosopher::outputLog(const char *str) {
  millisec time;

  time = getTime();
  if (!info_.isDead() && !info_.isFullfilled()) {
    info_.print.lock();
    printf("%ld %d%s\n", time, index_, str);
    info_.print.unlock();
  }
  return (time);
}

void Philosopher::setLastmealTime(millisec time) {
  access_to_last_meal_.lock();
  last_meal_time_ = time;
  access_to_last_meal_.unlock();
}

millisec Philosopher::readLastmealTime() {
  millisec time;
  access_to_last_meal_.lock();
  time = last_meal_time_;
  access_to_last_meal_.unlock();
  return time;
}

void Philosopher::shakeForks() {
  if (index_ % 2 == 1) {
    right_->lock();
    outputLog(TAKEN_FORK);
    left_->lock();
    outputLog(TAKEN_FORK);
  } else {
    left_->lock();
    outputLog(TAKEN_FORK);
    right_->lock();
    outputLog(TAKEN_FORK);
  }
}

void Philosopher::releaseForks() {
  right_->unlock();
  left_->unlock();
}

void Philosopher::eatMeal() {
  setLastmealTime(outputLog(EATING));
  myUsleep(info_.time_eat);
  times_of_finished_meal_++;
  if (times_of_finished_meal_ == info_.limit_times) {
    info_.print.lock();
    info_.fullfill_num++;
    info_.print.unlock();
  }
}

void Philosopher::sleepWell() {
  outputLog(SLEEPING);
  myUsleep(info_.time_sleep);
}

void Philosopher::think() {
  outputLog(THINKING);
  if (info_.is_odd && index_ % 2 == 1)
    myUsleep(10);
}
