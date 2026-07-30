#include <stdio.h>
#include <limits.h>   // Chứa các macro giới hạn của kiểu số nguyên (INT_MAX, CHAR_MIN...)
#include <float.h>    // Chứa các macro giới hạn của kiểu số thực (FLT_MAX, DBL_MAX...)
#include <stdbool.h>  // Để sử dụng kiểu bool

// Hàm hỗ trợ in một số 8-bit ra định dạng nhị phân (Binary) để dễ quan sát
void print_binary(unsigned char val) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (val >> i) & 1);
    }
}

// Hàm biểu diễn các toán tử Bitwise và ứng dụng
void demonstrate_bitwise() {
    printf("\n=================================================================================\n");
    printf("                              BITWISE OPERATORS                                  \n");
    printf("=================================================================================\n");

    unsigned char a = 12; // Nhị phân: 0000 1100
    unsigned char b = 10; // Nhị phân: 0000 1010
    unsigned char result;

    printf("Gia tri ban dau:\n");
    printf("a = %3d (Binary: ", a); print_binary(a); printf(")\n");
    printf("b = %3d (Binary: ", b); print_binary(b); printf(")\n\n");

    // 1. BITWISE AND (&)
    result = a & b;
    printf("1. BITWISE AND (&): Tra ve 1 neu ca hai bit la 1.\n");
    printf("   a & b  = %3d (Binary: ", result); print_binary(result); printf(")\n\n");

    // 2. BITWISE OR (|)
    result = a | b;
    printf("2. BITWISE OR (|): Tra ve 1 neu mot trong hai la 1.\n");
    printf("   a | b  = %3d (Binary: ", result); print_binary(result); printf(")\n\n");

    // 3. BITWISE XOR (^)
    result = a ^ b;
    printf("3. BITWISE XOR (^): Tra ve 1 neu hai bit khac nhau.\n");
    printf("   a ^ b  = %3d (Binary: ", result); print_binary(result); printf(")\n\n");

    // 4. BITWISE NOT (~)
    result = ~a;
    printf("4. BITWISE NOT (~): Dao tat ca bit (0 <-> 1).\n");
    printf("   ~a     = %3d (Binary: ", result); print_binary(result); printf(")\n\n");

    // 5. LEFT SHIFT (<<)
    unsigned char n = 2;
    result = a << n;
    printf("5. LEFT SHIFT (<<): Dich trai %d bit (Nhan gia tri voi 2^%d).\n", n, n);
    printf("   a << 2 = %3d (Binary: ", result); print_binary(result); printf(")\n\n");

    // 6. RIGHT SHIFT (>>)
    result = a >> n;
    printf("6. RIGHT SHIFT (>>): Dich phai %d bit (Chia gia tri cho 2^%d).\n", n, n);
    printf("   a >> 2 = %3d (Binary: ", result); print_binary(result); printf(")\n\n");


    printf("---------------------------------------------------------------------------------\n");
    printf("                      UNG DUNG THUC TE TRONG EMBEDDED                            \n");
    printf("---------------------------------------------------------------------------------\n");
    
    unsigned char reg = 0; // Thanh ghi giả lập ban đầu bằng 0 (0000 0000)
    printf("Thanh ghi (reg) ban dau:       "); print_binary(reg); printf("\n");

    // Ứng dụng 1: Set bit (Bật bit) bằng OR (|) và LEFT SHIFT (<<)
    // Ví dụ: Bật bit ở vị trí số 3 (tính từ 0 từ phải qua trái)
    reg = reg | (1 << 3); 
    printf("Set bit 3 (reg | (1 << 3)):    "); print_binary(reg); printf(" -> Bit 3 da duoc bat len 1\n");

    // Ứng dụng 2: Toggle bit (Đảo trạng thái bit) bằng XOR (^)
    // Ví dụ: Đảo trạng thái bit số 3
    reg = reg ^ (1 << 3);
    printf("Toggle bit 3 (reg ^ (1 << 3)): "); print_binary(reg); printf(" -> Bit 3 bi dao ve 0\n");
    reg = reg ^ (1 << 3); // Đảo lại lần nữa
    printf("Toggle bit 3 lan nua:          "); print_binary(reg); printf(" -> Bit 3 duoc dao len 1\n");

    // Ứng dụng 3: Clear bit (Tắt bit) bằng AND (&) và NOT (~)
    // Ví dụ: Tắt bit số 3
    reg = reg & ~(1 << 3);
    printf("Clear bit 3 (reg & ~(1 << 3)): "); print_binary(reg); printf(" -> Bit 3 da bi xoa ve 0\n");

    // Ứng dụng 4: Check bit (Kiểm tra trạng thái) bằng AND (&)
    // Ví dụ: Kiểm tra xem bit số 3 có đang bật không
    reg = reg | (1 << 3); // Bật lại bit 3 để test
    if ((reg & (1 << 3)) != 0) {
        printf("\nKiem tra (reg & (1 << 3)):     -> Bit 3 dang o trang thai HIGH (1)\n");
    } else {
        printf("\nKiem tra (reg & (1 << 3)):     -> Bit 3 dang o trang thai LOW (0)\n");
    }
    printf("=================================================================================\n");
}

