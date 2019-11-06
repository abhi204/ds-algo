//Insertion Sort
#include <stdio.h>
#include <iostream>


int main(int argc, char const *argv[]) {
  int n;
  std::cin >> n;
  int list[n] = {};
  for (size_t i = 0; i < n; i++) {
    std::cin >> list[i];
  }
//List is read from user
//NOTE: actually, at any time, subarray before "i"th index is always sorted (This is the foundation of Insertion sort algorithm)

  for (int i=1; i<n; i++){
    int store = list[i];                        //store the value of list[i]
    for (int j=i-1; j>=0 ; j--){
      if (list[j]>store) {                      //if any element before list[i] is greater than it(store)
        list[j+1]=list[j];                      //shift the element to the right
      }
      else{
        list[j+1]=store;                        //as soon as an element before list[i] is found to be shorter, the element after it is replaced with store
        continue;
      }
    }
  }


  std::cout << '\n' << '\n';
  for (size_t i = 0; i < n; i++) {
    std::cout << list[i] << " ";
  }
  return 0;
}
