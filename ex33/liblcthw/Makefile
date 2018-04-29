CFLAGS=-g -O2 -Wall -Wextra -Isrc -rdynamic -DNDEBUG $(OPTFLAGS)
LIBS=-ldl $(OPTLIBS)
PREFIX?=/usr/local # ? makes it an optional variable.

SOURCES=$(wildcard src/**/*.c src/*.c)
OBJECTS=$(patsubst %.c,%.o,$(SOURCES))

TEST_SRC=$(wildcard tests/*_tests.c)
TESTS=$(patsubst %.c,%,$(TEST_SRC))

.PHONY: echo
echo:
	@echo $(TEST_SRC) $(TESTS)


TARGET=build/liblcthw.a
SO_TARGET=$(patsubst %.a,%.so,$(TARGET))

# The Target Build
all : $(TARGET) $(SO_TARGET) $(TESTS) tests

dev: CFLAGS=-g -Wall -Isrc -Wall -Wextra $(OPTFLAGS)
dev: all

$(TARGET): CFLAGS += -fPIC
$(TARGET): build $(OBJECTS)
	ar rcs $@ $(OBJECTS)
	ranlib $@

$(SO_TARGET): $(TARGET) $(OBJECTS)
	$(CC) -shared -o $@ $(OBJECTS)
	@echo Helloeeees.

build:
	@mkdir -p build
	@mkdir -p bin

# I do not even know how to name this, **the rest** ???
%: %.c 
	${CC} ${CFLAGS} -o $@ $< $(TARGET)

# The Unit Tests
#.PHONY: $(TESTS)
tests: $(TESTS)
	sh ./tests/runtests.sh #test_lib.sh
#tests: CFLAGS += $(SO_TARGET)
#tests: $(TESTS)
#	cat $^ > $@
#	$(CC) $(CFLAGS) $(TEST_SRC) -ldl -o $(TESTS)
#	$(CC) $(CFLAGS) $(TEST_SRC output,,$<) -o -ldl $<
 
# Had problems as It only 
#$(TESTS): % : $(TEST_SRC)
#	$(CC) $(CFLAGS) $(SO_TARGET) $< -ldl -o $@


# The Cleaner
clean: 
	rm -rf build $(OBJECTS) $(TESTS)
	rm -f tests/tests.log
	find . -name "*.gc" -exec rm {} \;
	rm -rf `find . -name "*.dSYM" -print`

# The Install
install: all
	install -d $(DESTDIR)/$(PREFIX)/lib/
	install $(TARGET) $(DESTDIR)/$(PREFIX)/lib/

# The Checker
check: 
	@echo Files with potentially dangerous functions.
	@egrep '[^_.>a-zA-Z0-9](str(n?cpy|n?cat|xfm|n?dup|str|pbrk|tok|_)\
				|stpn?cpy|a?sn?printf|byte_)' $(SOURCES) || true
