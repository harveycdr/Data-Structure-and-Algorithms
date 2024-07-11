Bài tập 1

1. Viết hàm sắp xếp mảng chuỗi
2. Cho mảng cấu trúc gồm Họ, Tên,...
    Viết hàm sắp xếp mảng theo Tên, trùng Tên sắp theo Họ
3. Viết hàm sắp xếp (Interchange sort) dữ liệu kiểu int trên file nhị phân
4. Viết hàm sắp xếp mảng số nguyên bằng phương pháp Natural Mergesort
    void NaturalMergeSort(int a[], int n)
5. Viết hàm sắp xếp file số nguyên bằng p/p merge sort
    void MergeSortFile(char FName[])

//Hàm tạo mảng số nguyên ngẫu nhiên từ l-->r
#include <cstdlib>
#include <ctime>
void CreateRndArr(int a[],int n){
     int const l=0, r=99;
     srand(time(0));
     for (int i=0;i<n;i++)
         a[i]= l+rand()%(r-l+1);
}

==========================================

Bài tập 2

Sắp xếp và tìm kiếm

Viết chương trình quản lý gồm:
1. File dữ liệu SV.dat chứa thông tin sinh viên. gồm (tối thiểu) các trường (field) như sau:
    - maSV:  kiểu văn bản (10 kí tự)
    - ho:  kiểu văn bản (20 kí tự)
    - ten:  kiểu văn bản (10 kí tự)
    - diemTB: kiểu số nguyên
2. Tạo các mảng chỉ mục (INDEX) cho phép xuất danh sách SV theo
   - Thứ tự Mã sinh viên
   - Thứ tự Tên sinh viên, trùng tên sắp theo Họ
   - Thứ tự Điểm
3. Các chức năng sau:
    - Thêm 1 hoặc  nhiều SV vào danh sách SV.
    - Xóa 1 SV ra khỏi d/s (chọn SV cần xóa bằng MASV)
    - Sửa thông tin của 1 SV (chọn SV cần sửa bằng MASV)
    - Tìm 1 SV sau đó in ra thông tin của sinh viên đó ra màn hình (chọn SV bằng MASV)
    - Nhập tên sinh viên, xuất ra màn hình danh sách sinh viên có cùng tên theo thứ tự điểm giảm dần

==========================================

Bài tập 3
Bài tập về danh sách liên kết

Viết chương trình gồm các hàm sau:
- Tạo và nhập tự động các số ngẫu nhiên tử 1-99 vào 1 sách liên kết cài bằng con trỏ
- Sử dụng giải thuật sắp xếp để sắp xếp sao cho thứ tự tăng dần
- Chèn thêm một phần tử (nhập từ bàn phím) vào d/s sao cho giữ nguyên thứ tự.
- Loại bỏ các pt trùng nhau (giữ lại duy nhất 1 pt) trong danh sách
- Lưu d/s vào file
- Đọc d/s từ file

==========================================

Bài tập 4
Bài tập về danh sách liên kết

Viết chương trình quản lý hàng hóa của cửa hàng sử dụng DSLK đơn, mỗi nút của nó gồm các thông tin về mã số, tên mặt hàng, giá bán, số lượng.
- Nhập/xuất dữ liệu cho n mặt hàng.
- Tìm thông tin của mặt hàng có giá bán đắt nhất.
- Thay đổi số lượng của 1 mặt hàng nào đó dựa vào mã số mặt hàng.
- Xóa 1 mặt hàng ra khỏi danh sách dựa vào tên.
- Lưu vào file
- Đọc từ file

==========================================

Bài tập 5
Bài tập về stack

Cài đặt 1 stack bằng con trỏ, ứng dụng stack để 
  a. Đảo ngược 1 danh sách liên kết
  b. Đổi từ thập phân sang các hệ khác.

==========================================

Bài tập 6
Bài tập về queue

Xây dựng CTDL queue cài đặt bằng DSLK để mô phỏng qui trình cho thuê máy ở  một phòng NET với các yêu cầu:
- Danh sách các máy trống A – Dùng kiểu queue, mỗi nút chứa số máy;
- Danh sách khách đang chờ nhận máy Q – Dùng kiểu queue, mỗi nút chứa họ tên người thuê.
- Danh sách khách đang thuê máy H - Dùng kiểu DSLK đơn, mỗi nút có họ tên khách, giờ bắt đầu thuê máy, số máy. 
Các chức năng cần phải có:
- Đăng ký thuê máy: Còn máy trong A thì thêm khách vào H và lấy máy vừa cho thuê ra khỏi queue A. Nếu A trống thì thêm khách vào queue Q.
- Trả máy: Thêm máy trả vào queue A, bỏ người đó khỏi danh sách thuê H. 
- Phục vụ: Kiểm tra A và Q để phục vụ và cập nhật lại A, Q, H.

Hàm lấy giờ hệ thống:
#include <ctime>
...
//Lấy giờ phút
int gio, phut;
time_t now = time(0);
tm *ltm = localtime(&now);
gio=1 + ltm->tm_hour;
phut= 1 + ltm->tm_min;

//Lấy năm tháng ngày
int nam, thang, ngay;
nam= 1900 + ltm->tm_year;
thang= 1 + ltm->tm_mon;
ngay=  ltm->tm_mday ;

==========================================

Bài tập 7
Viết chương trình cài đặt 1 bảng băm bằng pp kết nối trực tiếp 
Trong đó M={0,1,2,...,9} hàm băm h(key)=k%10
và các chức năng sau:
a. Thêm 1 phần tử vào bảng băm (có kiểm tra trùng)
b. Tìm 1 pt trong bảng băm
c. Xoá 1 pt ra khỏi bảng băm

==========================================