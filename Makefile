# ============================================================
# 3DIOT · Makefile gốc — build nhanh một ví dụ bất kỳ
# Dùng: make EX=chapters/01-introduction/examples/hello-world run
# ============================================================
EX ?= chapters/01-introduction/examples/hello-world

.PHONY: all run clean help

all:
	$(MAKE) -C $(EX)

run:
	$(MAKE) -C $(EX) run

clean:
	$(MAKE) -C $(EX) clean

help:
	@echo "Dung: make EX=<duong-dan-vi-du> [run|clean]"
