## Đề bài

### Tóm tắt nội dung
Tính số cách để đổi *n* phiếu thưởng lấy các món quà với giá từ 1 đến *k*.

### Sample Input
5 3

### Sample Output
5

### Giải thích
Input gồm 2 số tương ứng với *n* phiếu thưởng và mức giá *k*.
Output là số cách đổi quà.

Có 5 cách:  
Số trong mỗi ô là số quà tương ứng với mức giá của cột.  

|        | giá = 1 | giá = 2 | giá = 3 |
|--------|-----------|-----------|-----------|
| Cách 1 | 0         | 1         | 1         |
| Cách 2 | 1         | 2         | 0         |
| Cách 3 | 2         | 0         | 1         |
| Cách 4 | 3         | 1         | 0         |
| Cách 5 | 5         | 0         | 0         |

Cách 1: Lấy 2 phiếu đổi quà giá 2; lấy 3 phiếu còn lại đổi quà giá 3.  
Cách 2: Lấy 1 phiếu đổi quà giá 1; lấy 4 phiếu còn lại đổi quà giá 2.  
Cách 3: Lấy 2 phiếu đổi quà giá 1; lấy 3 phiếu còn lại đổi quà giá 3.  
Cách 4: Lấy 3 phiếu đổi quà giá 1; lấy 2 phiếu còn lại đổi quà giá 2.  
Cách 5: Lấy 5 phiếu đổi quà giá 1.

## Ý tưởng

**Bước 1**
Khai báo mảng hai chiều *d*, với *d[p][g]* là số cách lấy *p* phiếu đổi quà giá từ 1 đến *g*.  
Nói cách khác: *p* phiếu, ứng với hàng, *g* giá ứng với cột.  

**Bước 2**
Khởi tạo cột 1 đều là 1 cách, vì với mức giá g = 1, chỉ có duy nhất 1 cách đổi quà cho mọi số phiếu.

**Bước 3**
Duyệt mảng *d* theo hàng *p* và cột *g*, lần lượt điền các giá trị vào ô *d[p][g]*.  

Nếu p < g, nghĩa là số phiếu < mức giá, thì không đủ phiếu để đổi quà giá cao, tức không có cách đổi. Do đó, số cách vẫn như cũ: *d[p][g]  =  d[p][g  -  1]*.  

Nếu p = g, số phiếu = mức giá, thì ngoài số cách cũ, có thêm 1 cách là lấy hết *p* phiếu đổi quà giá *g*. Do đó, số cách là *d[p][g]  =  d[p][g  -  1]  +  1*.  

Nếu p > g, số phiếu > mức giá, ta chia làm 2 nhóm:  

-- Trường hợp 1: Số cách mà trong đó, không đổi quà giá *g*.  
Không lấy quà giá g đồng nghĩa là chỉ lấy quà có giá từ *g - 1* trở xuống.  
Do đó, số cách của trường hợp 1 là *d[p][g  -  1]*.  

-- Trường hợp 2: Số cách mà trong đó, có đổi quà giá *g*.  
Mỗi cách trong trường hợp này đều có ít nhất một phần quà giá *g*.  
Nếu trong mỗi cách, ta bỏ bớt một phần quà giá *g* này ra, thì số cách cũng không thay đổi. Điều này tương đương với việc lấy *p - g* phiếu còn lại đổi quà giá từ 1 đến *g*.  

Ví dụ: Với 7 phiếu và mức giá cao nhất là 3, ta có những cách sau:  
7 = 3 + 4  
7 = 3 + 2 + 2  
7 = 3 + ...  

Số 3 đầu tiên của mỗi cách là 3 phiếu (để đổi một phần quà). Nếu bỏ bớt 3 phiếu này ra, còn 7 - 3 = 4 phiếu, ta tìm cách phân phối 4 phiếu này để đổi quà giá từ 1 đến 3.  

Do đó, số cách của trường hợp 2 là *d[p - g][g]*.  

Như vậy, khi p > g thì số cách = trường hợp 1 + trường hợp 2.  
Nghĩa là, *d[p][g]  =  d[p][g  -  1]  +  d[p  -  g][g]*.  

**Bước 4**
Output chính là phần tử cuối cùng của mảng *d*, tức *d[n][k]*.