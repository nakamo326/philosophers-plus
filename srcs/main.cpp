#include "Info.hpp"
#include "Philosopher.hpp"
#include "philosophers.hpp"

void sims(std::vector<Philosopher> &philos, Info &info) {
  std::vector<std::thread> philo_threads;
  std::vector<std::thread> doctor_threads;
  int num = philos[0].info_->philo_num;

  for (int i = 0; i < num; i++) {
    philo_threads.push_back(std::thread(philo_routine, &philos[i], &info));
    doctor_threads.push_back(std::thread(doctor_routine, &philos[i], &info));
  }
  for (int i = 0; i < num; i++) {
    philo_threads[i].join();
    doctor_threads[i].join();
  }
}

int main(int argc, char **argv) {
  Info info(argc, argv);
  std::vector<Philosopher> philos;
  for (int i = 0; i < info.philo_num; i++) {
    philos.push_back(Philosopher(i + 1, &info));
  }

  sims(philos, info);
  return 0;
}
