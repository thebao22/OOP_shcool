#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Object
{
protected:
    string name;
    Object *parent;

public:
    Object();
    Object(string name);
    virtual int getObjectType() = 0;
    virtual void printInfo(int level) = 0;
    string getName() const;
    void setParent(Object *parent);
    Object* getParent() const;
    virtual long getSize() = 0;
    virtual ~Object() {}
};

class File : public Object
{
private:
    long size;
    string type;

public:
    File();
    File(string name, long size, string type);
    int getObjectType() override;
    void printInfo(int level) override;
    long getSize() override;
};

// abstract class
class Shortcut : public Object
{
private:
    Object *obj;

public:
    Shortcut();
    Shortcut(string name, Object *obj);
    int getObjectType() override;
    void printInfo(int level) override;
    long getSize() override;
    ~Shortcut(){}
};

class Folder : public Object
{
private:
    vector<Object *> objs;

public:
    Folder();
    Folder(string name);
    bool newObject(Object *obj);
    int getObjectType() override;
    void printInfo(int level) override;
    long getSize() override;
    ~Folder();
};

class Disk
{
private:
    string name;
    long long memory;
    vector<Object *> objs;

public:
    Disk();
    Disk(string name, long long memory);
    string getDiskName();
    bool newObject(Object *obj);
    long long getFreeSpace();
    ~Disk();

    
};

class FS
{
private:
    vector<Disk *> disk;

public:
    bool addDisk(Disk *disks);
};