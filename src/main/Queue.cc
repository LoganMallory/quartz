Queue::Queue() {
  if(LOG_LEVEL <= DEBUG) printf("[DEBUG] Queue::Queue()\n");
  this->size        = 0;
  this->quantity    = 0;
  this->start_index = 0;
  this->next_index  = 0;
}

unsigned short Queue::get_size() const {
  return this->size;
}

unsigned int Queue::get_quantity() const {
  return this->quantity;
}

void Queue::reset_indices() {
  this->start_index = 0;
  this->next_index  = 0;
}

void Queue::trim_indices() {
  //TODO
}

void Queue::enqueue_order(Order& order) {
  if(LOG_LEVEL <= DEBUG) printf("[DEBUG] Queue::enqueue_order(order={price: %u, quantity: %u, side: %u})\n", order.get_price(), order.get_quantity(), order.get_side());
  //printf("[ ERROR ] Queue is full, cannot enqueue order");

  //increase queue quantity
  this->quantity += order.get_quantity();

  //value copy the Order into the array, increment/wrap around next_index
  this->orders[this->next_index++] = order; //does value copy occur?

  //increment size
  this->size++;

  //update Order's id for API response
  order.set_index(this->next_index-1);
}

void Queue::remove_order_by_index(const unsigned char& index) {
  if(LOG_LEVEL <= DEBUG) printf("[DEBUG] Queue::remove_order_by_index(index=%u)\n", index);

  //decrease queue quantity
  this->quantity -= this->orders[index].get_quantity();

  //effectively nullify the order -- relies on matching engine checking quantity
  this->orders[index].set_quantity(0);

  //TODO: should prob implement this.trim() to reset indices correctly, skip over empty slots
  //if no orders left after removal, reset the start and next indices
  if(this->size == 1) this->reset_indices();

  //if removing first-in-line order, increment start_index
  else if(index == this->start_index) this->start_index++;

  //if removing most recent order, decrement next_index
  else if(index == this->next_index-1) this->next_index--;

  //decrement the size
  this->size--;
}

Order& Queue::get_order_by_index(const unsigned char& index) {
  if(LOG_LEVEL <= DEBUG) printf("[DEBUG] Queue::get_order_by_index(index=%u)\n", index);

  //return a reference to the Order
  return this->orders[index];
}

bool Queue::is_full() const {
  return this->size >= QUEUE_SIZE;
}

void Queue::clear() {
  if(LOG_LEVEL <= DEBUG) printf("[DEBUG] Queue::clear()\n");

  //reset queue quantity
  this->quantity = 0;

  //set all Order's quantities to zero
  for(int i=0; i<QUEUE_SIZE; i++)
    this->orders[i].set_quantity(0);

  //reset size
  this->size = 0;

  //reset indexes
  this->start_index = 0;
  this->next_index  = 0;
}
