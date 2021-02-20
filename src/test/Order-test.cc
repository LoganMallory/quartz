#include "../main/Order.h"

void test_Order_DefaultConstructor() {
  if(LOG_LEVEL <= DEBUG) printf("\ttest_Order_DefaultConstructor\n");

  Order order;
  assert(order.get_id() == 0);
  assert(order.get_index() == 0);
  assert(order.get_price() == 0);
  assert(order.get_side() == 0);
  assert(order.get_quantity() == 0);
}

void test_Order_ParameterizedConstructor() {
  if(LOG_LEVEL <= DEBUG) printf("\ttest_Order_ParameterizedConstructor\n");

  unsigned int p = rand();
  unsigned int q = rand();
  unsigned int s = rand();

  Order order(p, q, s);

  assert(order.get_index() == 0);
  assert(order.get_price() == (p & LOWER_23_BITS));
  assert(order.get_side() == (s & 1));
  assert(order.get_quantity() == q);
}

void test_Order_Constructor_PassByReference() {
  if(LOG_LEVEL <= DEBUG) printf("\ttest_Order_Constructor_PassByReference\n");

  unsigned int p = rand();
  unsigned int q = rand();
  unsigned int s = rand();

  Order order(p, q, s);

  unsigned int p_copy = p;
  unsigned int q_copy = q;
  unsigned int s_copy = s;

  p = rand();
  q = rand();
  s = rand();

  assert(order.get_index() == 0);
  assert(order.get_price() == (p_copy & LOWER_23_BITS));
  assert(order.get_side() == (s_copy & 1));
  assert(order.get_quantity() == q_copy);
}

void test_Order_SetIndex() {
  if(LOG_LEVEL <= DEBUG) printf("\ttest_Order_SetIndex\n");

  Order order1;
  unsigned int i = rand();
  order1.set_index(i);

  assert(order1.get_index() == (i & LOWER_8_BITS));
  assert(order1.get_price() == 0);
  assert(order1.get_side() == 0);
  assert(order1.get_quantity() == 0);

  unsigned int p = rand();
  unsigned int q = rand();
  unsigned int s = rand();
  Order order2(p, q, s);
  order2.set_index(i);

  assert(order2.get_index() == (i & LOWER_8_BITS));
  assert(order2.get_price() == (p & LOWER_23_BITS));
  assert(order2.get_side() == (s & 1));
  assert(order2.get_quantity() == q);
}


void test_Order_SetPrice() {
  if(LOG_LEVEL <= DEBUG) printf("\ttest_Order_SetPrice\n");

  Order order1;
  unsigned int p = rand();
  order1.set_price(p);

  assert(order1.get_index() == 0);
  assert(order1.get_price() == (p & LOWER_23_BITS));
  assert(order1.get_side() == 0);
  assert(order1.get_quantity() == 0);

  unsigned int p2 = rand();
  unsigned int q  = rand();
  unsigned int s  = rand();
  Order order2(p, q, s);
  order2.set_price(p2);

  assert(order2.get_index() == 0);
  assert(order2.get_price() == (p2 & LOWER_23_BITS));
  assert(order2.get_side() == (s & 1));
  assert(order2.get_quantity() == q);
}

void test_Order_SetSide() {
  if(LOG_LEVEL <= DEBUG) printf("\ttest_Order_SetSide\n");

  Order order1;
  unsigned int s = rand();
  order1.set_side(s);

  assert(order1.get_index() == 0);
  assert(order1.get_price() == 0);
  assert(order1.get_side() == (s & 1));
  assert(order1.get_quantity() == 0);

  unsigned int p  = rand();
  unsigned int q  = rand();
  unsigned int s2 = rand();
  Order order2(p, q, s);
  order2.set_side(s2);

  assert(order2.get_index() == 0);
  assert(order2.get_price() == (p & LOWER_23_BITS));
  assert(order2.get_side() == (s2 & 1));
  assert(order2.get_quantity() == q);
}

void test_Order_SetQuantity() {
  if(LOG_LEVEL <= DEBUG) printf("\ttest_Order_SetQuantity\n");

  Order order1;
  unsigned int q = rand();
  order1.set_quantity(q);

  assert(order1.get_index() == 0);
  assert(order1.get_price() == 0);
  assert(order1.get_side() == 0);
  assert(order1.get_quantity() == q);

  unsigned int p  = rand();
  unsigned int q2 = rand();
  unsigned int s  = rand();
  Order order2(p, q, s);
  order2.set_quantity(q2);

  assert(order2.get_index() == 0);
  assert(order2.get_price() == (p & LOWER_23_BITS));
  assert(order2.get_side() == (s & 1));
  assert(order2.get_quantity() == q2);
}

void test_Order_AddQuantity() {
  if(LOG_LEVEL <= DEBUG) printf("\ttest_Order_AddQuantity\n");

  Order order1;
  unsigned int q = rand();
  order1.add_quantity(q);

  assert(order1.get_index() == 0);
  assert(order1.get_price() == 0);
  assert(order1.get_side() == 0);
  assert(order1.get_quantity() == q);

  unsigned int p  = rand();
  unsigned int q2 = rand();
  unsigned int s  = rand();
  Order order2(p, q, s);
  order2.add_quantity(q2);

  assert(order2.get_index() == 0);
  assert(order2.get_price() == (p & LOWER_23_BITS));
  assert(order2.get_side() == (s & 1));
  assert(order2.get_quantity() == q + q2);
}

void test_Order_SubQuantity() {
  if(LOG_LEVEL <= DEBUG) printf("\ttest_Order_SubQuantity\n");

  Order order1;
  unsigned int q = rand();
  order1.sub_quantity(q);

  assert(order1.get_index() == 0);
  assert(order1.get_price() == 0);
  assert(order1.get_side() == 0);
  assert(order1.get_quantity() == 0 - q);

  unsigned int p  = rand();
  unsigned int q2 = rand();
  unsigned int s  = rand();
  Order order2(p, q, s);
  order2.sub_quantity(q2);

  assert(order2.get_index() == 0);
  assert(order2.get_price() == (p & LOWER_23_BITS));
  assert(order2.get_side() == (s & 1));
  assert(order2.get_quantity() == q - q2);
}

void test_Order() {
  test_Order_DefaultConstructor();
  test_Order_ParameterizedConstructor();
  test_Order_Constructor_PassByReference();

  test_Order_SetIndex();
  test_Order_SetPrice();
  test_Order_SetSide();
  test_Order_SetQuantity();

  test_Order_AddQuantity();
  test_Order_SubQuantity();

}
