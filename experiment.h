#pragma once
#include <stdio.h>
#include <assert.h>

#define NAME_SIZE 255
typedef struct 
{
  int time; // en nombre de minutes depuis minuit
  char name[NAME_SIZE];
} experiment_t;

void afficheExperiment(experiment_t * e);
