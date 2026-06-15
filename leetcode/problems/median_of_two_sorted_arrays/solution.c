double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int a1_len = nums1Size + nums2Size;
    int *a1    = malloc(a1_len * sizeof(int));

    // nums1 = 1, 2, 3, 4, 5, 6 nums1Size = 7
    // nums2 = 4, 5, 7, 9, 29  nums2Size = 5
    // a1[] = 
    // 13
    for( int i = 0, nums1_i = 0, nums2_i = 0 ; i < a1_len ; i ++ )
    {
        if( nums1_i < nums1Size && nums2_i < nums2Size )
        {
            if( nums1[nums1_i] < nums2[nums2_i] )
                a1[i] = nums1[nums1_i ++];
            else
                a1[i] = nums2[nums2_i++];
        }
        else if ( nums1_i < nums1Size  )
        {
            a1[i] = nums1[nums1_i ++];
        }
        else if (nums2_i < nums2Size )
        {
            a1[i] = nums2[nums2_i ++];
        }
    }
    
    //for( int i = 0; i < nums1Size;  i ++ )
    //    printf("nums 1 %d \n", nums1[i]);
    
    //for( int i = 0; i < nums2Size;  i ++ )
    //    printf("nums 2 %d \n", nums2[i]);
    
    
    //for( int i = 0; i < a1_len;  i ++ )
    //    printf("a1 %d %d \n", i, a1[i]);
    
    
    double median = 0;
    
    if( a1_len&0x01 )
    {
        int index = (int)(a1_len/2) ;
        median = a1[index];
    }
    else
    {
        int index1 = (int)(a1_len/2);
        if( index1 >= 0 ){ 
            int index2 = index1-1;
            if( index2 >= 0 ){
                median = (double)(a1[index1] + a1[index2])/2;    
            }
        }
    }
    
    return median;
}