#include <iostream>
#include<iostream>
using namespace std;
 
int count = 0;

void printPairs(const vector<int>& arr) {
  count++//loop initialization-i=0:1
  for (int i = 0; i < arr.size(); i++) {
    count++//access array:n
    count++//Comparisons i < arr.size():n
    acount++ // inner loop initializationi=1:n
    for (int j = i + 1; j < arr.size(); j++) {
      count++//Comparisons j < arr.size():n(n+1)/2
      cout << arr[i] << "," << arr[j] << endl;
       count++//Increment-j++:n(n+1)/2
    }
  count++//Increment-i++:n
  }
}

//time complexity is n^2+4n+2
// Total operations:
//  n^2+4n+2 operations
// Therefore, O(n^2) complexity
