
int max( int x, int y ) {
    return (x > y) ? x : y ;
}


int maxSubArray(int* nums, int numsSize) {
    int maxSoFar = nums[0], maxEndingHere = nums[0];
    for( int i = 1 ; i < numsSize; i ++ ){
        maxEndingHere = max( maxEndingHere + nums[i],  nums[i]);
        maxSoFar = max( maxEndingHere, maxSoFar );
    }
    
    return maxSoFar;
}