bool isValid(char* s) {
    
    int slen = strlen(s);
    char *stack = calloc(slen+1, sizeof(char));
    int top = -1;

    /* (asd( as)asd) */
    for(  ; *s  ; s++) {
        switch( *s ){
            case '(':
            case '{':
            case '[':
                stack[++top] = *s;
                break;
            
            case ')':
                if ( top != -1 && stack[top] == '(' )
                {
                    stack[top] = 0;
                    top--;
                }
                else
                {
                    printf("Broke at 24");
                    return false;
                }
                break;
            
            case '}':
                if ( top != -1 && stack[top] == '{' )
                {
                    stack[top] = 0;
                    top--;
                }
                else
                {
                    printf("Broke at 36");
                    return false;
                }
                break;
            
            case ']':
                if ( top != -1 && stack[top] == '[' )
                {
                    stack[top] = 0;
                    top--;
                }
                else
                {
                    printf("Broke at 50");
                    return false;
                }
                break;
        }
        
    }    
    
    if( top == -1 ) // nothing shoud be there to match
        return true;
    printf("Broke at 60");
    return false;
}