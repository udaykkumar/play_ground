
char* toHex(int num) 
{
    if( num == 0 )
        return "0";
    
    const char HEX[] = "0123456789abcdef";
    const int HEX_SIZE = 32;
    const int STACK_SIZE = 32;
    
    
    char *hex = calloc(HEX_SIZE, sizeof(char));
    char stack[STACK_SIZE];
    int   top = -1;
    
    
    
    for( int   moves = 0; num && moves < 8 ; num >>= 4, moves ++ )
        stack[++top] = HEX[(num & 0xf)];
        
     
    for( int i = 0 ; top >= 0 && i < HEX_SIZE; i ++ )
        hex[i] = stack[top--];

    return hex;
}