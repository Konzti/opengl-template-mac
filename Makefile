C_FILES = ./*.c
INCLUDES = -I./include/
LIBRARY = -L./library/
LIBRARIES = -lglfw3
FRAMEWORKS = -framework OpenGL -framework IOKit -framework Cocoa -framework CoreVideo

build:
	@echo "Building..."
	clang $(C_FILES) -Wall $(INCLUDES) $(LIBRARY) $(LIBRARIES) $(FRAMEWORKS) -o main 