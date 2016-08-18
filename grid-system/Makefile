CC = g++
SOURCE = main.cpp
OUTPUT = grid
GL_INCLUDE = -I/usr/local/include -I/opt/X11/lib
GL_LIBRARY = -L/usr/local/lib
FREETYPE = -I/usr/local/Cellar/freetype/2.6.3/include/freetype2
LINKER_FLAGS = -framework OpenGL -lglfw3 -lglew

grid: main.cpp
	$(CC) $(SOURCE) $(GL_INCLUDE) $(GL_LIBRARY) $(LINKER_FLAGS) -o $(OUTPUT)
