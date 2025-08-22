// A tiny demo library exporting demo_add with variable latency
#include <time.h>

int demo_add(int a, int b){
  // Simulate 0–4ms work based on inputs
  struct timespec t = {0};
  t.tv_nsec = ((a + b) % 5) * 1000000L;
  if (t.tv_nsec > 0) {
    nanosleep(&t, 0);
  }
  return a + b;
}
