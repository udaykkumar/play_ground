// 1, 3, 5, 6
//          i
//
// 5 target
// 2 
// 7
// 0
int searchInsert(int* nums, int numsSize, int target) {
    
    for( int i = 0; i < numsSize ; i ++ ){
        
        // If found or Lesser than least occupied the least index
        if( target == nums[i] ||  target < nums[i] )                return i;
        
        // Beyond everything
        if( target > nums[i] && ( i == numsSize-1 || target < nums[i+1]))  return i+1;
        
    }
    
    return 0;
}