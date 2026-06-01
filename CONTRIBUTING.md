# Hướng dẫn đóng góp (CONTRIBUTING)

## Quy ước commit — Conventional Commits
Định dạng: `<type>(<scope>): <mô tả ngắn>`

| type | Khi nào dùng |
|------|--------------|
| `feat` | Thêm tính năng / ví dụ mới |
| `fix` | Sửa lỗi |
| `docs` | Sửa tài liệu, README |
| `style` | Format code (không đổi logic) |
| `refactor` | Tái cấu trúc code |
| `test` | Thêm / sửa test |
| `chore` | Việc lặt vặt, cấu hình |
| `build` | Thay đổi Makefile / toolchain |

`scope` = chương liên quan, ví dụ `ch07`, `ch12`.

**Ví dụ:**
```
feat(ch07): them vi du con tro ham callback
fix(ch04): sua loi tran mang trong bai chuoi
docs(ch02): bo sung huong dan pull request
```

## Quy ước branch
- `main` — nhánh ổn định, đã review.
- `dev` — nhánh tích hợp.
- `feature/<scope>-<mô-tả>` — tính năng/ví dụ mới.
- `fix/<scope>-<mô-tả>` — sửa lỗi.

## Quy trình
1. Tạo branch từ `dev`.
2. Commit theo Conventional Commits.
3. Mở Pull Request vào `dev`.
4. Mentor review → merge.
