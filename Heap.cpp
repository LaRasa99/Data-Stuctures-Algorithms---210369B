#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
   int largest = root;
   int left = 2*root + 1;
   int right = 2*root + 2;

   //if the left child is larger than the root
   if(left < n and arr[left] > arr[largest]){
       largest = left;
   }
   //if the right child is larger than the root
   if(right < n and arr[right] > arr[largest]){
       largest = right;
   }
   //if root is not the largest swap and continue heapifying
   if(largest != root){
       int temp = arr[root];
       arr[root] = arr[largest];
       arr[largest] = temp;

       heapify(arr, n, largest);
   }
  
   
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   for(int i=n/2-1; i>=0; i--){
       heapify(arr, n, i);
   }
   for(int i = n-1; i>=0; i--){
       int temp = arr[0];
       arr[0] = arr[i];
       arr[i] = temp;

       heapify(arr, i, 0);
   }
   
  
   // extracting elements from heap one by one
   
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
/*
int main()
{
   int heap_arr[] = {4,17,3,12,9,6};
   int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);

}
*/

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int heap_arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> heap_arr[i];
    }

    cout<<"Input array"<<endl;
    displayArray(heap_arr,n);

    heapSort(heap_arr, n);

    cout << "Sorted array"<<endl;
    displayArray(heap_arr, n);
    return 0;
}
