

#include "Linkedlist.h"

using namespace std;

class SoNguyenLon
{
private:
    static const int BASE = 1000000000; // 1e9
    Linkedlist<int> digits;             // mỗi node 1 block 9 số
    int size;                           // số block

    void remove_leading_zeros();
    void clear();

public:
    SoNguyenLon();
    SoNguyenLon(long long x);
    SoNguyenLon(int digit, int count);
    SoNguyenLon(const SoNguyenLon &other);

    bool operator>=(const SoNguyenLon &other) const;
    SoNguyenLon operator+(const SoNguyenLon &other) const;
    SoNguyenLon operator-(const SoNguyenLon &other) const;
    SoNguyenLon operator*(const SoNguyenLon &other) const;
    SoNguyenLon &operator=(const SoNguyenLon &other);

    friend SoNguyenLon operator+(long long x, const SoNguyenLon &b);
    friend SoNguyenLon operator-(long long x, const SoNguyenLon &b);
    friend SoNguyenLon operator+(const SoNguyenLon &a, long long x);
    friend SoNguyenLon operator-(const SoNguyenLon &a, long long x);

    friend ostream &operator<<(ostream &out, const SoNguyenLon &n);
};

// ------------------- Định nghĩa hàm ngoài class -------------------

void SoNguyenLon::remove_leading_zeros()
{
    while (size > 1 && digits[0] == 0)
    {
        digits.removeHead();
        size--;
    }
}

void SoNguyenLon::clear()
{
    while (this->size > 0)
    {
        digits.removeHead();
        this->size--;
    }
}
SoNguyenLon::SoNguyenLon()
{
    digits.addHead(0);
    size = 1;
}

SoNguyenLon::SoNguyenLon(long long x)
{
    size = 0;
    if (x == 0)
    {
        digits.addHead(0);
        size = 1;
        return;
    }

    while (x > 0)
    {
        int block = x % BASE;
        digits.addHead(block);
        x /= BASE;
        size++;
    }
}

SoNguyenLon::SoNguyenLon(int digit, int count)
{
    // 1. Chuẩn hóa input
    if (digit < 0)
        digit = 0;
    if (digit > 9)
        digit = 9;

    if (count <= 0)
    {
        digits.addHead(0);
        size = 1;
        return;
    }
    size = 0;

    // 2. Tính toán các block
    int num_full_blocks = count / 9;
    int remaining_digits = count % 9;

    // 3. Tạo giá trị cho block đầy (ví dụ: 777,777,777)
    long long full_block_value = 0;
    long long power_of_10 = 1;
    for (int i = 0; i < 9; i++)
    {
        full_block_value += digit * power_of_10;
        power_of_10 *= 10;
    }

    // 4. Tạo giá trị cho block lẻ (ví dụ: 777 nếu remaining_digits = 3)
    if (remaining_digits > 0)
    {
        long long rem_block_value = 0;
        power_of_10 = 1;
        for (int i = 0; i < remaining_digits; i++)
        {
            rem_block_value += digit * power_of_10;
            power_of_10 *= 10;
        }
        digits.addHead(rem_block_value); // Thêm block đầu tiên
        size++;
    }

    // 5. Thêm các block đầy vào
    for (int i = 0; i < num_full_blocks; i++)
    {
        if (size == 0 && i == 0)
        {
            digits.addHead(full_block_value);
        }
        else
        {
            digits.addTail(full_block_value);
        }
        size++;
    }

    // Nếu không tạo ra gì (ví dụ digit=0), hãy đảm bảo nó là số 0
    if (size == 0)
    {
        digits.addHead(0);
        size = 1;
    }
}
// ------------------- Thêm hàm khởi tạo SAO CHÉP -------------------

SoNguyenLon::SoNguyenLon(const SoNguyenLon &other)
{
    this->size = 0;
    for (int i = 0; i < other.size; i++)
    {
        this->digits.addTail(other.digits[i]);
        this->size++; // Tăng size của 'this'
    }
}
bool SoNguyenLon::operator>=(const SoNguyenLon &other) const
{
    if (size != other.size)
        return size > other.size;
    for (int i = 0; i < size; i++)
        if (digits[i] != other.digits[i])
            return digits[i] > other.digits[i];
    return true;
}

