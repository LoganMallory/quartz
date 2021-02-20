#ifndef ORDER_H
#define ORDER_H
#include <cstdio>
static const unsigned int LOWER_8_BITS     = 0xff;
static const unsigned int LOWER_23_BITS    = 0x7fffff;
static const unsigned int ORDER_INDEX_MASK = 0xff000000;
static const unsigned int ORDER_PRICE_MASK = 0xfffffe;
static const unsigned int ORDER_SIDE_MASK  = 0x1;

class Order {
public:
  unsigned int id;       //32 bits: index(8) price(23) side(1)
  unsigned int quantity;


  Order();
  Order(const unsigned int& price, const unsigned int& quantity, const unsigned int& side);

  unsigned int get_id() const;
  unsigned int get_index() const;
  unsigned int get_price() const;
  unsigned int get_side() const;
  unsigned int get_quantity() const;

  void set_index(const unsigned int& index);
  void set_price(const unsigned int& price);
  void set_side(const unsigned int& side);
  void set_quantity(const unsigned int& quantity);
  void add_quantity(const unsigned int& quantity);
  void sub_quantity(const unsigned int& quantity);

};

#include "Order.cc"
#endif
