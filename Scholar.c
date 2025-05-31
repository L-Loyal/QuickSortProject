// Loy Pereyra :)
// 10/17/2021
// Determines the maximum amount of books person can read based on conditions.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Function Prototypes.
int* ReadPages (int numBooks);
void QuickSort (int* books, int low, int high);
int Partition (int* books, int low, int high);
int IsSorted (int* books, int low, int high);
void Swap (int* a, int* b);
int FindMax (int* books, int numBooks, long long int maxPages);
int main (void) {
int numCases;
scanf("%d", &numCases);
srand(time(NULL));
// Case loop.
for (int loop = 0; loop < numCases; loop++) {
int* books;
int numBooks;
long long int maxPages;
scanf("%d%lld", &numBooks, &maxPages);
books = ReadPages(numBooks);
QuickSort(books, 0, numBooks - 1);
printf("%d\n", FindMax(books, numBooks, maxPages)); // Output.
free(books); // Frees allocated memory.
}
return 0;
}
// Dynamically allocates array of intergers and reads in input for book pages.
int* ReadPages (int numBooks) {
int* temp;
temp = (int*) calloc(numBooks, sizeof(int));
for (int i = 0; i < numBooks; i++)
scanf("%d", &temp[i]);
return temp;
}
// Quick sort algorithm sorts array from smallest to biggest.
void QuickSort (int* books, int low, int high) {
// Checks if array (or subarray) is sorted and then returns if true.
if (IsSorted(books, low, high)) return;
// Splits array into two parts.
int split = Partition(books, low, high);
// Sorts left side of split.
QuickSort(books, low, split - 1);
// Sorts right side of split.
QuickSort(books, split + 1, high);
}
// Returns partition index such that numbers less than or equal to it are to the left
// and numbers to the right are higher than the partition element.
int Partition (int* books, int low, int high) {
// Pick random element and swap it.
int randIndex = low + rand() % (high - low + 1);
Swap(&books[low], &books[randIndex]);
int lowPos = low; // Stores index of partition element.
low++; // Move low to next element.
// Partitioning until low and high counters cross.
while (low <= high) {
// Low pointer is moved until a value is found that is too large for one side.
while (low <= high && books[low] <= books[lowPos]) low++;
// High pointer is moved until a value is found that is too small for one side.
while (high >= low && books[high] > books[lowPos]) high--;
// If two values are on the wrong side of the partition they swap.
if (low < high) Swap(&books[low], &books[high]);
}
// Swaps partition element into the correct location.
Swap(&books[lowPos], &books[high]);
return high; // Returns the index of partition element.
}
// Checks if array is sorted in case partition algorithm is not needed and avoid worst case.
int IsSorted (int* books, int low, int high) {
for (int i = low; i <= high; i++)
if (books[i] > books[i + 1]) return 0;
return 1;
}
// Swaps elements.
void Swap (int* a, int* b) {
int temp = *a;
*a = *b;
*b = temp;
}
// Finds maximum number of books they can read without going over the limit.
int FindMax (int* books, int numBooks, long long int maxPages) {
long long int currPages = 0; // Keeps track of the amount of pages that the person has to read until it reaches the maximum.
for (int i = 0; i < numBooks; i++) {
currPages += books[i];
// Returns number of current iterations if current pages exceeds the limit.
if (currPages > maxPages)
return i;
}
return numBooks; // If program reaches here this means that the number of books is equal to the amount of books they need to read.
}