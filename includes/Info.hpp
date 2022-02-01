#ifndef PHILOSOPHERS_PLUS_INCLUDES_INFO
#define PHILOSOPHERS_PLUS_INCLUDES_INFO

#include "philosophers.hpp"

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

  Info(int argc, char **argv);

  void init();

  private:
  bool isInvalidRange(long num);
  long getNum(std::string &str);
};

#endif /* PHILOSOPHERS_PLUS_INCLUDES_INFO */