// Hàm biểu diễn 5 nhóm toán tử cơ bản trong C
void demonstrate_operators() {
    printf("\n=================================================================================\n");
    printf("                              5 NHOM TOAN TU (OPERATORS)                         \n");
    printf("=================================================================================\n");

    int a = 10;
    int b = 3;
    printf("Gia tri khoi tao ban dau: a = %d, b = %d\n\n", a, b);

    // 1. Nhóm Toán tử Số học (Arithmetic)
    printf("--- 1. Nhom Toan tu So hoc (Arithmetic) ---\n");
    printf("a + b = %d\n", a + b);
    printf("a / b = %d  (Phep chia nguyen, bo phan thap phan)\n", a / b);
    printf("a %% b = %d  (Phep chia lay du / Modulo)\n", a % b);
    
    int c = a++; // Hậu tố (Postfix): gán c = a (10), sau đó mới tăng a lên 11
    printf("c = a++ -> c = %d, a hien tai = %d (Hau to / Postfix)\n", c, a);
    
    int d = ++b; // Tiền tố (Prefix): tăng b lên 4, sau đó gán d = b (4)
    printf("d = ++b -> d = %d, b hien tai = %d (Tien to / Prefix)\n\n", d, b);

    // Reset lại giá trị cho các phần sau dễ theo dõi
    a = 10; b = 3; 

    // 2. Nhóm Toán tử Quan hệ (Relational)
    // Trả về 1 nếu Đúng (True), 0 nếu Sai (False)
    printf("--- 2. Nhom Toan tu Quan he (Relational) ---\n");
    printf("a == b : %d (False)\n", a == b);
    printf("a != b : %d (True)\n", a != b);
    printf("a >= 10: %d (True)\n\n", a >= 10);

    // 3. Nhóm Toán tử Logic (Logical)
    printf("--- 3. Nhom Toan tu Logic (Logical) ---\n");
    // && (AND) yêu cầu cả 2 vế đều đúng
    printf("(a > 5) && (b < 5) : %d (True AND True   -> True)\n", (a > 5) && (b < 5));
    // || (OR) chỉ cần 1 trong 2 vế đúng
    printf("(a < 5) || (b < 5) : %d (False OR True   -> True)\n\n", (a < 5) || (b < 5));

    // 4. Nhóm Toán tử Gán (Assignment)
    printf("--- 4. Nhom Toan tu Gan (Assignment) ---\n");
    int x = 5;
    printf("Khoi tao: x = 5\n");
    x += 3; // Tương đương: x = x + 3
    printf("x += 3  -> x tro thanh: %d\n", x);
    x *= 2; // Tương đương: x = x * 2
    printf("x *= 2  -> x tro thanh: %d\n\n", x);

    // 5. Nhóm Khác (Other)
    printf("--- 5. Nhom Toan tu Khac (Other) ---\n");
    
    // a. Toán tử sizeof: Lấy kích thước bộ nhớ
    printf("sizeof(a) = %lu bytes\n", (unsigned long)sizeof(a));
    
    // b. Toán tử 3 ngôi (Ternary operator) - ?:
    // Cú pháp: (Điều_kiện) ? Giá_trị_nếu_đúng : Giá_trị_nếu_sai
    int max = (a > b) ? a : b;
    printf("Toan tu 3 ngoi (a > b ? a : b) -> max = %d\n", max);
    
    // c. Toán tử dấu phẩy (Comma operator)
    // Tính toán từ trái sang phải, nhưng kết quả trả về là biểu thức cuối cùng (bên phải)
    int y = (x = 1, x + 5); 
    printf("Toan tu dau phay: y = (x = 1, x + 5) -> y = %d, x = %d\n", y, x);

    printf("=================================================================================\n");
}

