#include <string.h>
#include <ctype.h>
 
inline char* word_wrap (char* buffer, char* string, int line_width) {
    int i = 0;
    int k, counter;
 
    while(i < strlen( string ) )
    {
        // copy string until the end of the line is reached
        for ( counter = 1; counter <= line_width; counter++ )
        {
            // check if end of string reached
            if ( i == strlen( string ) )
            {
                buffer[ i ] = 0;
                return buffer;
            }
            buffer[ i ] = string[ i ];
            // check for newlines embedded in the original input
            // and reset the index
            if ( buffer[ i ] == '\n' )
            {
                counter = 1;
            }
            i++;
        }
        // check for whitespace
        if ( isspace( string[ i ] ) )
        {
            buffer[i] = '\n';
            i++;
        }
        else
        {
            // check for nearest whitespace back in string
            for ( k = i; k > 0; k--)
            {
                if ( isspace( string[ k ] ) )
                {
                    buffer[ k ] = '\n';
                    // set string index back to character after this one
                    i = k + 1;
                    break;
                }
            }
        }
    }
    buffer[ i ] = 0;
 
    return buffer;
}
