#include "lib.h"
//============== Object class ===========
Object::Object() : name(""), parent(nullptr) {}
Object::Object(string name) : name(name), parent(nullptr) {}
string Object::getName() const { return name; }
Object *Object::getParent() const { return parent; }
void Object::setParent(Object *parent)
{
    this->parent = parent;
}

//============== Folder class ===========
Folder::Folder() : Object() {}
Folder::Folder(string name) : Object(name) {}
int Folder::getObjectType() { return 0; }
bool Folder::newObject(Object *data)
{
    if (data == this)
        return false;
    int _type = data->getObjectType();
    for (Object *temp : objs)
    {
        if (temp->getName() == data->getName() && _type == temp->getObjectType())
        {
            cerr << "Object has been existed!!" << endl;
            return false;
        }
    }
    data->setParent(this);
    objs.push_back(data);
    return true;
}
void Folder::printInfo(int level)
{
    for (int i = 0; i < level; i++)
        cout << "   ";
    cout << "Folder: " << this->getName() << endl;

    for (Object *temp : objs)
        temp->printInfo(level + 1);
}
long Folder::getSize()
{
    long totalFoldersize = 0;
    for (Object *temp : objs)
    {
        totalFoldersize += temp->getSize();
    }
    return totalFoldersize;
}
Folder::~Folder()
{
    for (Object *obj : objs)
    {
        delete obj;
    }
    objs.clear();
}
//=============== File class ============
File::File() : Object(), size(0), type("") {}
File::File(string name, long _size, string _type) : Object(name), size(_size), type(_type) {}
int File::getObjectType()
{
    return 1;
}
void File::printInfo(int level)
{
    for (int i = 0; i < level; i++)
        cout << "   ";
    cout << "file name: " << this->getName() << "." << type << " (size:" << size << ")" << endl;
}
long File::getSize()
{
    return size;
}

//=============== Shortcut class ==========
Shortcut::Shortcut() : Object(), obj(nullptr) {}
Shortcut::Shortcut(string name, Object *_obj) : Object(name)
{

    if (_obj == nullptr)
    {
        throw std::runtime_error("Not Found");
    }
    int t = _obj->getObjectType();
    if (t != 0 && t != 1)
        throw std::runtime_error("Shortcut target not allowed");

    obj = _obj;
}
int Shortcut::getObjectType() { return 2; }
void Shortcut::printInfo(int level)
{
    for (int i = 0; i < level; i++)
        cout << "   ";
    cout << "Shortcut name: " << this->getName() << "     link: " << obj->getName() << endl;
    obj->printInfo(level+1);
}

long Shortcut::getSize()
{
    return obj->getSize();
}

//=============== Disk class =============
Disk::Disk() : name(""), memory(0) {}
Disk::Disk(string name, long long memory) : name(name), memory(memory) {}
bool Disk::newObject(Object *data)
{
    if (data->getObjectType() != 0 && data->getObjectType() != 1 && data->getObjectType() != 2)
    {
        cout << "Error";
        return false;
    }
    int _type = data->getObjectType();
    for (Object *temp : objs)
    {
        if (temp->getName() == data->getName() && _type == temp->getObjectType())
        {
            cerr << "Object has been existed!!" << endl;
            return false;
        }
    }
    if (data->getSize() > this->getFreeSpace())
        return false;
    objs.push_back(data);
    return true;
}
string Disk::getDiskName()
{
    return name;
}
long long Disk::getFreeSpace()
{
    long long used_size = 0;
    for (Object *temp : objs)
    {
        used_size += temp->getSize();
    }
    return memory - used_size;
}
Disk::~Disk()
{
    for (Object *obj : objs)
    {
        delete obj;
    }
    objs.clear();
}

//==================== FS class =====================
bool FS::addDisk(Disk *dsk)
{
    for (Disk *temp : disk)
    {
        if (dsk->getDiskName() == temp->getDiskName())
            return false;
    }
    disk.push_back(dsk);
    return true;
}
