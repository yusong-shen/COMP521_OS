#
#	Template Makefile for COMP 421 Lab 1 monitor-based terminal
#	device driver and test programs
#
#	The device driver monitor built will be named "montty.o".
#	This is an object file that can then be linked with any
#	user test program desired.  *ALL* Makefiles for this lab
#	must make a target named "montty.o" rule in them to
#	produce your terminal device driver -- we will run
#	your Makefile and will grade the resulting device driver
#	named "montty.o" when lilnked with our own user test programs.
#
MONTTY = montty.o

#
#	This Makefile and the project are designed to work with gcc.
#	All solutions for the Lab 1 project must be written using
#	the C programming language (e.g., not in C++ or other languages).
#
LANG = gcc

#
#	Define the list of everything to be made by this Makefile.
#
#	The TEST list is a list of all user test programs that you
#	want to test your terminal device driver with.  Edit it to
#	be a list of your own test programs (the example initially
#	given below is for test programs named test1, test2, and
#	test3).
#
#	For each user test program, the Makefile will make the
#	program out of a single correspondingly named source file.
#	In addition to this single source file for each test
#	program, each program will also be linked with your device
#	driver.  For example, the Makefile will make test1 out
#	of test1.c, if you have a file named test1.c in this
#	directory.
#
#	The ALL list is the complete list of everything to be made
#	by the Makefile.  In addition to the user test programs
#	(defined by TEST list), the Makefile must create your
#	terminal device driver named \verb|montty.o|.  Your
#	compiled driver *must* be named \verb|montty.o|.
#
TEST = test1
ALL = $(MONTTY) $(TEST)

#
#	You should not have to modify anything else in this Makefile
#	below here.  If you want to, however, you may modify things
#	such as the definition of CFLAGS, for example.
#

PUBLIC_DIR = /clear/courses/comp421/lab1

CPPFLAGS = -I$(PUBLIC_DIR)/include
CFLAGS = -g -Wall -fno-inline
LDFLAGS = -pthread

all: $(ALL)

$(TEST): $(MONTTY) $(PUBLIC_DIR)/lib/liblab1.a

clean:
	rm -f $(ALL)
