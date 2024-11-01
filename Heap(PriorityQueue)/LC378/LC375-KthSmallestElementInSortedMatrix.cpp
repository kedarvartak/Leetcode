// Leetcode Link: https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
// Leetcode Solution


#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // Max heap to store k smallest elements
        priority_queue<int> pq;
        
        // Counter to keep track of how many elements we've processed
        int m = 0;
        int size = matrix.size();
        
        // Iterate through each element in the matrix
        for(int i = 0; i < size; i++){
            for(int j = 0; j < matrix[0].size(); j++){
                // For first k elements, directly push to heap
                if (m < k) {
                    pq.push(matrix[i][j]);
                }
                m++;

                // For elements after kth position
                if(m > k){
                    // If current element is smaller than largest element in heap
                    // Replace it to maintain k smallest elements
                    if(matrix[i][j] < pq.top()){
                        pq.pop();  // Remove largest element
                        pq.push(matrix[i][j]);  // Add current smaller element
                    }
                }
            }
        } 
        // At this point, heap contains k smallest elements
        // Top element is the kth smallest
        return pq.top();   
    }
};

/*
Example Walkthrough:
Given matrix = [
    [1,  5,  9],
    [10, 11, 13],
    [12, 13, 15]
]
k = 4

Step by step process:
1. First k elements (m < k):
   m=1: Push 1    → pq = [1]
   m=2: Push 5    → pq = [5, 1]
   m=3: Push 9    → pq = [9, 5, 1]
   m=4: Push 10   → pq = [10, 9, 5, 1]

2. Remaining elements (m > k):
   m=5: Check 11  → 11 > 10 (skip)
   m=6: Check 13  → 13 > 10 (skip)
   m=7: Check 12  → 12 > 10 (skip)
   m=8: Check 13  → 13 > 10 (skip)
   m=9: Check 15  → 15 > 10 (skip)

3. Final heap: [10, 9, 5, 1]
   Return pq.top() = 10

Therefore, 10 is the 4th smallest element in the matrix.

Time Complexity: O(n²logk) where n is the size of matrix
Space Complexity: O(k) for the heap
*/