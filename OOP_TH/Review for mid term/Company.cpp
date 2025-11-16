#include "Company.h"

char *removeSpace(char *str)
{
    if (!str)
        return nullptr;
    while (*str && isspace(*str))
        str++;
    return str;
}
//=====IMPLEMENT CLASS LAPTOP=====
Laptop::Laptop()
{
    name = new char[8];
    brand = new char[8];
    PRD = new char[8];
    strcpy(brand, "xxxxxxx");
    strcpy(PRD, "xxxxxxx");
    strcpy(name, "xxxxxxx");
    price = 0;
    weightl = 0;
    battery = 0;
}

Laptop::Laptop(char *name, char *brand, char *PRD, long long price, double weight, double battery)
{
    this->name = new char[strlen(name) + 1];
    this->brand = new char[strlen(brand) + 1];
    this->PRD = new char[strlen(PRD) + 1];
    strcpy(this->name, name);
    strcpy(this->brand, brand);
    strcpy(this->PRD, PRD);
    this->price = price;
    this->weightl = weight;
    this->battery = battery;
}

// Laptop::~Laptop()
// {
//     delete[] name;
//     delete[] brand;
//     delete[] PRD;
// }

bool Laptop::operator<(const char *date)
{
    int dd1, mm1, yy1;
    int dd2, mm2, yy2;

    sscanf(this->PRD, "%d/%d/%d", &dd1, &mm1, &yy1);
    sscanf(date, "%d/%d/%d", &dd2, &mm2, &yy2);

    if (yy1 != yy2)
        return yy1 < yy2;
    if (mm1 != mm2)
        return mm1 < mm2;
    return dd1 < dd2;
}

//=====IMPLEMENT CLASS LAPTOP GAMING=====
GamingType::GamingType() : Laptop()
{
    card = new char[8];
    strcpy(card, "xxxxxxx");
    int hz = 0;
}

GamingType::GamingType(char *name, char *brand, char *PRD, long long price, double weight, double battery, char *card, int hz) : Laptop(name, brand, PRD, price, weight, battery)
{
    this->card = new char[strlen(card) + 1];
    strcpy(this->card, card);
    this->hz = hz;
}

void GamingType::print()
{
    cout << "Name: " << Laptop::name << endl;
    cout << "brand: " << Laptop::brand << endl;
    cout << "Production date: " << Laptop::PRD << endl;
    cout << "price: " << Laptop::price << " VND" << endl;
    cout << "Weight: " << Laptop::weightl << " Kg" << endl;
    cout << "Battery: " << Laptop::battery << endl;
    cout << "Type: " << "*Gaming Laptop*" << endl;
    cout << "Graphics Card: " << card << endl;
    cout << "Refresh rate: " << hz << endl;
}

char *GamingType::getCard()
{
    return card;
}

int GamingType::getHZ()
{
    return hz;
}

GamingType::~GamingType()
{
    delete[] card;
}
//=====IMPLEMENT CLASS LAPTOP OFFICE=====
OfficeType::OfficeType() : Laptop()
{
    port = new char[8];
    monitor = new char[8];
    strcpy(port, "xxxxxxx");
    strcpy(monitor, "xxxxxxx");
}

OfficeType::OfficeType(char *name, char *brand, char *PRD, long long price, double weight, double battery, char *port, char *monitor) : Laptop(name, brand, PRD, price, weight, battery)
{
    this->port = new char[strlen(port) + 1];
    this->monitor = new char[strlen(monitor) + 1];
    strcpy(this->port, port);
    strcpy(this->monitor, monitor);
}

void OfficeType::print()
{
    cout << "Name: " << Laptop::name << endl;
    cout << "brand: " << Laptop::brand << endl;
    cout << "Production date: " << Laptop::PRD << endl;
    cout << "price: " << Laptop::price << " VND" << endl;
    cout << "Weight: " << Laptop::weightl << " Kg" << endl;
    cout << "Battery: " << Laptop::battery << endl;
    cout << "Type: " << "*Officed Laptop*" << endl;
    cout << "Conect Port: " << port << endl;
    cout << "Monitor: " << monitor << endl;
}

char *OfficeType::getPort()
{
    return port;
}

char *OfficeType::getMonitor()
{
    return monitor;
}

OfficeType::~OfficeType()
{
    delete[] port;
    delete[] monitor;
}
//=====IMPLEMENT CLASS LAPTOP BUSINESS=====
BusinessType::BusinessType() : Laptop()
{
    security = new char[8];
    type_netW = new char[8];
    strcpy(security, "xxxxxxx");
    strcpy(type_netW, "xxxxxxx");
}

BusinessType::BusinessType(char *name, char *brand, char *PRD, long long price, double weight, double battery, char *security, char *type_netW) : Laptop(name, brand, PRD, price, weight, battery)
{
    this->security = new char[strlen(security) + 1];
    this->type_netW = new char[strlen(type_netW) + 1];
    strcpy(this->security, security);
    strcpy(this->type_netW, type_netW);
}

