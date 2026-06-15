/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int *ret = calloc(2, sizeof(int));
    
    for( int i = 0 ; i < numsSize; i ++ ) {
        ret[0] = i;
        int searchfor = target - nums[i];
        for( int j = i+1 ; j < numsSize;  j++) {
            if( nums[j] == searchfor ){
                ret[1] = j;
                return ret;
            }
        }
    }
    
    return NULL;
    
}