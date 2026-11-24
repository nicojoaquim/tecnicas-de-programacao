raiz := .

binario := $(raiz)/bin
src_dir := $(raiz)/src
obj_dir := $(raiz)/obj

#sfml_path := /opt/sfml2
sfml_path := "$(shell pwd)"/SFML-2.6.2

libraries := sfml-system sfml-window sfml-graphics

libraries := -L$(sfml_path)/lib $(patsubst %,-l%,$(libraries))
libraries += -Wl,-rpath=$(sfml_path)/lib

headers := -I$(sfml_path)/include

#sources := main Jogo Gerenciador/Janela
#sources := $(patsubst %,$(src_dir)/%.cpp,$(sources))

sources := $(shell find $(src_dir) -type f -name "*.cpp")

objects := $(patsubst $(src_dir)/%.cpp,$(obj_dir)/%.o,$(sources))

compiler := g++ -Wall

.PHONY: all
.PHONY: build
.PHONY: rebuild
.PHONY: clean
.PHONY: run

all: $(binario) run

build: $(binario)

rebuild: clean $(binario)

$(binario): $(objects)
	$(compiler) -o $(binario) $(objects) $(libraries)

#$(objects): $(obj_dir)/%.o: $(src_dir)/%.cpp
#	@if [ ! -d $(dir $@) ]; then mkdir -p $(dir $@); fi
#	$(compiler) -o $@ -c $< $(headers)

depends := $(patsubst %.o,%.d,$(objects))
-include $(depends)
$(objects): $(obj_dir)/%.o: $(src_dir)/%.cpp makefile
	@if [ ! -d $(dir $@) ]; then mkdir -p $(dir $@); fi
	$(compiler) -o $@ -c $< -MMD -MP $(headers)

clean:
	rm -rf $(obj_dir)
	rm -f $(binario)

run:
	@$(binario)
#	export LD_LIBRARY_PATH=$(sfml_path)/lib && $(binario)

