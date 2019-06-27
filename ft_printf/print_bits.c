#include <stdio.h>
#include <limits.h>

static void print_bits(const char* little_endian_memory, size_t size)
{
  for (size_t i = size; i--> 0; ) {
    const unsigned char byte = little_endian_memory[i];
    for (size_t n = CHAR_BIT; n--> 0; )
      putchar(byte & (1u << n) ? '1' : '0');
  }
}

int main(void)
{
  double x = 2346.3463342342;
  print_bits((const char*)&x, sizeof x);
}