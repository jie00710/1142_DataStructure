#include <iostream>
#include<vector>
using namespace std;

int stepCount = 0;

int countElement(const vector<int>& arr, int target) {
  int count = 0;
  stepCount++;//assignments:1

  stepCount++;//loop initialization:1
  for (int i = 0; i < arr.size(); i++) {
    stepCount++// Comparison : i < arr:n+1
  
    stepCount++// Comparison with target: arr[i] == target:n
    if (arr[i] == target) {
      count++;
      stepCount++//assignments:n
  }
    stepCount++// Increment-i++:n
  }
  stepCount++//return count
  return count;

}

//time complexity
// Total operations:
//  4 + 4n operations
// Therefore, O(n) complexity
