
int compare( const void *x, const void *y ) {
    return  *( int *)x - *( int * )y;
}

int min(int x, int y ){
    return (x < y ) ?x : y;
}
int arrayPairSum(int* nums, int numsSize) {
    qsort( nums, numsSize, sizeof(int), compare );
    
    for( int i = 0 ; i < numsSize-1 ;i +=2 ){
        printf("%d ", nums[i]);
    }
    
    int sum = 0;
    for( int i = 0 ; i < numsSize-1 ;i +=2 ){
        sum += min( nums[i], nums[i+1]);
    }
    return sum;
}


