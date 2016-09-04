CC = g++
SOURCE = main.cpp graphics/window.cpp
OUTPUT = sparky
GL_INCLUDE = -I/usr/local/include -I/opt/X11/lib
GL_LIBRARY = -L/usr/local/lib -I/opt/X11/lib
FREETYPE = -I/usr/local/Cellar/freetype/2.6.3/include/freetype2
LINKER_FLAGS = -framework OpenGL -lglfw3 -lglew
# -lftgl

sparky: main.cpp graphics/window.cpp
	$(CC) $(SOURCE) $(GL_INCLUDE) $(GL_LIBRARY) $(LINKER_FLAGS) -o $(OUTPUT)
