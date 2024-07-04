// Bubble sort in C++

#include <iostream>
using namespace std;

void printArray(int array[], int size);

// perform bubble sort
void bubbleSort(int array[], int size) {

    bool flag = true;

  // loop to access each array element
  for (int step = 0; step < size; ++step) {
      
    // loop to compare array elements
    for (int i = 0; (i < size - step); ++i) {

      // compare two adjacent elementse
      // change > to < to sort in descending order
      if (array[i] > array[i + 1]) {

        // swapping elements if elements
        // are not in the intended order
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
        // flag = true;
      }
    }
  }


void bubbleSortVect()

// int size = (sizeof(array)/sizeof(array[0]));

  cout << "Sorted Array in Ascending Order:\n";  

  printArray(array, size);
}

// print array
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    cout << "  " << array[i];
  }
  cout << "\n";
}

int main() {
  int data[] = {-2, 45, 0, 11, -9};
  
  // find array's length
  int size = sizeof(data) / sizeof(data[0]);
  
  bubbleSort(data, size);
  
//   printArray(data, size);
}