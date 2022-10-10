CFLAGS += --std=c99 -Wall -Wextra -Wshadow -Wdouble-promotion -Wundef -fno-common # -Werror
CC = gcc

.PHONY: clean debug profile  minsize

TARGET = stats

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) $? -o $@

# useful for gdb and valgrind
debug: CFLAGS += -g3
debug: $(TARGET)

# $ ./stats
# $ gprof stats gmon.out > prof_output
profile: CFLAGS += -pg
profile: $(TARGET)

minsize: CFLAGS += -Os -ffunction-sections -fdata-sections --data-sections
minsize: $(TARGET)

clean:
	$(RM) $(TARGET) *.out *.o prof_output