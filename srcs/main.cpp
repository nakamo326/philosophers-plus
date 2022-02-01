#include "Info.hpp"
#include "Philosopher.hpp"

int main(int argc, char **argv) {
  Info info(argc, argv);
  std::vector<Philosopher> philos;
  for (int i = 0; i < info.philo_num; i++) {
    philos.push_back(Philosopher(i + 1, info));
  }

  // start_sims(philos);
  // join_philos(philos);
  // return (exit_free(&info, philos, NULL));
}
