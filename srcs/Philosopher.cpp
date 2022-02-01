#include "Philosopher.hpp"

#include "Info.hpp"

Philosopher::Philosopher()
    : info_(nullptr), index_(0), left_(nullptr), right_(nullptr),
      times_of_finished_meal_(0) {}

Philosopher::Philosopher(int index, Info *info)
    : info_(info), index_(index), times_of_finished_meal_(0) {
  int i = index - 1;
  left_ = &info->forks[i];
  right_ = &info->forks[(i + info->philo_num - 1) % info->philo_num];
}

millisec Philosopher::outputLog(const char *str) {
  millisec time = getTime();
  if (!info_->isDead() && !info_->isFullfilled()) {
    info_->print.lock();
    std::cout << time << " " << index_ << str << std::endl;
    info_->print.unlock();
  }
  return time;
}

void Philosopher::setLastmealTime(millisec time) {
  info_->print.lock();
  last_meal_time_ = time;
  info_->print.unlock();
}

millisec Philosopher::readLastmealTime() {
  info_->print.lock();
  millisec time = last_meal_time_;
  info_->print.unlock();
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
  myUsleep(info_->time_eat);
  times_of_finished_meal_++;
  if (times_of_finished_meal_ == info_->limit_times) {
    info_->print.lock();
    info_->fullfill_num++;
    info_->print.unlock();
  }
}

void Philosopher::sleepWell() {
  outputLog(SLEEPING);
  myUsleep(info_->time_sleep);
}

void Philosopher::think() {
  outputLog(THINKING);
  if (info_->is_odd && index_ % 2 == 1)
    myUsleep(10);
}
