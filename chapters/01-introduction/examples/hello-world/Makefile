# ============================================================
# 3DIOT · Makefile mẫu cho một bài / ví dụ C
# Dùng:  make        -> biên dịch
#        make run    -> biên dịch & chạy
#        make clean  -> xóa file build
# ============================================================
CC      := gcc
CFLAGS  := -Wall -Wextra -std=c11 -g
SRC_DIR := src
OBJ_DIR := build
TARGET  := program

SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

run: all
	./$(TARGET)

clean:
	rm -rf $(OBJ_DIR) $(TARGET)
