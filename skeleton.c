#include <stdio.h>
#include <stdlib.h>
//ParseOutputFlag
//DebugFlag
//PBrainFlag
//16BitFlag
#define BRAINFUCK_STACK_SIZE 65536
// Maybe some machine-specific stuff?
#define BRAINFUCK_MIN_VALUE 0
#ifdef SIXTEEN_BIT
#define BRAINFUCK_MAX_VALUE 65535
#else /* SIXTEEN_BIT */
#define BRAINFUCK_MAX_VALUE 255
#endif /* SIXTEEN_BIT */
#define BRAINFUCK_ESCAPE_VALUE 0

unsigned char stack[BRAINFUCK_STACK_SIZE];
unsigned long ptr;

#ifdef PBRAIN
//PBrainFunctions

inline void callFunction(char ref)
{
    
}
#endif /* PBRAIN */

#ifdef BRAINFUCK_COMPILE_OUTPUT
int main()
#else
int skeletonCode()
#endif
{
    for(ptr = 0; ptr < BRAINFUCK_STACK_SIZE; ptr++)
    {
        stack[ptr] = BRAINFUCK_MIN_VALUE;
    }
    ptr = 0;
//ParseOutput
#ifdef DEBUG
    printf("\n\nPress [ENTER] to exit the program.\nIronic, isn't it?\n");
    getchar();
#endif
    return EXIT_SUCCESS;
}