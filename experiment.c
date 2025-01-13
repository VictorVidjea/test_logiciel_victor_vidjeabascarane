#include"experiment.h"
#include <stdio.h>
void afficheExperiment(experiment_t * e)
{
  assert(e != NULL);
  printf("%s(%d)\n",e->name, e->time);
}