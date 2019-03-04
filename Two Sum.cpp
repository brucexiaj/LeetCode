/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    
    int *result = (int *)malloc(sizeof(int)*2);
    int rest, i, j;
    for (;i < numsSize;i++) {
        rest = target - nums[i];
        for (j = i + 1;j < numsSize;j++) {
            if (rest == nums[j]) {              
              result[0] = i;
                result[1] = j;
                 return result;
            }
        }
    }     
    return result;                  
}