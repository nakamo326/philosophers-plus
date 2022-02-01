#ifndef PHILOSOPHERS_PLUS_INCLUDES_PHILOSOPHER
#define PHILOSOPHERS_PLUS_INCLUDES_PHILOSOPHER

#include "philosophers.hpp"

class Philosopher {
  public:
  using ms = long;

  private:
  Info *info;
  int index;
  pthread_t th;
  pthread_t doctor;
  std::mutex &left;
  std::mutex &right;
  std::mutex access_to_last_meal;
  ms last_meal_time;
  long times_of_finished_meal;

  private:
  ms getTime();
  void myUsleep(ms milliseconds);

  public:
  Philosopher();
  ~Philosopher();

  ms outputLog(const char *str);
};

#endif /* PHILOSOPHERS_PLUS_INCLUDES_PHILOSOPHER */
