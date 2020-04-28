# Simple makefile template to handle a few executables
# in a single directory. Mostly to help playing around
# with code in a lightweight manner.
#
# Lorenzo Flueckiger - April 2020
#
# To use this makefile, you need to:
# 1) define two variables (at the top of this makefile):
#   a) sources = all the source files you want to compile
#      (DEFINE SOURCES section)
#   b) targets = all the executables you would like to build
#      (DEFINE EXECUTABLES section)
# 2) define the extra dependencies if one executable depends
#    on more than one source file:
#       EXTRA RULES section
#
# Beside this, the makefile should handle all the dependencies
# automatically for you and recompile only what is necessary!
#
# `make help` will show the list of targets

# DEFINE SOURCES HERE
# If you want everything, just use a wildcard
sources := $(wildcard *.cpp)
# If your prefer to be selective, explicitely define the files to compile
#sources := hello.cpp simple.cpp waste.cpp

# DEFINE EXECUTABLE HERE
targets := hello waste moving
# If there is only a single source fule per executable, you could generate
# this variable automatically:
#targets := $(patsubst %.cpp, %, $(sources))

# Define your prefered compiler
CC = clang++
CXX = clang++
#CC = g++
#CXX = g++

# Use a modern language and are careful about our code
CXXFLAGS =  -std=c++17 -Wall -Wextra -g -fno-elide-constructors 

# Dependency flags
DEPFLAGS = -MT $@ -MMD -MP -MF $(dep_dir)/$*.d
# For the deependencies management, have a look at:
# http://make.mad-scientist.net/papers/advanced-auto-dependency-generation/

# Generation of artifacts should not pollute the directory
dep_dir = ./.deps
obj_dir = ./.objs
bin_dir = ./bin

objects := $(addprefix $(obj_dir)/, $(patsubst %.cpp,%.o, $(sources)))
depfiles := $(addprefix $(dep_dir)/, $(patsubst %.cpp,%.d, $(sources)))
binaries := $(addprefix $(bin_dir)/,$(targets))

all: $(binaries)

# Add here extra dependencies that this simple makefile
# cannot figure out automatically
# EXTRA RULES START
$(bin_dir)/waste: $(obj_dir)/simple.o

# EXTRA RULES STOP
# Stop editing now, and let the smart rules do their job!

help:
	@echo "make [target]"
	@echo "  none|all : build the binaries"
	@echo "  clean: remove all objects"
	@echo "  purge: remove all objects and binaries"
	@echo "  info: print some basic debug information"

# How to compile an object
$(obj_dir)/%.o: %.cpp $(dep_dir)/%.d | $(dep_dir) $(obj_dir)
	$(CXX) $(DEPFLAGS) $(CXXFLAGS) $(OUTPUT_OPTION) -c $<

# How to build a binary
$(bin_dir)/%: $(obj_dir)/%.o | $(bin_dir)
	$(CC) $(OUTPUT_OPTION) $^

$(depfiles):
include $(wildcard $(depfiles))

# Rules to create subdirectories
$(dep_dir):
	mkdir -p $@

$(obj_dir):
	mkdir -p $@

$(bin_dir):
	mkdir -p $@

# Check if we are sane
info:
	$(info compiler=$(CXX))
	$(info options=$(CXXFLAGS))
	$(info sources=$(sources))
	$(info depfiles=$(depfiles))
	$(info objects=$(objects))
	$(info binaries=$(binaries))

# Allow to clean things properly
clean:
	rm -fr $(obj_dir) $(dep_dir)

purge: | clean
	rm -fr $(bin_dir)

.PRECIOUS: $(objects)

.PHONY: clean purge
