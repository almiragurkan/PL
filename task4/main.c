#include <stdio.h>
#include <math.h>
#include <stdbool.h>

void printArray (const int arr[], const int size) {
  for (int i = 0; i < size; i++)
    printf ("%d ", arr[i]);
  printf ("\n");
}

void swap (int *p, int *k) {
  int temp = *p;
    *p = *k;
    *k = temp;
}

bool stoogeSort (int arr[], const int low, const int high){
  if (low >= high)
    return true;
  if (arr[low] > arr[high])
    swap (arr+low, arr+high);

  int length = high - low + 1;
  if (length >= 3) {
      int lastTwoThirds = low + floor (length * 2.0 / 3.0) - 1;
      int firstTwoThirds = low + ceil (length / 3.0);

      stoogeSort (arr, low, lastTwoThirds);
      stoogeSort (arr, firstTwoThirds, high);
      stoogeSort (arr, low, lastTwoThirds);

}
  return 1;
}

int main () {
  int size;
  printf("Enter array size: ");
  scanf("%d", &size);
  int arr[size];
  printf("Enter %d elements: ", size);

  for(int i=0; i<size; i++)
    scanf("%d", arr+i);
  stoogeSort (arr, 0, size-1);
  printf("Sorted array:\n");
  printArray (arr, size);
  return 0;
}
