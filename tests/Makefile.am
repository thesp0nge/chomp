## Process this file with automake to produce Makefile.in

TESTS = check_chomp
chomp_PROGRAMS = check_chomp
check_chomp_SOURCES = check_chomp.c $(top_builddir)/src/chomp.h
check_chomp_CFLAGS = @CHECK_CFLAGS@
check_chomp_LDADD = $(top_builddir)/src/chomp.o @CHECK_LIBS@
