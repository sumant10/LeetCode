Given an array with N integers. Perform a special operation K times. After K operations what is the value at index M of the latest array.

Special Operation: Given an array A with X elements, create a new array with X-1 elements where A[i] = A[i]^A[i+1]

Constraints:
1 <= N<= 10^5
1 < K <N
1 <= A[i] <= 10^9

Eg- arr=[1,2,3,4] K=2, M=2
output array after two operations - [1^3, 2^4]
2nd index in the resultant array is 2^4
