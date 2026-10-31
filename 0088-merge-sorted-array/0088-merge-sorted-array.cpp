class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
     vector<int> anscop;
     int i = 0;
     int j = 0;
     while (anscop.size() < nums1.size()){
        if(i < m && j < n && nums1[i] <= nums2[j]){
           anscop.push_back(nums1[i]);
           i++; 
        }
        if(i >= m && j < n){
            anscop.push_back(nums2[j]);
            j++;
        }
        if( i < m && j >= n){
            anscop.push_back(nums1[i]);
            i++;
        }
        if(i < m && j < n && nums1[i] > nums2[j]){
            anscop.push_back(nums2[j]);
            j++;
        }
     }
     for(int i = 0 ; i < nums1.size(); i++){
        nums1[i] = anscop[i];
     }

    }
};