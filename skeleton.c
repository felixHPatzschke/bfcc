#include <stdio.h>
#include <stdlib.h>
//ParseOutputFlag
//DebugFlag
//PBrainFlag
//16BitFlag
#define BRAINFUCK_STACK_SIZE 65536 // Maybe some machine-specific stuff?
#define BRAINFUCK_MIN_VALUE 0
#ifdef SIXTEEN_BIT
#define BRAINFUCK_MAX_VALUE 65535
unsigned short int stack[BRAINFUCK_STACK_SIZE];
#else /* SIXTEEN_BIT */
#define BRAINFUCK_MAX_VALUE 255
unsigned char stack[BRAINFUCK_STACK_SIZE];
#endif /* SIXTEEN_BIT */
#define BRAINFUCK_ESCAPE_VALUE 0
unsigned long ptr;
#ifdef PBRAIN
void (*function[BRAINFUCK_MAX_VALUE+1])();
void not_yet_defined_function()
{
#ifdef DEBUG
    printf("\n\nERROR: Undefined function call\n");
    getchar();
    exit(EXIT_FAILURE);
#else
    exit(EXIT_FAILURE);
#endif
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
#ifdef PBRAIN
    for(ptr = 0; ptr <= BRAINFUCK_MAX_VALUE; ptr++)
    {
        function[ptr] = not_yet_defined_function;
    }
#endif /* PBRAIN */
    ptr = 0;
//ParseOutput
#ifdef DEBUG
    printf("\n\nPress [ENTER] to exit the program.\nIronic, isn't it?\n");
    getchar();
#endif
    return EXIT_SUCCESS;
}