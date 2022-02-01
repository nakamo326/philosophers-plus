#ifndef PHILOSOPHERS_PLUS_INCLUDES_PHILOSOPHER
#define PHILOSOPHERS_PLUS_INCLUDES_PHILOSOPHER

#include "philosophers.hpp"

class Philosopher {
  private:
  Info *info;
  int index;
  pthread_t th;
  pthread_t doctor;
  pthread_mutex_t *left;
  pthread_mutex_t *right;
  pthread_mutex_t *print;
  pthread_mutex_t access_to_last_meal;
  long last_meal_time;
  long times_of_finished_meal;

  public:
  Philosopher();
  ~Philosopher();
};

#endif /* PHILOSOPHERS_PLUS_INCLUDES_PHILOSOPHER */
