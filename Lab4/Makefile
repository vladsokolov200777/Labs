CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -O2

TARGET = laba4
OBJS = main.o bubble_sort.o insertion_sort.o merge_sort.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c bubble_sort.h insertion_sort.h merge_sort.h
	$(CC) $(CFLAGS) -c main.c

bubble_sort.o: bubble_sort.c bubble_sort.h
	$(CC) $(CFLAGS) -c bubble_sort.c

insertion_sort.o: insertion_sort.c insertion_sort.h
	$(CC) $(CFLAGS) -c insertion_sort.c

merge_sort.o: merge_sort.c merge_sort.h
	$(CC) $(CFLAGS) -c merge_sort.c

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
