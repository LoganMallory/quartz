#include "../main/Queue.h"

void test_Queue_DefaultConstructor() {
  if(LOG_LEVEL <= DEBUG) printf("\ttest_Queue_DefaultConstructor\n");

  Queue queue;
  assert(queue.get_size() == 0);
  assert(queue.get_quantity() == 0);
  assert(queue.start_index == 0);
  assert(queue.next_index == 0);
}

void test_Queue_EnqueueOrder() {
  if(LOG_LEVEL <= DEBUG) printf("\ttest_Queue_EnqueueOrder\n");

  Queue queue;
  unsigned int p = rand();
  unsigned int q = rand();
  unsigned int s = rand();

  Order order(p, q, s);

  queue.enqueue_order(order);

  assert(order.get_index() == 0);

  assert(queue.get_size() == 1);
  assert(queue.get_quantity() == q);
  assert(queue.start_index == 0);
  assert(queue.next_index == 1);
  assert(queue.orders[0].get_price() == (p & LOWER_23_BITS));
  assert(queue.orders[0].get_quantity() == q);
  assert(queue.orders[0].get_side() == (s & 1));
}

void test_Queue_EnqueueOrder_ValueCopy() {
  if(LOG_LEVEL <= DEBUG) printf("\ttest_Queue_EnqueueOrder_ValueCopy\n");

  Queue queue;
  unsigned int p = rand();
  unsigned int q = rand();
  unsigned int s = rand();

  Order order(p, q, s);

  queue.enqueue_order(order);

  order.set_price(rand());
  order.set_quantity(rand());
  order.set_side(rand());

  assert(queue.orders[0].get_price() == (p & LOWER_23_BITS));
  assert(queue.orders[0].get_quantity() == q);
  assert(queue.orders[0].get_side() == (s & 1));
}

void test_Queue_RemoveOrderByIndex_First() {
  if(LOG_LEVEL <= DEBUG) printf("\ttest_Queue_RemoveOrderByIndex_First\n");

  Queue queue;
  Order order1(rand(), rand(), rand());
  Order order2(rand(), rand(), rand());
  Order order3(rand(), rand(), rand());

  queue.enqueue_order(order1);
  queue.remove_order_by_index(0);

  assert(queue.get_quantity() == 0);
  assert(queue.get_size() == 0);
  assert(queue.start_index == 0);
  assert(queue.next_index == 0);
  assert(queue.orders[0].get_quantity() == 0);

  queue.enqueue_order(order2);
  queue.enqueue_order(order3);

  assert(queue.get_quantity() != 0);
  assert(queue.get_size() == 2);
  assert(queue.start_index == 0);
  assert(queue.next_index == 2);
}


void test_Queue_GetOrderByIndex() {

}

void test_Queue_Clear() {

}

void test_Queue() {
  test_Queue_DefaultConstructor();
  test_Queue_EnqueueOrder();
  test_Queue_EnqueueOrder_ValueCopy();
  test_Queue_RemoveOrderByIndex_First();
  test_Queue_GetOrderByIndex();
  test_Queue_Clear();
}
