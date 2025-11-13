#include "lib.h"
#include "Day6.cpp"

int main() {
int arr[6] = {0, 1, 0, 2, 3, 4};
Array a1(arr, 6);
a1[3] = 4;
//...

HistogramArray a2(6, arr, 5); // histSize = 5 -> [0, 4]
a2.computeHist();
a2.displayHist(); // 0->2, 1->1, 2->1, 3->1, 4->1
cout << endl;
a2[3] = 4; // [0, 1, 0, 4, 3, 4]
a2.computeHist();
a2.displayHist(); // 0->2, 1->1, 2->0, 3->1, 4->2
//...
}