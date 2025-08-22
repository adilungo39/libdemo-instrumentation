// Demo app that calls demo_add from libdemo.so
#include <stdio.h>

int demo_add(int, int); // from libdemo.so

int main(void){
  int sum = 0;
  for(int i = 0; i < 200; ++i){
    int a = i % 100;
    int b = (i * 7) % 100;
    sum += demo_add(a, b);
    if (i % 50 == 0) {
      printf("i=%d, partial=%d\n", i, sum);
    }
  }
  printf("done, sum=%d\n", sum);
  return 0;
}
