MAIN = build/snake
BUILD_CONFIG = build/build.ninja
BUILD_FILE = CMakeLists.txt
SRCS = src/* include/*

.PHONY: depend clean
all:	$(MAIN)
	@echo  $(MAIN) has been compiled
$(MAIN):	$(BUILD_CONFIG) $(SRCS)
	@ninja -j8 -C build/
$(BUILD_CONFIG):	$(BUILD_FILE)
	@cmake $(CMAKE_FLAG) -B build/ -S ./
clean:
	$(RM) -rf build/* $(MAIN)
run :	$(MAIN)
	@./$(MAIN)