void demonstrate_datatypes() {
    printf("\n=================================================================================\n");
    printf("                                   KIEU DU LIEU                                  \n");
    printf("=================================================================================\n");
    printf("====================================================================================================\n");
    printf("%-10s | %-10s | %-30s | %-25s | %-15s\n", 
           "KIEU", "KICH THUOC", "DAI GIA TRI (SIGNED)", "DAI GIA TRI (UNSIGNED)", "FORMAT");
    printf("====================================================================================================\n");

    // 1. Kiểu char
    printf("%-10s | %lu byte    | %-14d -> %-13d | %d -> %-20d | %%c . %%d\n",
           "char", sizeof(char), SCHAR_MIN, SCHAR_MAX, 0, UCHAR_MAX);

    // 2. Kiểu short
    printf("%-10s | %lu byte    | %-14d -> %-13d | %d -> %-20d | %%hd . %%hu\n",
           "short", sizeof(short), SHRT_MIN, SHRT_MAX, 0, USHRT_MAX);

    // 3. Kiểu int
    printf("%-10s | %lu byte    | %-14d -> %-13d | %d -> %-20u | %%d . %%u\n",
           "int", sizeof(int), INT_MIN, INT_MAX, 0, UINT_MAX);

    // 4. Kiểu long (Lưu ý: Trên Windows x86_64 long là 4 bytes, trên Linux/macOS là 8 bytes)
    printf("%-10s | %lu byte    | %-14ld -> %-13ld | %d -> %-20lu | %%ld . %%lu\n",
           "long", sizeof(long), LONG_MIN, LONG_MAX, 0, ULONG_MAX);

    // 5. Kiểu float
    printf("%-10s | %lu byte    | +-%-12.1e -> +-%-10.1e | %-25s | %%f . %%.2f\n",
           "float", sizeof(float), FLT_MIN, FLT_MAX, "---");

    // 6. Kiểu double
    printf("%-10s | %lu byte    | +-%-12.1e -> +-%-10.1e | %-25s | %%lf\n",
           "double", sizeof(double), DBL_MIN, DBL_MAX, "---");

    // 7. Kiểu bool
    printf("%-10s | %lu byte    | %-30s | %-25s | %%d\n",
           "bool", sizeof(bool), "true (1) | false (0)", "---");

    printf("====================================================================================================\n\n");

    // === VÍ DỤ VỀ TRÀN SỐ (OVERFLOW) NHƯ TRONG ẢNH CÓ NHẮC ĐẾN ===
    printf("--- VI DU VE TRAN SO (OVERFLOW) ---\n");
    char c = 127; // Giá trị lớn nhất của signed char
    printf("Gia tri khoi tao cua char c = %d\n", c);
    
    c = c + 1;    // Vượt quá giới hạn 127
    printf("Sau khi cong them 1 (c = c + 1), gia tri cua c = %d (Bi tran so / Overflow)\n", c);
}

#include <stdio.h>

