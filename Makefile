CC=g++
CPPFLAGS = -Istb/
LDFLAGS = #-L/usr/local/Cellar/llvm/9.0.0_1/lib -Wl,-search_paths_first -Wl,-headerpad_max_install_names
PROGFLAGS = -g -Wall
INPUT = *.cpp stb/stb_image_write.h

macos:
	$(CC) $(CPPFLAGS) $(PROGFLAGS) $(LDFLAGS) $(INPUT) 

all:
	$(CC) -Wall -g -std=c++17 *.cpp stb/stb_image_write.h -o program