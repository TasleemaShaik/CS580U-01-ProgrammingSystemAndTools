ASSIGNMENT=string-functions
HOSTNAME=$(shell hostname)
DATETIME=$(shell date)
SUBMIT=$(ASSIGNMENT)-$(USER)

CC=/usr/bin/gcc
CXX=/usr/bin/g++
CFLAGS=-g -Wall -Werror -std=c2x
LDFLAGS=-L.
LDLIBS=-lcunit -lsolutions -lrandstr
ARFLAGS=rcvs

all: test

# Implement a test rule that:
# 1. Depends on test.c, functions.c
# 2. Uses flags in CFLAGS and LDFLAGS
# 3. Links to the libraries in LDLIBS
# 4. Produces a binary named test
test: test.c functions.c
	$(CC) $(CFLAGS) $(LDFLAGS) test.c functions.c -o test $(LDLIBS)
	

# Rules to check for correct implmentations
# test.log is a feedback file for cut-and-paste to Brightspace or Github issues
test.log: test
	echo $(USERNAME)@$(HOSTNAME) at $(DATETIME) | tee $@
	-./test --verbose 2>&1 | tee -a $@
	-valgrind --tool=memcheck --leak-check=full --error-exitcode=1 \

.PHONY: check
check: test.log

# Rules to produce an archive containing repository contents
$(SUBMIT).tar: configure.sh functions.c functions.h librandstr.a \
               libsolutions.a Makefile randstr.h solutions.h \
               test.c
	mkdir -p $(SUBMIT)
	cp $^ $(SUBMIT)
	tar -cf $@ $(SUBMIT)
	$(RM) -r $(SUBMIT)

.PHONY: submit
submit: $(SUBMIT).tar

# Implement a clean rule that:
# 1. removes any files created by `make test`: ./test 
# 2. removes any files created by `make check`: test.log
# 3. removes any files created by `make submit`: *.tar 
# 4. removes any editor cruft files
.PHONY: clean
clean:
	rm -rf main *.tar test test.log
