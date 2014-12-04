SHELL=/bin/bash
CC=gcc
CPP=g++
CFLAGS=-O3 -fdiagnostics-color=auto -pthread -std=gnu11
CXXFLAGS=$(filter-out -std=gnu11, $(CFLAGS)) -std=gnu++11 -fno-exceptions -Wno-write-strings
MKDIRS=lib bin tst/bin .pass .pass/tst/bin
INCLUDE=$(addprefix -I,include)
EXECS=$(addprefix bin/,)
TESTS=$(addprefix tst/bin/, capitalC)

.PHONY: default all clean again check distcheck dist-check
.SECONDARY:
default: all
all: $(EXECS) $(TESTS)
clean:
	rm -rf $(MKDIRS)
again: clean all
check: $(addprefix .pass/,$(TESTS))
distcheck dist-check:
	@rm -rf .pass
	@make --no-print-directory check
.pass/tst/bin/%: tst/bin/% | .pass/tst/bin
	@printf "$<: "
	@$<\
		&& echo -e "\033[0;32mpass\033[0m" && touch $@\
		|| echo -e "\033[0;31mfail\033[0m"
$(MKDIRS):
	@mkdir -p $@
bin/%: %.cpp | bin
	$(CPP) $(CXXFLAGS) $(INCLUDE) $< -o $@
bin/%: %.c | bin
	$(CC) $(CFLAGS) $(INCLUDE) $< -o $@
lib/%.o: src/%.cpp include/%.h | lib
	$(CPP) -c $(CXXFLAGS) $(INCLUDE) $< -o $@
lib/%.o: src/%.c include/%.h | lib
	$(CC) -c $(CFLAGS) $(INCLUDE) $< -o $@
tst/bin/%: tst/%.cpp | tst/bin
	$(CPP) $(CXXFLAGS) $(INCLUDE) $^ -o $@
tst/bin/%: tst/%.c | tst/bin
	$(CC) $(CFLAGS) $(INCLUDE) $^ -o $@
