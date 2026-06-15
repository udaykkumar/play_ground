/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int lo = 0 , hi = numbersSize-1;
    while( lo < hi ){
        int s = numbers[lo] + numbers[hi];
        if( s == target ){
            int *ret = malloc(2*sizeof(int));
            ret[0] = lo+1;
            ret[1] = hi+1;
            *returnSize=2;
            return ret;
        }
        if(s < target)
            lo ++;
        else
            hi --;
    }
    
    
    return NULL;
}