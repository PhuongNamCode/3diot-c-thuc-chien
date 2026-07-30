#include "common.h"

// Hàm static: Chỉ được dùng nội bộ trong file này
static int secret_multiplier(int x) {
    return x * 10;
}

// Hàm global: Các file khác có thể gọi
int calculate(int a) {
    return secret_multiplier(a) + 5;
}
