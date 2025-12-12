#include "lib.h"
#include "lib.cpp"
int main()
{
    Disk *diskC = new Disk("C", 1000);
    
    Folder *folder1 = new Folder("Documents");
    Folder *folder2 = new Folder("Images");

    File *file1 = new File("Resume", 50, "docx");
    File *file2 = new File("Photo", 200, "jpg");

    folder1->newObject(file1);
    folder2->newObject(file2);

    diskC->newObject(folder1);
    diskC->newObject(folder2);

    Folder *sub1 = new Folder("Projects");
    Folder *sub2 = new Folder("Wallpapers");
    folder1->newObject(sub1);
    folder2->newObject(sub2);

    sub1->newObject(new File("ProjectA", 120, "txt"));
    sub1->newObject(new File("ProjectB", 180, "txt"));

    Folder *animals = new Folder("Animals");
    sub2->newObject(animals);

    animals->newObject(new File("cat", 40, "jpg"));
    animals->newObject(new File("dog", 35, "jpg"));

    Shortcut *sc = new Shortcut("Resume Shortcut", file1);
    diskC->newObject(sc);

    cout << "Disk: " << diskC->getDiskName() 
         << ", Free space: " << diskC->getFreeSpace() << endl;

    folder1->printInfo(0);
    folder2->printInfo(0);
    sc->printInfo(0);

    delete diskC;
    return 0;
}
