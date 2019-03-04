double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    //先合并两个数组，然后取中间的值
    int num = nums1Size + nums2Size;
    int size = num/2 + 1;
    int nums[size];
    int step = 0, m = 0, n = 0;
    double result = 0.0;
    while (m <= nums1Size - 1 && n <= nums2Size - 1 && step <= size - 1) {
        if (nums1[m] <= nums2[n]) {
            nums[step++] = nums1[m];
            m++;
        } else {
            nums[step++] = nums2[n];
            n++;
        }
    }
    while (m <= nums1Size - 1 && step <= size - 1) {
        nums[step++] = nums1[m];
        m++;
    }
    while (n <= nums2Size - 1 && step <= size - 1) {
        nums[step++] = nums2[n];
        n++;
    }
    if ((num % 2) == 0) {
        result = ((double)nums[num/2 - 1] + (double)nums[num/2])/2;
    } else {
        result = nums[(num - 1)/2];
    }
    return result;
}