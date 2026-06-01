# Quy trình Git cho khóa học

## Học viên — vòng đời một bài tập
```
fork → clone → branch → code → commit → push → Pull Request → review → merge
```

1. **Fork** repo `3diot-c-baitap-template` về tài khoản của bạn.
2. **Clone** bản fork:
   ```bash
   git clone git@github.com:<ban>/3diot-c-baitap-template.git
   cd 3diot-c-baitap-template
   ```
3. **Tạo branch** cho bài:
   ```bash
   git checkout -b bai/chuong-07-bai-01
   ```
4. **Code** trong thư mục `chuong-07/bai-01/src/`.
5. **Commit** theo Conventional Commits:
   ```bash
   git add .
   git commit -m "feat(ch07): hoan thanh bai 01 con tro"
   ```
6. **Push** & mở **Pull Request** để mentor review.

## Lệnh Git hay dùng
```bash
git status            # xem trạng thái
git log --oneline     # lịch sử commit gọn
git diff              # xem thay đổi chưa stage
git pull --rebase     # cập nhật từ remote
```
