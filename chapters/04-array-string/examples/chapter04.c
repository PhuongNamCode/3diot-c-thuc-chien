#include <stdio.h>
#include <string.h>

void demonstrate_arrays_strings() {
    printf("\n=================================================================================\n");
    printf("                    3. MANG (ARRAYS) & CHUOI (STRINGS)                           \n");
    printf("=================================================================================\n");

    // --- 1. MẢNG 1 CHIỀU (1D ARRAY) ---
    printf("--- 1. Mang 1 Chieu (1D Array) ---\n");
    // Khởi tạo một mảng số nguyên gồm 5 phần tử
    int numbers[5] = {10, 25, 40, 55, 70}; 
    
    // Tính số lượng phần tử trong mảng: Tổng kích thước mảng / kích thước 1 phần tử
    int length_1d = sizeof(numbers) / sizeof(numbers[0]); 
    printf("So luong phan tu cua mang: %d\n", length_1d);
    
    printf("Cac phan tu trong mang: ");
    for (int i = 0; i < length_1d; i++) {
        printf("%d ", numbers[i]);
    }
    
    // Cập nhật giá trị phần tử (index bắt đầu từ 0)
    numbers[2] = 99; 
    printf("\nSau khi doi gia tri phan tu index [2] thanh 99: \n");
    printf("numbers[2] = %d\n\n", numbers[2]);


    // --- 2. CHUỖI KÝ TỰ (STRING) ---
    // Trong C, chuỗi bản chất là một mảng 1 chiều chứa các ký tự (char) 
    // và LUÔN kết thúc bằng ký tự null '\0'.
    printf("--- 2. Chuoi ky tu (String) ---\n");
    
    // Cách 1: Khởi tạo chuỗi gán trực tiếp
    char greeting[] = "Hello 3D IOT"; 
    printf("Chuoi greeting: %s\n", greeting);
    printf("Do dai chuoi (khong tinh '\\0'): %lu ky tu\n", (unsigned long)strlen(greeting));

    // Cách 2: Khởi tạo mảng char giới hạn kích thước và dùng hàm strcpy để copy dữ liệu
    char buffer[50];
    strcpy(buffer, "Lap trinh C cho Embedded");
    printf("Chuoi buffer sau khi copy: %s\n\n", buffer);


    // --- 3. MẢNG 2 CHIỀU (2D ARRAY) ---
    // Mảng 2 chiều có thể hình dung như một ma trận có HÀNG (Rows) và CỘT (Columns)
    printf("--- 3. Mang 2 Chieu (2D Array / Matrix) ---\n");
    
    // Khởi tạo ma trận 2 hàng, 3 cột
    int matrix[2][3] = {
        {1, 2, 3},  // Hàng 0 (Index 0)
        {4, 5, 6}   // Hàng 1 (Index 1)
    };

    int rows = 2;
    int cols = 3;

    printf("Hien thi ma tran %dx%d:\n", rows, cols);
    // Cần 2 vòng lặp lồng nhau (nested loops) để duyệt mảng 2 chiều
    for (int i = 0; i < rows; i++) {         // Vòng lặp duyệt Hàng
        for (int j = 0; j < cols; j++) {     // Vòng lặp duyệt Cột
            printf("[%d][%d] = %d\t", i, j, matrix[i][j]);
        }
        printf("\n"); // Xuống dòng sau khi in hết 1 hàng
    }

    printf("=================================================================================\n");
}

void main() {
    demonstrate_arrays_strings();
}