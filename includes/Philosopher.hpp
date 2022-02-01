#ifndef PHILOSOPHERS_PLUS_INCLUDES_PHILOSOPHER
#define PHILOSOPHERS_PLUS_INCLUDES_PHILOSOPHER

#include "philosophers.hpp"

class Philosopher {
  public:
  Info *info_;
  int index_;

  private:
  std::mutex *left_;
  std::mutex *right_;
  std::mutex access_to_last_meal_;
  millisec last_meal_time_;
  int times_of_finished_meal_;

  public:
  Philosopher();
  Philosopher(int index, Info *info);
  ~Philosopher() {}

  millisec outputLog(const char *str);
  void setLastmealTime(millisec time);
  millisec readLastmealTime();

  // actions
  void shakeForks();
  void eatMeal();
  void releaseForks();
  void sleepWell();
  void think();
};

#endif /* PHILOSOPHERS_PLUS_INCLUDES_PHILOSOPHER */
