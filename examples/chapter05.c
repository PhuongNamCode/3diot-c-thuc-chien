#include <stdio.h>
#include "common.h"


// Hàm nhận vào "bản sao" của a và b
// void swapThamTri(int a, int b) {
//     int temp = a;  // Đổ nước từ cốc sao chép A sang cốc trung gian
//     a = b;         // Đổ nước từ cốc sao chép B sang cốc sao chép A
//     b = temp;      // Đổ nước từ cốc trung gian sang cốc sao chép B
    
//     // Nếu in ra ở đây, a và b đã được đổi. Nhưng đây chỉ là bản sao!
// }

// Hàm nhận vào "địa chỉ" (con trỏ) của a và b
// void swapThamChieu(int *a, int *b) {
//     // Dùng dấu * để "mở khóa" địa chỉ, lấy giá trị thật
//     int temp = *a;   // Lấy giá trị thật tại địa chỉ a, cất vào biến tạm
//     *a = *b + 10;         // Lấy giá trị tại địa chỉ b, ghi đè lên địa chỉ a
//     *b = temp;       // Lấy giá trị từ biến tạm, ghi đè lên địa chỉ b
// }

// int main() {
//     printf("Tính toán: %d\n", calculate(5));
    
//     // printf("%d", secret_multiplier(5));


//     // int x = 10, y = 20;
    
//     // printf("TRƯỚC KHI ĐỔI: x = %d, y = %d\n", x, y);

//     // swapThamTri(x, y);  // Gọi hàm swapThamTri với bản sao của x và y
//     // printf("SAU KHI ĐỔI (Tham trị): x = %d, y = %d\n", x, y);

//     // BẮT BUỘC dùng dấu & để lấy địa chỉ của x và y truyền vào hàm
//     // swapThamChieu(&x, &y); 
//     // Kết quả: x và y đã được tráo đổi giá trị cho nhau
//     // printf("SAU KHI ĐỔI (Tham chiếu): x = %d, y = %d\n", x, y);


//     return 0;
// }


// 1. MACRO LỖI (Thiếu độ ưu tiên)
#define MULTIPLY_BAD(x, y) x * y

// 2. MACRO AN TOÀN (Bọc ngoặc chống trôi độ ưu tiên)
#define MULTIPLY_GOOD(x, y) ((x) * (y))

#define FOR_LOOP(i, n) for (int i = 0; i < (n); i++)

// 3. INLINE FUNCTION (Hàm thực sự, trình biên dịch tự lo độ ưu tiên)
static inline int multiply_inline(int x, int y) {
    return x * y;
}

int main() {
    int a = 5;
    int b = 2;
    int c = 3;
    int d = 4;

    printf("Bài toán: Tính (a + b) * (c + d) tuc la (5 + 2) * (3 + 4) = 7 * 7 = 49\n\n");

    // --- TRƯỜNG HỢP 1: MACRO LỖI ---
    // Trình tiền xử lý thay thế thành: a + b * c + d
    // Toán học: 5 + (2 * 3) + 4 = 5 + 6 + 4 = 15 (SAI!)
    int res1 = MULTIPLY_BAD(a + b, c + d);
    printf("1. MULTIPLY_BAD: %d\n", res1); 

    // --- TRƯỜNG HỢP 2: MACRO AN TOÀN ---
    // Trình tiền xử lý thay thế thành: ((a + b) * (c + d))
    // Toán học: (5 + 2) * (3 + 4) = 7 * 7 = 49 (ĐÚNG)
    int res2 = MULTIPLY_GOOD(a + b, c + d);
    printf("2. MULTIPLY_GOOD: %d\n", res2);

    // --- TRƯỜNG HỢP 3: INLINE FUNCTION ---
    // Trình biên dịch tính toán (a + b) = 7, (c + d) = 7 trước.
    // Sau đó chèn mã máy: 7 * 7 = 49 (ĐÚNG, AN TOÀN TUYỆT ĐỐI)
    int res3 = multiply_inline(a + b, c + d);
    printf("3. Inline function: %d\n", res3);

    // --- TRƯỜNG HỢP 4: FOR LOOP ---
    printf("\n4. FOR_LOOP:\n");
    FOR_LOOP(i, 5) {
        printf("i = %d\n", i);
    }

    return 0;
}