void BusinessType::print()
{
    cout << "Name: " << Laptop::name << endl;
    cout << "brand: " << Laptop::brand << endl;
    cout << "Production date: " << Laptop::PRD << endl;
    cout << "price: " << Laptop::price << " VND" << endl;
    cout << "Weight: " << Laptop::weightl << " Kg" << endl;
    cout << "Battery: " << Laptop::battery << endl;
    cout << "Type: " << "*Business Laptop*" << endl;
    cout << "Security: " << security << endl;

    cout << "Type NetWork support: " << type_netW << endl;
}
char *BusinessType::getSecurity()
{
    return security;
}

char *BusinessType::getType_netW()
{
    return type_netW;
}

BusinessType::~BusinessType()
{
    delete[] security;
    delete[] type_netW;
}

//=====IMPLEMENT CLASS COMPANY=====

void Company::updateList(fstream &file)
{
    if (!file.is_open())
    {
        cerr << "Opening file unsuccessfully" << endl;
    }

    int _size = 0;
    char *line = new char[SZ];
    while (file.getline(line, SZ))
    {
        if (line[0] == '\0')
            continue;
        _size++;
    }
    // lấy kích thước cho list
    file.clear();            // xóa cờ eof
    file.seekg(0, ios::beg); // đưa con trỏ file về đầu trang

    this->size = _size;
    list_lap = new Laptop *[this->size];
    type_state = new int[this->size];
    int index = 0;
    while (file.getline(line, SZ))
    {
        if (line[0] == '\0')
            continue;
        char *_name = removeSpace(strtok(line, ","));
        char *_brand = removeSpace(strtok(nullptr, ","));
        char *_PRD = removeSpace(strtok(nullptr, ","));
        long long _price = parsePrice(removeSpace(strtok(nullptr, ","))); // Chuyển về double
        double _weight = atof(removeSpace(strtok(nullptr, ",")));
        double _battery = atof(removeSpace(strtok(nullptr, ",")));
        char *_type = removeSpace(strtok(nullptr, ","));
        char *_info1 = removeSpace(strtok(nullptr, ","));
        char *_info2 = removeSpace(strtok(nullptr, ","));

        if (strcmp(_type, "Gaming") == 0)
        {
            int info2 = atoi(_info2);
            list_lap[index] = new GamingType(_name, _brand, _PRD, _price, _weight, _battery, _info1, info2);
            type_state[index] = -1;
        }
        else if (strcmp(_type, "VanPhong") == 0)
        {
            list_lap[index] = new OfficeType(_name, _brand, _PRD, _price, _weight, _battery, _info1, _info2);
            type_state[index] = 0;
        }
        else
        {
            list_lap[index] = new BusinessType(_name, _brand, _PRD, _price, _weight, _battery, _info1, _info2);
            type_state[index] = 1;
        }
        index++;
    }
    delete[] line;
}

void Company::printList() const
{
    if (size == 0 || list_lap == nullptr)
    {
        cout << "No laptops in the list." << endl;
        return;
    }

    for (int i = 0; i < size; i++)
    {
        cout << "Laptop #" << (i + 1) << ":" << endl;

        // Gọi hàm print() của từng object Laptop
        if (list_lap[i] != nullptr)
            list_lap[i]->print();

        // Hiển thị trạng thái loại máy
        cout << "Type state: ";
        if (type_state[i] == -1)
            cout << "Gaming" << endl;
        else if (type_state[i] == 0)
            cout << "VanPhong" << endl;
        else if (type_state[i] == 1)
            cout << "Business" << endl;
        else
            cout << "Unknown" << endl;

        cout << "---------------------------" << endl;
    }
}

void Company::printList(const char *type, const char *date) const
{
    if (strcmp(type, "Gaming") == 0)
    {
        for (int i = 0; i < size; i++)
        {
            if (type_state[i] == -1 && *list_lap[i] < date)
            {
                list_lap[i]->print();
                cout << "---------------------------" << endl;
            }
        }
    }
    else if (strcmp(type, "VanPhong") == 0)
    {
        for (int i = 0; i < size; i++)
        {
            if (type_state[i] == 0 && *list_lap[i]< date)
            {
                list_lap[i]->print();
                cout << "---------------------------" << endl;
            }
        }
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            if (type_state[i] == 1 && *list_lap[i]< date)
            {
                list_lap[i]->print();
                cout << "---------------------------" << endl;
            }
        }
    }
}
long long parsePrice(char *priceStr)
{
    // 1. Kiểm tra an toàn nếu strtok trả về NULL
    if (priceStr == nullptr)
    {
        return 0.0; // Trả về giá trị mặc định là 0
    }

    // 2. Tạo mảng tạm để lưu chuỗi "sạch"
    char cleanPrice[SZ];
    int j = 0; // Vị trí ghi cho chuỗi "sạch"

    // 3. Lặp qua chuỗi giá tiền (ví dụ: "65.000.000")
    for (int i = 0; priceStr[i] != '\0'; i++)
    {
        // 4. Chỉ copy ký tự nếu nó KHÔNG phải là dấu '.'
        if (priceStr[i] != '.')
        {
            cleanPrice[j] = priceStr[i];
            j++;
        }
    }
    cleanPrice[j] = '\0'; // 5. Kết thúc chuỗi "sạch" (ví dụ: "65000000")

    // 6. Chuyển chuỗi "sạch" sang double và trả về
    return atof(cleanPrice);
}