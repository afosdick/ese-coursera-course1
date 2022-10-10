CFLAGS += --std=c99 -Wall -Wextra -Wshadow -Wdouble-promotion -Wundef -fno-common # -Werror

.PHONY: clean debug profile  minsize

TARGET = stats

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) $? -o $@

# useful for gdb and valgrind
debug: CFLAGS += -g3
debug: $(TARGET)

# $ gprof test gmon.out > prof_output
profile: CFLAGS += -gprof
profile: $(TARGET)

minsize: CFLAGS += -Os -ffunction-sections -fdata-sections --data-sections
minsize: $(TARGET)

clean:
	$(RM) $(TARGET)