class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       int ptr1 = m - 1, ptr2 = n - 1, ptr = n + m - 1;
        while(ptr1 >= 0 && ptr2 >= 0)
        {
            if(nums1[ptr1] < nums2[ptr2])
                nums1[ptr--] = nums2[ptr2--];
            else 
                nums1[ptr--] = nums1[ptr1--];
        }
        while(ptr2 >= 0)
        {
            nums1[ptr--] = nums2[ptr2--];   
        }
    }
};
//second solution (gfg problem)
class Solution{
    public:
        
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            int j = 0;
            for(int i = 0; i < n; i++)
            {
                if(arr1[i] > arr2[j])
                {
                    swap(arr1[i], arr2[j]);
                    sort(arr2, arr2 + m);
                }
            }
        } 
};