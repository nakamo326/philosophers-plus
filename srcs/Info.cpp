#include "Info.hpp"

Info::Info(int argc, char **argv) {
  if (!(argc == 5 || argc == 6))
    throw std::length_error("arguments number is not valid.");

  std::vector<std::string> args(argv, argv + argc);
  philo_num = getNum(args[1]);
  time_die = getNum(args[2]);
  time_eat = getNum(args[3]);
  time_sleep = getNum(args[4]);
  limit_times = argc == 6 ? getNum(args[5]) : -1;
}

bool Info::isInvalidRange(long num) {
  return num <= 0 || num > std::numeric_limits<int>::max();
}

long Info::getNum(std::string &str) {
  long tmp = std::atoi(str.c_str());
  if (isInvalidRange(tmp))
    throw std::range_error("input num is not valid range.");
  return (tmp);
}

void Info::init() {}