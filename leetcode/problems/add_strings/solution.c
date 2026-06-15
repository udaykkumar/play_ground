char* addStrings(char* num1, char* num2) {
    int n1 = strlen(num1);
    int n2 = strlen(num2);
    char *n = malloc( (((n1>n2)?n1:n2) + 2) * sizeof(char) );
    int carry = 0, i = 0, s;
    for( n1--, n2-- ; n1 >= 0 && n2 >= 0 ; i ++, n1-- , n2--) {
        s = num1[n1]-'0' + num2[n2]-'0' + carry ;
        carry = s/10;
            s %= 10;
        n[i] = s + '0';
       // printf("L1 %s\n", n);
    }
    
    for( ; n1 >= 0 ; i ++, n1 -- ){
        int s = num1[n1]-'0' + carry ;
        carry = s/10;
            s %= 10;
        n[i] = s + '0';
        //printf("L2 %s\n", n);
    }

    for( ; n2 >= 0 ; i++, n2-- ) {
        int s = num2[n2]-'0' + carry ;
        carry = s/10;
            s %= 10;
        n[i] = s + '0';
        //printf("L3 %s\n", n);
    }
    
    if( carry > 0 ) {
        n[i++] = carry + '0';    
    }
    n[i] = '\0';
    for( int x = 0, y = i-1 ; x < y; x ++, y -- ){
        char c = n[y];
        n[y] = n[x];
        n[x] = c ;
        //printf("L4 %s\n", n);
    }
    
    //printf("%s\n", n);
    return n;
}