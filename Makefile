CC     = gcc
CFLAGS = -g -Wall
LIBPATH += -L"/System/Library/Frameworks/OpenGL.framework/Libraries"
FRAMEWORK = -framework GLUT
FRAMEWORK += -framework OpenGL
LIBRARIES = -lGL -lGLU -lstdc++

all: spinningcube

spinningcube: spinningcube.o
	$(CC) $(FRAMEWORK) $(CFLAGS) -o $@ $(LIBPATH) $(OBJECTS) $<

spinningcube.o: spinningcube.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f spinningcube spinningcube.o

# This is GNU Makefile extension to notify that roughly means: 'clean' does
# not depend on any files in order to call it.
.PHONY: clean


#OBJECTS = GlutExample.o 
#All: GlutExample 

#GlutExample: GlutExample.o $(OBJECTS) 
    #$(CC) $(FRAMEWORK) $(CFLAGS) -o $@ $(LIBPATH) $(OBJECTS)

#$(LIBRARIES) 
       #./GlutExample

