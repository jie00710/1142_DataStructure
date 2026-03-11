#include <iostream>
#include<vector>
using namespace std;

int stepCount = 0;

int findMax(const vector<int>& arr) {
 
  int max = arr[0];
  stepCount++//Assignments:1
  
  
  stepCount++;//loop initialization-i=1:1
  for (int i = 1; i < arr.size(); i++) {
    stepCount ++; // Loop comparison: i < arr.size():n
    stepCount ++; // Array access: arr[i]:n-1
    
    
    stepCount ++; // Comparison with target: arr[i] == target:n-1
   if (arr[i] > max) {
      max = arr[i];
      stepCount ++; //Assignments:n-1
    }
    stepCount ++; // Increment-i++:n-1
  }
  
  stepCount++;//return:1
  return max;
}

//time complexity is 5n-1
// Total operations:
//  5n-1 operations
// Therefore, O(n) complexity

