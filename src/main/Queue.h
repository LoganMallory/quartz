#ifndef QUEUE_H
#define QUEUE_H
#include <cstdio>
#include "Order.h"
static const unsigned int QUEUE_SIZE = 256;

class Queue {
public:
  Order orders[QUEUE_SIZE];
  unsigned int quantity;
  unsigned short size;
  unsigned char start_index;
  unsigned char next_index;

  Queue();

  unsigned short get_size() const;
  unsigned int get_quantity() const;

  void enqueue_order(Order& order);
  void remove_order_by_index(const unsigned char& index);
  Order& get_order_by_index(const unsigned char& index);

  bool is_full() const;
  void clear();

private:
  void reset_indices();
  void trim_indices();
};

#include "Queue.cc"
#endif
