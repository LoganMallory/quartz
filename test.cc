#include <cstdio>
#include <cassert>
#include <cstdlib>
#include "Log-Levels.h"
static const int LOG_LEVEL = INFO;
#include "src/test/Order-test.cc"


void print_bits(unsigned int a) {
  for(int i=0; i<32; i++) {
    printf("%u ", a & (1<<31) ? 1 : 0);
    a <<= 1;
  }
  printf("\n\n");
}

int main() {
  //prevents stdout buffering
  setbuf(stdout, NULL);

  srand(1);

  printf("LOWER_8_BITS:\n");
  print_bits(LOWER_8_BITS);

  printf("LOWER_23_BITS:\n");
  print_bits(LOWER_23_BITS);

  printf("ORDER_INDEX_MASK:\n");
  print_bits(ORDER_INDEX_MASK);

  printf("ORDER_PRICE_MASK:\n");
  print_bits(ORDER_PRICE_MASK);

  printf("ORDER_SIDE_MASK:\n");
  print_bits(ORDER_SIDE_MASK);


  for(int i=1; i<=1000000; i++) {
    printf("\rTesting... %-8d", i);

    test_Order();
    
  }

  printf("\n");
}
