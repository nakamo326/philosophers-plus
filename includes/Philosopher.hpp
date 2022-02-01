#ifndef PHILOSOPHERS_PLUS_INCLUDES_PHILOSOPHER
#define PHILOSOPHERS_PLUS_INCLUDES_PHILOSOPHER

#include "Info.hpp"
#include "philosophers.hpp"

class Philosopher {
  private:
  Info &info;
  int index;
  std::thread th;
  std::thread doctor;
  std::mutex &left;
  std::mutex &right;
  std::mutex access_to_last_meal;
  millisec last_meal_time;
  size_t times_of_finished_meal;

  private:
  millisec getTime();
  void myUsleep(millisec milliseconds);

  public:
  Philosopher();
  ~Philosopher();

  millisec outputLog(const char *str);
};

#endif /* PHILOSOPHERS_PLUS_INCLUDES_PHILOSOPHER */
