#include <bits/stdc++.h>

void merge(int arr[], int left[], int right[],int l_size,int r_size) {

  int i=0,j=0,k=0;

  while(i<l_size && j<r_size){   //while i , j can be indices of left,right arrays
    if (left[i]<=right[j]) {
      arr[k]=left[i];
      i++;
    }
    else{
      arr[k]=right[j];
      j++;
    }
    k++;
  }

  while(i<l_size){
    arr[k]=left[i];
    i++;
    k++;
  }
  while(j<r_size){
    arr[k]=right[j];
    j++;
    k++;
  }

}

void merge_sort(int A[],int Asize){
  // if list size is 1, no more recursion
  if (Asize < 2) {
    return;
  }

  int mid = Asize/2;

  int seek = 0; // for creating right,left array

  int left[mid];
  for (;seek < mid; seek++) {
    left[seek] = A[seek];
  }

  int right[(Asize-mid)];
  for (int j=0; seek < Asize; seek++,j++) {
    right[j]=A[seek];
  }
  //left,right array length
  int l_size = sizeof(left)/sizeof(int);
  int r_size = sizeof(right)/sizeof(int);


  merge_sort(left,l_size);
  merge_sort(right,r_size);
  merge(A,left,right,l_size,r_size);

}


int main(int argc, char const *argv[]) {
  int n;
  std::cin >> n;
  int arr_in[n];
  for (size_t i = 0; i <= n-1; i++) {
    std::cin >> arr_in[i];
  }

  merge_sort(arr_in,n);
  for (size_t i = 0; i < n; i++) {
    std::cout << arr_in[i] << " ";
  }
  return 0;
}
