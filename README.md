# DoAnGiaiThuat
Học từ vựng tiếng anh thông qua trò chơi
Mô tả đề tài: Xây dựng trò chơi đố chữ đơn giản để giúp người chơi củng cố từ
vựng trong Tiếng Anh.

Yêu cầu:
Về lý thuyết: - Nắm vững cơ sở lý thuyết về cấu trúc dữ liệu, đặc biệt là cấu trúc
bảng băm và các kỹ thuật lưu trữ ngoài. Vận dụng các lý thuyết này vào cài đặt tự điển.
Về lập trình:
Các chức năng chính của chương trình :
- Thêm từ vựng: cho phép thêm từ vựng mới vào trong tự điển và lưu tự điển vào
tập tin. Với mỗi từ trong tự điển cần lưu trữ các thông tin về loại từ (danh từ, động từ,...),
phiên âm quốc tế và các nghĩa có thể có của từ.
- Hiển thị & cập nhật tự điển: Hiển thị danh sách các từ có trong tự điển để kiểm
tra. Sau khi hiển thị, người dùng có thể thực hiện các thao tác sau:
+ Hiển thị thông tin chi tiết của một từ vựng.
+ Sửa thông tin chi tiết của một từ vựng.
+ Xóa một từ vựng nào đó.
- Chơi trò chơi đố chữ: Chương trình chọn ngẫu nhiên một từ vựng nào đó, xóa
một cách ngẫu nhiên một ký tự trong từ và yêu cầu người chơi nhập vào ký tự bị thiếu.
Nếu người chơi nhập vào một ký tự làm thành một từ hợp lệ (nghĩa là có trong tự điển)
thì chương trình hiển thị thông tin về từ đó, người chơi sẽ được tính điểm. Còn nếu người
chơi nhập vào ký tự không làm thành từ hợp lệ, thì chương trình sẽ hiển thị thông báo
lỗi: ‘Không có từ này trong tiếng Anh’
Ví dụ: Chương trình hiển thị từ c_t:
- Nếu người chơi nhập vào chữ u thì sẽ tạo thành từ cut, khi đó chương trình sẽ
hiển thị thông tin về từ cut và tính điểm cho người chơi.
- Hoặc nếu người chơi nhập vào chữ a thì sẽ tạo thành từ cat, khi đó chương
trình sẽ hiển thị thông tin về từ cat và tính điểm cho người chơi.
- Hoặc nếu người chơi nhập vào chữ i thì sẽ tạo thành từ cit, thì chương trình sẽ
hiển thị thông báo lỗi: ‘Không có từ này trong tiếng Anh’.

Môi trường cài đặt : C, C ++
