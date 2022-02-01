#ifndef PHILOSOPHERS_PLUS_INCLUDES_PHILOSOPHER
#define PHILOSOPHERS_PLUS_INCLUDES_PHILOSOPHER

#include "Info.hpp"
#include "philosophers.hpp"

class Philosopher {
  public:
  Info &info_;

  private:
  int index_;
  std::mutex *left_;
  std::mutex *right_;
  std::mutex access_to_last_meal_;
  millisec last_meal_time_;
  size_t times_of_finished_meal_;

  private:
  millisec getTime();
  void myUsleep(millisec milliseconds);

  public:
  Philosopher();
  Philosopher(int index, Info &info);
  ~Philosopher();

  void addIndex(int index);
  millisec outputLog(const char *str);
};

#endif /* PHILOSOPHERS_PLUS_INCLUDES_PHILOSOPHER */
