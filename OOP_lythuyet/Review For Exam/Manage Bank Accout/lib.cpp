MainAccount::MainAccount(string AccountID, double balance)
    : AccountID(AccountID), balance(balance)
{
    cout << "Mo tai khoan CHINH " << AccountID << ". So du: " << balance << endl;
}

void MainAccount::deposit(double amount)
{
    if (amount > 0)
    {
        balance += amount;
        cout << "[TK Chinh " << AccountID << "] Nap " << amount << " thanh cong. So du moi: " << balance << endl;
    }
}

bool MainAccount::with_draw(double amount)
{
    if (amount <= 0)
    {
        cout << "[TK Chinh " << AccountID << "] So tien rut khong hop le." << endl;
        return false;
    }
    if ((balance - amount) >= minBalance)
    {
        balance -= amount;
        cout << "[TK Chinh " << AccountID << "] Rut " << amount << " thanh cong. So du con lai: " << balance << endl;
        return true;
    }
    cout << "[TK Chinh " << AccountID << "] Rut " << amount << " THAT BAI. Khong du so du." << endl;
    return false;
}

double MainAccount::getBalance() const
{
    return balance;
}

string MainAccount::getAccountID() const
{
    return AccountID;
}

// --- Dinh Nghia Lop SubAccount ---

SubAccount::SubAccount(string AccountID, MainAccount *main)
    : AccountID(AccountID), tklk(main), Count_Balance(0)
{
    cout << "Mo tai khoan PHU THUOC " << AccountID << " lien ket voi " << main->getAccountID() << endl;
}

void SubAccount::deposit(double amount)
{
    cout << "[TK Phu " << AccountID << "] Dang nap vao TK Chinh..." << endl;
    tklk->deposit(amount);
}

bool SubAccount::with_draw(double amount)
{
    if (amount <= 0)
    {
        cout << "[TK Phu " << AccountID << "] So tien rut khong hop le!" << endl;
        return false;
    }

    if (Count_Balance + amount > max_draw)
    {
        cout << "[TK Phu " << AccountID << "] Rut THAT BAI. Vuot han muc thang." << endl;
        cout << "   Da rut: " << fixed << setprecision(0) << Count_Balance << "/" << max_draw << endl;
        return false;
    }

    bool rutThanhCong = tklk->with_draw(amount);

    if (rutThanhCong)
    {
        Count_Balance += amount;
        cout << "[TK Phu " << AccountID << "] Da cap nhat han muc. Da rut: "
             << fixed << setprecision(0) << Count_Balance << "/" << max_draw << endl;
        return true;
    }

    return false;
}

double SubAccount::getBalance() const
{
    return tklk->getBalance();
}

string SubAccount::getAccountID() const
{
    return AccountID;
}

void SubAccount::resetCountBalance()
{
    Count_Balance = 0;
}

// --- Dinh Nghia Lop Client ---

Client::Client(string name) : name_Cli(name) {}

Client::~Client()
{
    cout << "Don dep Client: " << name_Cli << endl;
    for (MainAccount *acc : list_main_account)
    {
        delete acc;
    }
    for (SubAccount *acc : list_sub_account)
    {
        delete acc;
    }
}

bool Client::InsertMainAcc(MainAccount *Acc)
{
    if (list_main_account.size() < Quantity_max_per_type)
    {
        list_main_account.push_back(Acc);
        cout << "Them tai khoan chinh " << Acc->getAccountID() << " cho client " << name_Cli << " thanh cong." << endl;
        return true;
    }
    delete Acc;
    return false;
}

bool Client::InsertSubAcc(SubAccount *Acc)
{
    if (list_sub_account.size() < Quantity_max_per_type)
    {
        list_sub_account.push_back(Acc);
        cout << "Them tai khoan phu " << Acc->getAccountID() << " cho client " << name_Cli << " thanh cong." << endl;
        return true;
    }
    delete Acc;
    return false;
}

MainAccount *Client::getMainAccount(string AccountID)
{
    for (MainAccount *tk : list_main_account)
    {
        if (tk->getAccountID() == AccountID)
        {
            return tk;
        }
    }
    return nullptr;
}

SubAccount *Client::getSubAccount(string AccountID)
{
    for (SubAccount *tk : list_sub_account)
    {
        if (tk->getAccountID() == AccountID)
        {
            return tk;
        }
    }
    return nullptr;
}

string Client::getName() const
{
    return name_Cli;
}

// --- Dinh Nghia Lop Bank ---

Bank::Bank(string name) : name_Bank(name)
{
    cout << "Khoi tao Ngan Hang " << name << endl;
}

Bank::~Bank()
{
    cout << "Don dep Ngan Hang " << name_Bank << endl;
    for (Client *cli : list_Client)
    {
        delete cli;
    }
}

void Bank::InsertClient(Client *cli)
{
    list_Client.push_back(cli);
    cout << "Them client " << cli->getName() << " vao ngan hang." << endl;
}

Client *Bank::getClient(string name)
{
    for (Client *temp : list_Client)
    {
        if (temp->getName() == name)
        {
            return temp;
        }
    }
    return nullptr;
}