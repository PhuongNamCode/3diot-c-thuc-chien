#!/usr/bin/env bash
# Tạo nhanh khung một bài tập mới.
# Dùng: ./scripts/new-exercise.sh chapters/07-pointer/exercises/bai-02
set -e
DIR="$1"
if [ -z "$DIR" ]; then echo "Dung: $0 <duong-dan-bai>"; exit 1; fi
mkdir -p "$DIR/src"
cat > "$DIR/src/main.c" <<'EOF'
#include <stdio.h>

int main(void) {
    printf("3DIOT - bai tap moi\n");
    return 0;
}
EOF
echo "Da tao khung tai: $DIR"
