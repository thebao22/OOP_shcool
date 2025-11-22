#include "employLib.h"
#include "employ.cpp"
int main()
{
    // Tạo công ty
    Company c;

    // Tạo danh sách nhân viên

    c.addEmploy(new Engineer(1000, 10, 5));
    c.addEmploy(new Manager(2000, 3, 100));

    // In thông tin từng nhân viên
    for (auto emp : c.getList())
    {
        emp->print();
        cout << "\n--------------------------------\n";
    }
    
    for (auto emp : c.getList())
    {
        cout << emp->getRole();
        cout << "\n--------------------------------\n";
    }

    // Tính tổng lương
    double total = 0;
    for (auto emp : c.getList())
        total += emp->getSalary();

    cout << "Total Salary: " << total << endl;

    // Giải phóng bộ nhớ
    return 0;
}