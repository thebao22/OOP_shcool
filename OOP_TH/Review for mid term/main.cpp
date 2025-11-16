#include "Company.h"
#include "Company.cpp"
int main(){
    fstream fs("input.txt");
    Company cp;
    cp.updateList(fs);
    cp.printList("Gaming", "05/04/2025");
}