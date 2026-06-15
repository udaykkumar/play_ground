bool isPalindrome(char* s) {
    int size = strlen(s);
    int n    = size -1;
    int i    = 0;
    
    while( i <= n ){
        //printf("%c %c\n", s[i], s[n]);
        if( tolower(s[i]) ==  tolower(s[n])){
            //printf("match %c %c\n", s[i], s[n]);
            i++;
            n--;
        }else if( !isalnum(s[i]) ){
            //printf("No Alnum i %c %c\n", s[i], s[n]);
            i++;
        }
        else if( !isalnum(s[n])){
            //printf("No Alnum n %c %c\n", s[i], s[n]);
            n--;
        }else {
            return false;
        }
    }
    
    return true;
}