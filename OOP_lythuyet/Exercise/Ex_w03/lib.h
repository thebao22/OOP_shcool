#include <iostream>
using namespace std;

class Account {
private:
    static int id;
    char* username;
    char* password;

public:
    Account();
    Account(char* username, char* password);

    void login();
    void signup();
};