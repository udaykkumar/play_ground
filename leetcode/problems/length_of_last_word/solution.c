int lengthOfLastWord(char* s) {
    int len = strlen(s);
    int wLen = 0;
    // Trim Spaces at the end
    while( s[len-1] == ' ' && len > 0 )
        len --;
    
    while( s[len-1] != ' ' && len > 0 ){  
        wLen ++ ;  len -- ; 
    }
    
    return wLen;
}