SoNguyenLon SoNguyenLon::operator+(const SoNguyenLon &other) const
{
    SoNguyenLon result;
    result.clear();

    int i = size - 1, j = other.size - 1;
    long long carry = 0;

    while (i >= 0 || j >= 0 || carry)
    {
        long long a = (i >= 0 ? digits[i] : 0);
        long long b = (j >= 0 ? other.digits[j] : 0);
        long long sum = a + b + carry;
        result.digits.addHead(sum % BASE);
        carry = sum / BASE;
        i--;
        j--;
    }

    result.size = result.digits.getSize();
    result.remove_leading_zeros();
    return result;
}

SoNguyenLon SoNguyenLon::operator-(const SoNguyenLon &other) const
{
    if (!(*this >= other))
        return SoNguyenLon(0);
    SoNguyenLon result;
    result.clear();

    int i = size - 1, j = other.size - 1;
    long long borrow = 0;

    while (i >= 0)
    {
        long long a = digits[i];
        long long b = (j >= 0 ? other.digits[j] : 0);
        long long sub = a - b - borrow;

        if (sub < 0)
        {
            sub += BASE;
            borrow = 1;
        }
        else
            borrow = 0;

        result.digits.addHead(sub);
        i--;
        j--;
    }

    result.size = result.digits.getSize();
    result.remove_leading_zeros();
    return result;
}

SoNguyenLon SoNguyenLon::operator*(const SoNguyenLon &other) const
{

    // ---- Sửa code ở đây ----
    SoNguyenLon result; // 1. Khởi tạo result = 0
    result.clear();     // 2. Xóa sạch (size = 0)

    int result_size = size + other.size;

    for (int i = 0; i < result_size; i++)
    {
        result.digits.addTail(0);
    }

    for (int i = size - 1; i >= 0; i--)
    {
        long long carry = 0;
        for (int j = other.size - 1; j >= 0; j--)
        {
            long long mul = 1LL * digits[i] * other.digits[j] + result.digits[i + j + 1] + carry;
            result.digits[i + j + 1] = mul % BASE;
            carry = mul / BASE;
        }
        result.digits[i] += carry;
    }

    result.size = result.digits.getSize();
    result.remove_leading_zeros();
    return result;
}

SoNguyenLon &SoNguyenLon::operator=(const SoNguyenLon &other)
{
    // 1. Tự kiểm tra gán
    if (this == &other)
    {
        return *this;
    }

    this->clear();

    this->size = 0;

    for (int i = 0; i < other.size; i++)
    {
        this->digits.addTail(other.digits[i]);
        this->size++;
    }

    return *this;
}

SoNguyenLon operator+(long long x, const SoNguyenLon &b) { return SoNguyenLon(x) + b; }
SoNguyenLon operator-(long long x, const SoNguyenLon &b) { return SoNguyenLon(x) - b; }
SoNguyenLon operator+(const SoNguyenLon &a, long long x) { return a + SoNguyenLon(x); }
SoNguyenLon operator-(const SoNguyenLon &a, long long x) { return a - SoNguyenLon(x); }

ostream &operator<<(ostream &out, const SoNguyenLon &n)
{
    out << n.digits[0];
    for (int i = 1; i < n.size; i++)
        out << setw(9) << setfill('0') << n.digits[i];
    return out;
}

int main()
{
    SoNguyenLon snl1;
    SoNguyenLon snl2(44667733);
    SoNguyenLon snl3(5, 9);
    SoNguyenLon snl4(7, 30);
    SoNguyenLon snl5 = snl3 - snl2;
    SoNguyenLon snl6 = 1098765432 - snl2;
    SoNguyenLon snl7 = snl4 - snl3 + 123456789;
    SoNguyenLon snl8 = snl2 * snl3;

    cout << snl1 << endl
         << snl2 << endl
         << snl3 << endl;
    cout << snl4 << endl
         << snl5 << endl
         << snl6 << endl;
    cout << snl7 << endl
         << snl8 << endl
         << endl;
    system("pause");
    return 0;
}