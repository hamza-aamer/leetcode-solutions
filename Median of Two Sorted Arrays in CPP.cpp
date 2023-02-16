/*Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106*/

   double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

   vector<int> merged;
   int apos = 0, bpos = 0;
   int postofind = ceil((nums1.size() + nums2.size() + 1) / 2);
   bool even = ((nums1.size() + nums2.size()) % 2 == 0);
   bool odd = !even;
   int lasta = INT_MIN;
   int lastb = INT_MIN;
   if (nums1.size() > 0)  lasta = nums1[0];
   if (nums2.size() > 0)  lastb = nums2[0];
   int x;
   for (x = 0; x < nums1.size() + nums2.size() || postofind+2!=x; x++) {
       if (postofind+1 == x) {
           if (odd) {
               return merged[x-2];
           }
           if (even) {
               return ((double)merged[x-1] + (double)merged[x-2]) / 2;
           }
       }
       if (nums1.size() > apos) {
           if (nums1[apos] <= lastb || nums2.size() <= bpos) {
               merged.push_back(nums1[apos]);
               lasta = nums1[apos];
               apos++;
               if (nums1.size() > apos) {
                   lasta = nums1[apos];
               }
               continue;
           }
       }
       if (nums2.size() > bpos) {
           if (nums2[bpos] <= lasta || nums1.size()<=apos) {
               merged.push_back(nums2[bpos]);
               lastb = nums2[bpos];
               bpos++;
               if (nums2.size() > bpos) {
                   lastb = nums2[bpos];
               }
               continue;
           }
       }
   }

   return 0;
 }
