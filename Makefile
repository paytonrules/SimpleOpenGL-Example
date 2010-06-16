CC     = gcc
CFLAGS = -g -Wall
LIBPATH += -L"/System/Library/Frameworks/OpenGL.framework/Libraries"
FRAMEWORK = -framework GLUT
FRAMEWORK += -framework OpenGL
LIBRARIES = -lGL -lGLU -lstdc++

all: simpleexample

simpleexample: simpleexample.o
	$(CC) $(FRAMEWORK) $(CFLAGS) -o $@ $(LIBPATH) $(OBJECTS) $<

simpleexample.o: simpleexample.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f simpleexample simpleexample.o

# This is GNU Makefile extension to notify that roughly means: 'clean' does
# not depend on any files in order to call it.
.PHONY: clean
