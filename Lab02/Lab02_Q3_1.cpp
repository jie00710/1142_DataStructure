#include <iostream>
using namespace std;
int count = 0 ;
void copyArray(const vector<int>& source, vector<int>& dest) {
    count++// loop initialization:1
  for (int i = 0; i < source.size(); i++) {
    count++//Loop comparison:n+1
    dest[i] = source[i];
    count++//assignment:n
    
    count ++; // Increment-i++:n
}
}

//time complexity is 3n+2
// Total operations:
//  2 + 3n operations
// Therefore, O(n) complexity
