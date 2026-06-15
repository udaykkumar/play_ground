/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

int compare( const void *x, const void *y ) {
    return *( int *) x - *( int *) y;
}

int** threeSum(int* nums, int numsSize, int* returnSize) {
    
    int **ret = NULL;
    
    qsort(nums, numsSize, sizeof(int), compare);
    
    for( int  i = 0; i < numsSize-2 ; i ++  ) {
        int lo = i + 1;
        int hi = numsSize-1;
        int sum = 0 - nums[i];
        
        if( i == 0 || ( i > 0 && nums[i] != nums[i-1])) {
            while( lo < hi ){
                if( nums[lo] + nums[hi] == sum ){
                    ret = ( int **) realloc( ret, ( *returnSize +1 ) * sizeof(*ret));
                    ret[*returnSize] = (int *) malloc( 3* sizeof(int));
                    ret[*returnSize][0] = nums[i]; 
                    ret[*returnSize][1] = nums[lo];
                    ret[*returnSize][2] = nums[hi];
                
                    *returnSize += 1;
                
                    while( lo < hi && nums[lo] == nums[lo+1]) lo ++;
                    while( lo < hi && nums[hi] == nums[hi-1]) hi --;
                
                    lo ++;
                    hi --;
                    
                } else if( nums[lo] + nums[hi] < sum ) {
                    lo ++;
                } else {
                    hi --;
                }
            }    
        }
        
    }
    
    return ret;
    
}