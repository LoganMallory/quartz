Order::Order() {
  if(LOG_LEVEL <= DEBUG) printf("[DEBUG] Order::Order()\n");
  this->id       = 0;
  this->quantity = 0;
}

//Create an Order with the given price, quantity, and side (0=ask, 1=bid) and compress that info into Order's id
Order::Order(const unsigned int& price, const unsigned int& quantity, const unsigned int& side) {
  if(LOG_LEVEL <= DEBUG) printf("[DEBUG] Order::Order(price=%u, quantity=%u, side=%u)\n", price, quantity, side);

  this->set_index(0);        //index = 0 until Order is put in table (or never, if Order fully matches)
  this->set_side(side);
  this->set_price(price);
  this->quantity = quantity;
}


// GETTERS //
unsigned int Order::get_id() const {
  return this->id;
}

unsigned int Order::get_index() const {
  return (this->id & ORDER_INDEX_MASK) >> 24;
}

unsigned int Order::get_price() const {
  return (this->id & ORDER_PRICE_MASK) >> 1;
}

unsigned int Order::get_side() const {
  return this->id & ORDER_SIDE_MASK;
}

unsigned int Order::get_quantity() const {
  return this->quantity;
}


// SETTERS //
void Order::set_index(const unsigned int& index) {
  if(LOG_LEVEL <= DEBUG && index > LOWER_8_BITS) printf("[ERROR] set_index(index=%u) > LOWER_8_BITS\n", index);
  this->id &= ~ORDER_INDEX_MASK;            //zero out the index bits
  this->id |= (index & LOWER_8_BITS) << 24; //replace with new index (bounded)
}

void Order::set_price(const unsigned int& price) {
  if(LOG_LEVEL <= DEBUG && price > LOWER_23_BITS) printf("[ERROR] set_price(price=%u) > LOWER_23_BITS\n", price);
  this->id &= ~ORDER_PRICE_MASK;            //zero out the price bits
  this->id |= (price & LOWER_23_BITS) << 1; //replace with new price (bounded)
}

void Order::set_side(const unsigned int& side) {
  if(LOG_LEVEL <= DEBUG && side > 1) printf("[ERROR] set_side(side=%u) > 1\n", side);
  this->id &= ~1;         //zero out side bit
  this->id |= (side & 1); //replace with new side (bounded)
}

void Order::set_quantity(const unsigned int& quantity) {
  this->quantity = quantity;
}

void Order::add_quantity(const unsigned int& quantity) {
  this->quantity += quantity;
}

void Order::sub_quantity(const unsigned int& quantity) {
  this->quantity -= quantity;
}

//31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9  8  7  6  5  4  3  2  1  0
//0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
