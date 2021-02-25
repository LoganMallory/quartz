#ifndef PAGE_H
#define PAGE_H
#include <cstdio>
#include "Queue.h"
static const unsigned int N_PRICE_LEVELS = 64;

class Page {
public:
  Queue queues[N_PRICE_LEVELS];
  unsigned int best_index;
  unsigned int depth;

  Page();


};

#include "Queue.cc"
#endif
