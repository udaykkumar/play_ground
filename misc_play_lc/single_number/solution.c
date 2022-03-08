
int compare( const void *x, const void *y)
{
    return *( int *)x  - *( int *) y;
}

int singleNumber(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);
    int i = 0;
    for(  ; i < numsSize-1 ; i ++ )
    {
        if( nums[i] == nums[i+1] )
            i++;
        else
            return nums[i];
    }
    
    return nums[i];
}