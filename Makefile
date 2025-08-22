CC = gcc
CFLAGS = -fPIC -O2 -Wall -Wextra -g
.PHONY: all clean run plot

all: libdemo.so libhook.so demo_app

libdemo.so: demo/libdemo.c
	$(CC) $(CFLAGS) -shared -o $@ $<

libhook.so: src/hook.c
	$(CC) $(CFLAGS) -shared -o $@ $< -ldl

demo_app: demo/demo_app.c libdemo.so
	$(CC) -O2 -Wall -Wextra -o $@ $< -L. -ldemo -Wl,-rpath,'$$ORIGIN'

run:
	LD_LIBRARY_PATH=. LD_PRELOAD=./libhook.so ./demo_app

plot:
	python3 scripts/plot.py

clean:
	rm -f libdemo.so libhook.so demo_app hook.csv latency.png
	find . -name '*.o' -delete
