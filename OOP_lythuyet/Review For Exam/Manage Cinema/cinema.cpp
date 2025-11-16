#include <iostream>
#include <vector>
using namespace std;
class Cinema{
    private:
        vector<Room*> list_room;
        int quantity;
        static int total_booked;
        static int total_canceled;
    public:
        void addRoom(Room *room);
        static void update_total_booked(); 
        static void update_total_canceled(); 
};
class Film{
    private:
     string name;
     int duration;
     string type;
    public:
    Film() = default;
    Film(string name, int duration, string type); 
};
class Room{
    private:
    string name_room;
    int size;
    vector<bool> chair;
    vector <SuatChieu*> sclist;
    public:
    void add_suatchieu(SuatChieu &sc);
    
};
class SuatChieu{
    private:
    Film a;
    string date;
    double price;
    Room *rm;
    public:
    SuatChieu() = default;
    SuatChieu(Film a, string date, double price, Room *rm);
};
class Client{
    private:
        string type;
    public:
    bool book(SuatChieu &sc);
};