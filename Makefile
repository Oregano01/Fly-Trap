
#OBJS will specify which file to compile
OBJS = *.cpp *.hpp

#CC specifies compiler we are using
CC = g++

#COMPILER_FLAGS specifies additional compilation options.
# -w to supress all warnings
COMPILER_FLAGS = -w

#LINKER_FLAGS specifies libraries we're linking
LINKER_FLAGS = -lSDL2 -lSDL2_image

#OBJ_NAME specifies the name of our executable
OBJ_NAME = Fly-Trap

#target that compiles our executable
all : $(OBJS)
				$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
