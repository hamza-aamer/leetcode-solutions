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

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size()+nums2.size()==1){
            if(nums1.size()!=1)
            return nums1[0];
            else return nums2[0];
        }
        int apos = 0;
        int bpos = 0;
        bool flag = 0;
        for (int x = 0; x < nums1.size() + nums2.size(); x++) {
            if (apos <= nums1.size()-1 && nums1[apos] < nums2[bpos]) {
                //apos++;
                if (x+1 >=( nums1.size() + nums2.size()) / 2) {
                     //cout<<nums1.size()+nums2.size();
                     if((nums1.size()+nums2.size())%2==0){
                         //apos++;
                         if (apos + 1 == nums1.size()) {
                             bpos++;
                             return ((double)nums1[apos-1] + nums2[bpos]) / 2;
                         }
                         if (nums1[apos + 1] > nums2[bpos]) {
                             bpos++;
                             return ((double)nums1[apos-1] + nums2[bpos]) / 2;
                         }
                         return ((double)nums1[apos]+nums1[apos+1])/2;
                     }
                     if (flag == 1) return nums1[apos];
                    apos++;
                     if (nums1[apos] > nums2[bpos]) {
                         flag = 1;
                         continue;
                     }
                    return nums1[apos];
                }
                //cout << nums1[apos-1];
                apos++;
                continue;
            }
            if (bpos <= nums2.size()-1 && nums2[bpos] < nums1[apos]) {
                if (x+1 >= (nums1.size() + nums2.size()) / 2) {
                    
                    if ((nums1.size() + nums2.size()) % 2 == 0) {
                        
                        if (bpos + 1 == nums2.size()) {
                            bpos++;
                            return ((double)nums1[apos] + nums2[bpos-1]) / 2;
                        }
                        if (nums2[bpos + 1] > nums1[apos]) {
                            bpos++;
                            return ((double)nums1[apos] + nums2[bpos-1]) / 2;
                        }
                        return ((double)nums1[apos] + nums1[apos + 1]) / 2;
                    }
                    if (flag == 1) return nums2[bpos];
                    bpos++;
                    if (nums1[apos] < nums2[bpos]) {
                        flag = 1;
                        continue;
                    }
                    return nums2[bpos];
                }
                //cout << nums2[bpos-1];
                bpos++;
                continue;
            }
        }
        return 0;
    }
};
