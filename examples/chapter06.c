#include <stdio.h>
#include <stdlib.h>


// 1. .BSS (Block Started by Symbol): Chứa biến toàn cục/static chưa khởi tạo (hoặc gán = 0).
int global_uninit_var;               // Đi vào .bss (Tự động được khởi tạo bằng 0)
int global_zero_var = 0;             // Đi vào .bss (Vì giá trị là 0)

// 2. .DATA: Chứa biến toàn cục/static đã được khởi tạo giá trị khác 0.
int global_init_var = 42;            // Đi vào .data

// 3. .RODATA (Read-Only Data): Chứa hằng số toàn cục và chuỗi ký tự.
const int global_const_var = 100;    // Đi vào .rodata (Không thể thay đổi)

// Bản thân chuỗi "Hello World" nằm ở .rodata.
// Nhưng biến con trỏ 'global_str' (lưu địa chỉ của chuỗi) lại nằm ở .data.
char *global_str = "Hello World";    


// Mã lệnh của hàm này (các instruction) sẽ được lưu ở .text segment.
void demo_function(int arg_var) {    // 'arg_var' (tham số) được đẩy vào STACK
    // ... mã lệnh ...
}

int main() {
    // Bản thân mã lệnh của hàm main() cũng nằm ở .text segment.
       
    // Các biến cục bộ khai báo bên trong hàm sẽ nằm ở Stack.
    // Stack sẽ tự động giải phóng khi hàm kết thúc.
    int local_var = 10;
    
    // Bản thân mảng này và dữ liệu "C-Lang" của nó đều copy vào Stack.
    char local_array[] = "C-Lang";
       
    // Mặc dù khai báo trong hàm, nhưng từ khóa 'static' đưa chúng ra khỏi Stack.
    static int local_static_uninit;  // Đi vào .bss
    static int local_static_init = 5;// Đi vào .data
       
    // 1. 'heap_ptr' là một biến con trỏ cục bộ -> Nằm ở STACK.
    // 2. malloc(100) xin hệ điều hành 100 bytes -> Vùng nhớ 100 bytes này nằm ở HEAP.
    // KL: STACK đang lưu một con trỏ trỏ tới một địa chỉ trên HEAP.
    void *heap_ptr = malloc(100);    
       
    demo_function(local_var);

    // Giải phóng Heap
    free(heap_ptr);

    /// ==========================================

    // 1. Cấp phát 3 khối bộ nhớ liên tiếp trên Heap
    void *khối_A = malloc(100); // Chiếm 100 bytes
    void *khối_B = malloc(100); // Chiếm 100 bytes
    void *khối_C = malloc(100); // Chiếm 100 bytes

    free(khối_B);
    // LÚC NÀY: Giữa A và C có một khoảng trống 100 bytes (một cái hố).

    // 3. Yêu cầu một khối D cần 150 bytes
    void *khối_D = malloc(150);
    
    // KẾT QUẢ: Khối D KHÔNG THỂ nhét vừa vào "cái hố" 100 bytes của B.
    // Hệ điều hành phải đi tìm một khoảng trống khác lớn hơn ở cuối Heap.
    // Khoảng trống 100 bytes ở giữa sẽ bị lãng phí mãi mãi nếu chương trình 
    // không bao giờ yêu cầu khối nào <= 100 bytes nữa. Đây là phân mảnh!

    free(khối_A); free(khối_C); free(khối_D);

    return 0;
}