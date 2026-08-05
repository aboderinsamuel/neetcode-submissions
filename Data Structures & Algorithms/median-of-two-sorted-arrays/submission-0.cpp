class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()){
            return findMedianSortedArrays(nums2, nums1);
        }
        int m = nums1.size();
        int n = nums2.size();
        int total = m + n;
        int half = (total+1)/2;
        int left = 0;
        int right = m;
        while(left <= right){
            int i = left + (right-left)/2;
            int j = half-i;

            int nums1Left = (i == 0) ? INT_MIN : nums1[i-1];
            int nums1Right = (i == m) ? INT_MAX : nums1[i];
            int nums2Left = (j == 0) ? INT_MIN : nums2[j-1];
            int nums2Right = (j == n) ? INT_MAX : nums2[j];

            if(nums1Left <= nums2Right && nums2Left <= nums1Right){
                if(total % 2 == 0){
                    return (max(nums1Left, nums2Left) + min(nums1Right, nums2Right)) / 2.0;
                }else{
                    return max(nums1Left, nums2Left);
                }
            }
            else if(nums1Left > nums2Right){
                right = i-1;
            }else{
                left = i + 1;
            }
        }
        return -1;
    }
};
