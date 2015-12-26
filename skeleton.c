#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//ParseOutputFlag
//DebugFlag

#define BRAINFUCK_STACK_SIZE 65536
// Maybe some machine-specific stuff
#define BRAINFUCK_MIN_VALUE 0
#define BRAINFUCK_MAX_VALUE 255
#define BRAINFUCK_ESCAPE_VALUE 0


#ifdef BRAINFUCK_COMPILE_OUTPUT
int main(int argc, char** argv)
#else
int skeletonCode()
#endif
{
    unsigned char stack[BRAINFUCK_STACK_SIZE];
    unsigned long ptr;
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

