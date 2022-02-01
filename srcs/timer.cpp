#include "philosophers.hpp"

millisec getTime() {
  struct timeval tp;

  gettimeofday(&tp, NULL);
  return tp.tv_sec * 1000 + tp.tv_usec / 1000;
}

void myUsleep(millisec milliseconds) {
  long start;

  start = getTime();
  while (getTime() - start < milliseconds) {
    std::this_thread::sleep_for(std::chrono::microseconds(1000));
  }
}
