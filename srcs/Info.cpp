#include "Info.hpp"

Info::Info(int argc, char **argv) : is_dead(false) {
  if (!(argc == 5 || argc == 6))
    throw std::length_error("arguments number is not valid.");

  std::vector<std::string> args(argv, argv + argc);
  philo_num = getNum(args[1]);
  time_die = getNum(args[2]);
  time_eat = getNum(args[3]);
  time_sleep = getNum(args[4]);
  limit_times = argc == 6 ? getNum(args[5]) : -1;

  if (philo_num % 2 == 1)
    is_odd = true;
  // forks.reserve(philo_num);
  forks = new std::mutex[philo_num];
}

bool Info::isInvalidRange(long num) {
  return num <= 0 || num > std::numeric_limits<int>::max();
}

long Info::getNum(std::string &str) {
  long tmp = std::atoi(str.c_str());
  if (isInvalidRange(tmp))
    throw std::range_error("input num is not valid range.");
  return tmp;
}

bool Info::isDead() {
  bool ret;

  print.lock();
  ret = is_dead;
  print.unlock();
  return ret;
}

bool Info::isFullfilled() {
  bool ret;

  print.lock();
  ret = (fullfill_num == philo_num);
  print.unlock();
  return ret;
}