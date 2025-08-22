// Observe-only LD_PRELOAD hook for demo_add in libdemo.so
#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef int (*demo_add_fn)(int,int);
static demo_add_fn real_demo_add = NULL;
static FILE* logf = NULL;

static long ms_since(struct timespec a, struct timespec b){
  return (b.tv_sec - a.tv_sec) * 1000L + (b.tv_nsec - a.tv_nsec) / 1000000L;
}

__attribute__((constructor))
static void hook_init(void){
  logf = fopen("hook.csv","a");
  if (logf) {
    fseek(logf, 0, SEEK_END);
    long size = ftell(logf);
    if (size == 0) {
      fprintf(logf, "ts,a,b,r,ms\n");
      fflush(logf);
    }
  }
}

__attribute__((destructor))
static void hook_fini(void){
  if (logf) fclose(logf);
}

int demo_add(int a, int b){
  if(!real_demo_add){
    real_demo_add = (demo_add_fn)dlsym(RTLD_NEXT, "demo_add");
    if(!real_demo_add){
      fprintf(stderr, "[hook] failed to resolve demo_add\n");
      return 0;
    }
  }
  struct timespec t0, t1;
  clock_gettime(CLOCK_MONOTONIC, &t0);
  int r = real_demo_add(a, b);
  clock_gettime(CLOCK_MONOTONIC, &t1);
  if (logf){
    fprintf(logf, "%ld,%d,%d,%d,%ld\n", time(NULL), a, b, r, ms_since(t0, t1));
    fflush(logf);
  }
  return r;
}
