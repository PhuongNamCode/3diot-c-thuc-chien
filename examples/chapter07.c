#include <stdio.h>
#include <stdlib.h>

/* =====================================================================
 * 1. CÁC LOẠI CON TRỎ
 * ===================================================================== */
void demo_pointer_types() {
    printf("--- 1. DEMO CAC LOAI CON TRO ---\n");

    // 1.1 NULL POINTER
    // Không trỏ đến vị trí hợp lệ. Gán NULL để kiểm tra trước khi dùng.
    int *null_ptr = NULL;
    if (null_ptr == NULL) {
        printf("-> NULL Pointer: Con tro dang la NULL, an toan de tranh crash.\n");
    }

    // 1.2 VOID POINTER (Generic pointer)
    // Trỏ đến bất kỳ kiểu dữ liệu nào. Phải ép kiểu trước khi dereference.
    int x = 42;
    void *void_ptr = &x;
    printf("-> Void Pointer: Gia tri sau khi ep kieu = %d\n", *(int*)void_ptr);

    // 1.3 WILD POINTER (Con trỏ hoang)
    // CẢNH BÁO NGUY HIỂM: Chưa được khởi tạo, chứa giá trị rác.
    int *wild_ptr; 
    // *wild_ptr = 100; // Mở comment dòng này sẽ gây lỗi hoặc hỏng dữ liệu (crash).
    printf("-> Wild Pointer: Chua khoi tao, viec truy cap truc tiep vao *wild_ptr la cuc ky nguy hiem.\n");

    // 1.4 DANGLING POINTER (Con trỏ treo)
    // Trỏ đến vùng nhớ đã bị giải phóng hoặc ra khỏi scope.
    int *dangling_ptr = (int*)malloc(sizeof(int));
    *dangling_ptr = 50;
    free(dangling_ptr); 
    // Lúc này dangling_ptr đã trở thành con trỏ treo vì vùng nhớ đã free.
    // *dangling_ptr = 60; // Gây lỗi không xác định.
    dangling_ptr = NULL; // Cách khắc phục: Gán ngay về NULL sau khi free.
    printf("-> Dangling Pointer: Da free() vung nho, can gan ve NULL de an toan.\n\n");
}


/* =====================================================================
 * 2. MẢNG CON TRỎ - Array of Pointers
 * ===================================================================== */
void demo_array_of_pointers() {
    printf("--- 2. DEMO MANG CON TRO ---\n");
    
    // Mảng con trỏ đến chuỗi (Array of strings)
    // Tiết kiệm bộ nhớ so với mảng 2D khi lưu các chuỗi độ dài khác nhau.
    char *languages[] = {
        "C Programming",
        "Python",
        "Java",
        "C++"
    };

    int size = sizeof(languages) / sizeof(languages[0]);
    printf("Danh sach cac ngon ngu lap trinh:\n");
    for (int i = 0; i < size; i++) {
        // languages[i] lưu địa chỉ của từng chuỗi ký tự độc lập
        printf("  %d: %s\n", i + 1, languages[i]);
    }
    printf("\n");
}


/* =====================================================================
 * 3. HẰNG CON TRỎ VÀ CON TRỎ HẰNG
 * ===================================================================== */
void demo_const_pointers() {
    printf("--- 3. DEMO HANG CON TRO VA CON TRO HANG ---\n");
    int var1 = 10;
    int var2 = 20;

    // 3.1 CON TRỎ HẰNG (Pointers to Constant)
    // Khả năng đổi địa chỉ: CÓ | Khả năng đổi giá trị: KHÔNG
    const int *ptr_to_const = &var1;
    // *ptr_to_const = 15; // LỖI: Compiler không cho phép đổi giá trị
    ptr_to_const = &var2;  // HỢP LỆ: Cho phép trỏ sang địa chỉ khác
    printf("-> Con tro hang (const int *p): Khong the doi gia tri, nhung doi duoc dia chi (tro sang var2 = %d).\n", *ptr_to_const);

    // 3.2 HẰNG CON TRỎ (Constant Pointers)
    // Khả năng đổi địa chỉ: KHÔNG | Khả năng đổi giá trị: CÓ
    int *const const_ptr = &var1;
    *const_ptr = 99;       // HỢP LỆ: Thay đổi giá trị tại ô nhớ
    // const_ptr = &var2;  // LỖI: Compiler không cho phép đổi địa chỉ trỏ tới
    printf("-> Hang con tro (int *const p): Doi duoc gia tri (var1 nay = %d), nhung khong the doi dia chi.\n\n", var1);
}


/* =====================================================================
 * 4. CON TRỎ HÀM - Function Pointer
 * ===================================================================== */
// Hàm so sánh mẫu (Ví dụ để dùng cho con trỏ hàm)
int reverse(int a, int b) {
    if (a > b) return 1;
    return 0;
}

void demo_function_pointer() {
    printf("--- 4. DEMO CON TRO HAM ---\n");
    
    // Khai báo con trỏ hàm (Strict Type Check: Chữ ký phải khớp hoàn toàn)
    // Kiểu trả về là 'int', 2 tham số là 'int' và 'int'
    int (*reverseSort)(int, int); 
    
    // Gán con trỏ trỏ tới hàm reverse (Nó sẽ trỏ vào .text segment của bộ nhớ)
    reverseSort = reverse;

    int num1 = 10, num2 = 5;
    // Gọi hàm thông qua con trỏ
    int result = reverseSort(num1, num2); 
    
    printf("-> Function Pointer: Goi reverseSort(%d, %d) tra ve %d.\n", num1, num2, result);
    printf("-> Luu y: Khong dung so hoc con tro voi function pointer (Vi du: reverseSort++ la sai).\n");
}


int main() {
    demo_pointer_types();
    demo_array_of_pointers();
    demo_const_pointers();
    demo_function_pointer();
    
    return 0;
}