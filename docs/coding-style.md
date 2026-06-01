# Quy ước code & đặt tên

## Đặt tên file / thư mục
| Đối tượng | Quy ước | Ví dụ |
|-----------|---------|-------|
| Thư mục chương | `NN-kebab-case` | `07-pointer` |
| File nguồn | `snake_case.c` | `linked_list.c` |
| File header | `snake_case.h` | `gpio_driver.h` |
| Thư mục bài tập | `bai-NN` | `bai-03` |

## Đặt tên trong code
| Đối tượng | Quy ước | Ví dụ |
|-----------|---------|-------|
| Hàm | `snake_case` | `uart_init()` |
| Biến | `snake_case` | `buffer_len` |
| Hằng / Macro | `UPPER_SNAKE` | `MAX_BUFFER` |
| Kiểu (typedef) | `snake_case_t` | `point_t` |
| Header guard | `UPPER_SNAKE_H` | `LINKED_LIST_H` |

## Định dạng
- Thụt lề 4 space (Makefile dùng tab).
- Mở ngoặc `{` cùng dòng với hàm/khối.
- Luôn `-Wall -Wextra` khi biên dịch.
