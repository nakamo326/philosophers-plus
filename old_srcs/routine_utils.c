#include "philosophers.h"

bool	is_dead(t_philo *p)
{
	bool	ret;

	pthread_mutex_lock(&p->info->print);
	ret = p->info->is_dead;
	pthread_mutex_unlock(&p->info->print);
	return (ret);
}

bool	is_fullfilled(t_philo *p)
{
	bool	ret;

	pthread_mutex_lock(&p->info->print);
	ret = (p->info->fullfill_num == p->info->params[NUM_OF_PHILOS]);
	pthread_mutex_unlock(&p->info->print);
	return (ret);
}
