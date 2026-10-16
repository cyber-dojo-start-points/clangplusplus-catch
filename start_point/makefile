CXXFLAGS += -I.
CXXFLAGS += -std=c++2a
CXXFLAGS += -Wall
CXXFLAGS += -Wextra
CXXFLAGS += -Wshadow
CXXFLAGS += -Wfloat-equal
CXXFLAGS += -O
CXXFLAGS += -Wsequence-point
CXXFLAGS += -Wmissing-noreturn
CXXFLAGS += -Wunreachable-code

COVERAGE_FLAGS += -fprofile-arcs -ftest-coverage
CXXFLAGS += $(COVERAGE_FLAGS)

CXXFLAGS += -fsanitize=leak,address
CXXFLAGS += -fno-sanitize-recover=undefined
CXXFLAGS += -fno-omit-frame-pointer

HPP_FILES = $(wildcard *.hpp)
COMPILED_HPP_FILES = $(patsubst %.hpp,%.compiled_hpp,$(HPP_FILES))
CPP_FILES = $(wildcard *.cpp)
OBJ_FILES = $(patsubst %.cpp,%.o,$(CPP_FILES))
# Catch2Main holds main(), so a kata's files hold only its tests.
LDLIBS = -lCatch2Main -lCatch2

%.o: %.cpp
	@$(CXX) -c -o $@ $< $(CXXFLAGS)

# Catch2 runs tests in a random order unless told otherwise. Declaration
# order is what lets a test that ends the process leave the earlier ones
# reported.
.PHONY: test.output
test.output: test makefile
	@./$< --order decl

test: $(OBJ_FILES) $(COMPILED_HPP_FILES)
	@$(CXX) $(CXXFLAGS) -O $(OBJ_FILES) -o $@ $(LDLIBS)

# This rule ensures header files build in their own right.
# The quality of header files is important because header files
# are #included from other files and thus have a large span
# of influence (unlike .cpp files which are not #included)

# hiker.hpp compiled here and hiker.cpp compiled elsewhere both claim
# hiker.gcno, so a learner's own source file can vanish from the coverage
# report. The header holds no code to measure, so leaving coverage out of this
# compile is what keeps the real coverage data intact.
%.compiled_hpp: %.hpp
	@$(CXX) -x c++ $(filter-out $(COVERAGE_FLAGS),$(CXXFLAGS)) -c -o $@ $<
