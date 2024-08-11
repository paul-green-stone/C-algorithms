# Object files location. Object files will be placed in this directory during compilation
OBJDIR := objects

# Full names of object files
OBJECTS	:= $(addprefix $(OBJDIR)/, sort_search.o)

# ================================================================ #

# C compiler
CC := gcc

# We are only interested in object files without linking them into an executable `-c`
# Debugging included `-g`
CFLAGS := -g -c

# Extra layer of protection
ALL_CFLAGS := $(CFLAGS) -Wall -Wextra -pedantic-errors -fPIC -O2

# ================================ #

# Using an archiver to produce a static library
AR := ar

# Archiver flags
ARFLAGS := -r -s

# ================================ #

# *nix operating system support only
OS_NAME := $(shell uname -s)

# Library name
LIB_NAME := Calgs

# ================================ #

# If the operating system is Linux, set the variables
ifeq ($(OS_NAME), Linux)
# The prefix for library names
	LIB_PREFIX := lib
# The suffix for static library files
    LIB_SUFFIX := .a
# The suffix for dynamic library files
    DLL_SUFFIX := .so
else ifeq ($(OS_NAME), Darwin)
# The prefix for library names
    LIB_PREFIX := lib
# The suffix for static library files
    LIB_SUFFIX := .a
# The suffix for dynamic library files
    DLL_SUFFIX := .dylib
else
    $(error Unsupported operating system)
endif

# ======== #

# Constructing the name of static library
TARGET_STATIC := $(LIB_PREFIX)$(LIB_NAME)$(LIB_SUFFIX)


# Constructing the name of dynamic library
TARGET_SHARED := $(LIB_PREFIX)$(LIB_NAME)$(DLL_SUFFIX)

# ================================================================ #
# ================================================================ #
# ================================================================ #

# Setting the value of the variable SORT_SEARCH to the path of the `sorting.c`
SORT_SEARCH := $(addprefix sorting/, sorting.c)

# ================================================================ #
# ================================================================ #
# ================================================================ #

# Define a target
all: $(TARGET_STATIC) $(TARGET_SHARED)

# Building a static library
$(TARGET_STATIC): $(OBJECTS)
	$(AR) $(ARFLAGS) $(TARGET_STATIC) $^

#Building a shared library
$(TARGET_SHARED): $(OBJECTS)
	$(CC) -shared -o $@ $^ $(LDFLAGS)
    
# ================================ #

# Building the `sort_search.o` object file from the SORT_SEARCH
$(OBJDIR)/sort_search.o: $(SORT_SEARCH) sorting/sorting.h
	$(CC) $(ALL_CFLAGS) $(CFLAGS) -o $@ $<

# ================================================================ #
# ================================================================ #
# ================================================================ #

# Creating a directory if it does not exist. *nix
$(shell mkdir -p $(OBJDIR))

# ================================ #

# Executing the commands regardless of whether a file named clean exists or not
.PHONY: clean

clean:
	rm -rf $(OBJS) $(OBJDIR) $(TARGET_STATIC) $(TARGET_SHARED)