void swap( int *a, int i, int j)
{
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}

int removeElement(int* nums, int numsSize, int val) {
    int hole = 0;
    for( int i = 0 ; i < numsSize ; i ++ ) {
        if( nums[i] == val )
            continue;
        swap(nums, hole++, i);
    }
    
    return hole;
}