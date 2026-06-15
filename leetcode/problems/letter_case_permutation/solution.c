/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

bool isChar( char x )
{
    if ( x >= 'a' && x <= 'z' || x >= 'A' && x <='Z' )
        return true;
    else
        return false;
}
char alter( char x ) {
    if( x >= 'a' && x <= 'z')
        return toupper(x);
    else if( x >= 'A' && x <= 'Z')
        return tolower(x);
    else
        return '0';
}
char ** letterCasePermutationsAgain( char *S, int *returnSize, char **ret, int i, int n)
{
    if(i == n)
    {
        //printf("%s\n", S);
        (*returnSize)++;
        ret = realloc( ret , *returnSize * sizeof(*ret));
        ret[(*returnSize)-1] = malloc(n * sizeof(char));
        strcpy( ret[(*returnSize)-1], S);
        
        //for( int k = 0 ; k < *returnSize; k ++ ){
        //    printf("LOOP %d %s\n",k, ret[k]);
        //}
        return ret;
    }
    
    int idx = i;
    //for(  ; idx <  n ; idx ++ ) 
    if( isChar(S[idx]))
    {
        ret = letterCasePermutationsAgain( S, returnSize, ret, i+1, n);
            
        S[idx] = alter(S[idx]);
        ret = letterCasePermutationsAgain( S, returnSize, ret, i+1, n);
            
        S[idx] = alter(S[idx]);
        
    }
    else
    {
        ret = letterCasePermutationsAgain( S, returnSize, ret, i+1, n);
    }
    return ret;
}

char** letterCasePermutation(char* S, int* returnSize) {
    char **ret = NULL;
    return letterCasePermutationsAgain(S,returnSize,ret, 0, strlen(S));
}