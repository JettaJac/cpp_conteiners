CCF=g++ #-lstdc++ -std=c++17 -Wextra -Wall -Werror #-g -fsanitize=address 
GCOV_FLAGS=-fprofile-arcs -ftest-coverage -lgcov
CHECK_FLAGS= -lgtest -lgtest_main -lpthread
# -lcheck -lm -lpthread
ALL_FLAGS=$(CFLAGS) $(GCOV_FLAGS) $(CHECK_FLAGS)

SRCS = list.h

OBJS = $(SRCS:.c=.o) tests.cc 
OBJS_m = $(SRCS:.c=.o) main.cc 
# OBJS_T = $(SRCS:.c=.o) tests_t.cc 
# OBJS2 = $(SRCS:.c=.o) s21_matrix_test.cc
# OBJS3 = $(SRCS:.c=.o) s21_test_matrix.cc
# OBJS4 = $(SRCS:.c=.o) s21_test_matrix2.cc
NAME = list
# NAME2 = test2

REPORT_NAME = report

all: objs list.a test

objs: $(SRCS)
	$(CCF) $(CFLAGS)  $(SRCS) -c 

list.a: objs
	ar rc list.a  list.o 
	ranlib list.a

test: $(OBJS)
	$(CCF) $(CHECK_FLAGS) $(OBJS) -o list
	./list

main: $(OBJS)
	$(CCF) $(CHECK_FLAGS) $(OBJS_m) -o list
	./list
#	 CK_FORK=no leaks -exclude -list --atExit -- ./list  | grep LEAK:

test_t: $(OBJS_T)
	$(CCF) $(CHECK_FLAGS) $(OBJS_T) -o list
	./list

clean:
	rm -rf *.o
	rm -rf *.out
	rm -rf *.gch
	rm -rf *.dSYM
	rm -rf *.gcno
	rm -rf *.gcda
	rm -rf *.info
	rm -rf *.a
	rm -rf $(REPORT_NAME)
	rm -rf *.log
	rm -rf test
	rm -rf test_t
	rm -rf list


gcov_report:
	$(CCF) -o $(NAME) $(SRCS) tests_t.cc $(GCOV_FLAGS) $(CHECK_FLAGS)
	./$(NAME)
	lcov -t "gcov_report" -o tests.info -c -d .
	genhtml -o $(REPORT_NAME) tests.info
	open report/index.html
	rm $(NAME)
	rm *.gcno *.gcda

check: 
	clang-format  -n *.cc *.h
	clang-format  -i *.cc *.h
   