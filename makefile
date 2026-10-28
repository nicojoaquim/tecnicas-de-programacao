raiz := .

binario := $(raiz)/bin
src_dir := $(raiz)/src
obj_dir := $(raiz)/obj

libraries := sfml-system sfml-window sfml-graphics

libraries := -L/opt/sfml2/lib $(patsubst %,-l%,$(libraries))
libraries += -Wl,-rpath=/opt/sfml2/lib

headers := -I/opt/sfml2/include

#sources := main Jogo Gerenciador/Janela
#sources := $(patsubst %,$(src_dir)/%.cpp,$(sources))

sources := $(shell find $(src_dir) -type f -name "*.cpp")

objects := $(patsubst $(src_dir)/%.cpp,$(obj_dir)/%.o,$(sources))

compiler := g++ -Wall

.PHONY: all
.PHONY: rebuild
.PHONY: clean
.PHONY: run

all: $(binario)

rebuild: clean $(binario)

$(binario): $(objects)
	$(compiler) -o $(binario) $(objects) $(libraries)

$(objects): $(obj_dir)/%.o: $(src_dir)/%.cpp
	@if [ ! -d $(dir $@) ]; then mkdir -p $(dir $@); fi
	$(compiler) -o $@ -c $< $(headers)

clean:
	rm -rf $(obj_dir)
	rm -f $(binario)

run:
	@$(binario)
#	export LD_LIBRARY_PATH=/opt/sfml2/lib && $(binario)
