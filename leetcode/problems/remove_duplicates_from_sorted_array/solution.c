void swap( int *a, int i, int j )
{
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}

//     s
// 1 2 3 4
// 1 1 2 2 3 3 4 4 5 5 6 7 8 9 10
//
//               i

int removeDuplicates(int* nums, int numsSize) {
    int start = 0;
    for( int i = 0 ; i < numsSize ; i ++ ) {
        if(i != numsSize-1 && nums[i] == nums[i+1] )
            continue;
        swap(nums, start, i);
        start ++;
    }
    
    return start;
}