// ============================================================================
// HÀM 1: MINH HỌA CẤU TRÚC RẼ NHÁNH (if-else, switch-case)
// ============================================================================
void demonstrate_branching() {
    printf("\n=================================================================================\n");
    printf("                       1. CAU TRUC RE NHANH (BRANCHING)                          \n");
    printf("=================================================================================\n");

    // --- Ví dụ 1: Cấu trúc if - else if - else ---
    printf("--- Vi du if-else (Phan loai diem) ---\n");
    int score = 75;
    printf("Diem so hien tai: %d\n", score);
    
    if (score >= 85) {
        printf("=> Ket qua: Loai Gioi\n");
    } else if (score >= 70) {
        printf("=> Ket qua: Loai Kha\n"); // Điều kiện này sẽ khớp với score = 75
    } else if (score >= 50) {
        printf("=> Ket qua: Loai Trung Binh\n");
    } else {
        printf("=> Ket qua: Yeu (Truot)\n");
    }

    // --- Ví dụ 2: Cấu trúc switch-case ---
    // switch-case thường dùng để rẽ nhánh khi so sánh bằng (==) với các hằng số nguyên
    printf("\n--- Vi du switch-case (Xu ly ma lenh thiet bi) ---\n");
    int command = 2; // Giả lập nhận được mã lệnh số 2
    printf("Ma lenh (command) nhan duoc: %d\n", command);
    
    switch (command) {
        case 1:
            printf("=> Hanh dong: BAT (TURN ON) thiet bi.\n");
            break; // Lệnh break giúp thoát khỏi switch, nếu không nó sẽ chạy tuột xuống case 2
        case 2:
            printf("=> Hanh dong: TAT (TURN OFF) thiet bi.\n");
            break;
        case 3:
            printf("=> Hanh dong: KHOI DONG LAI (RESTART).\n");
            break;
        default:
            // default chạy khi không có case nào khớp
            printf("=> Hanh dong: Ma lenh khong hop le, bo qua!\n");
            break; 
    }
    printf("=================================================================================\n");
}


// ============================================================================
// HÀM 2: MINH HỌA CẤU TRÚC VÒNG LẶP (for, while, do-while)
// ============================================================================
void demonstrate_loops() {
    printf("\n=================================================================================\n");
    printf("                           2. VONG LAP (LOOPS)                                   \n");
    printf("=================================================================================\n");

    // --- 1. Vòng lặp FOR ---
    // Dùng khi bạn BIẾT TRƯỚC số lần lặp. Cú pháp: for (khởi tạo; điều kiện; cập nhật)
    printf("--- 1. Vong lap FOR (In chuoi 3 lan) ---\n");
    for (int i = 1; i <= 3; i++) {
        printf("   Vong lap for - Lan chay thu %d\n", i);
    }

    // --- 2. Vòng lặp WHILE ---
    // Dùng khi kiểm tra điều kiện TRƯỚC khi chạy. Số lần lặp có thể chưa biết trước.
    printf("\n--- 2. Vong lap WHILE (Dem nguoc) ---\n");
    int count = 3;
    while (count > 0) {
        printf("   Dem nguoc: %d...\n", count);
        count--; // Rất quan trọng: Phải cập nhật biến để tránh "vòng lặp vô hạn" (infinite loop)
    }
    printf("   => BOOM! Ket thuc dem nguoc.\n");

    // --- 3. Vòng lặp DO-WHILE ---
    // Đặc điểm: Luôn chạy khối lệnh ÍT NHẤT 1 LẦN, SAU ĐÓ mới kiểm tra điều kiện.
    // Rất hay dùng cho việc in Menu lựa chọn hoặc bắt người dùng nhập lại mật khẩu.
    printf("\n--- 3. Vong lap DO-WHILE (Thu nhap mat khau) ---\n");
    int attempt = 0;
    int max_attempts = 1; // Giả lập chỉ cho phép thử 1 lần
    
    do {
        attempt++;
        printf("   Hien thi man hinh nhap mat khau... (Lan thu %d)\n", attempt);
        // Giả sử người dùng nhập sai, điều kiện dưới đây sẽ kiểm tra
    } while (attempt < max_attempts);
    
    printf("   => Da thoat khoi vong lap do-while.\n");
    printf("=================================================================================\n");
}

int main() {
    
    demonstrate_datatypes();

    demonstrate_bitwise();

    demonstrate_operators();

    demonstrate_branching();
    demonstrate_loops();

    return 0;
}