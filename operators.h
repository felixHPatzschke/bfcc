
/* 
 * File:   operators.h
 * Author: felix
 *
 * Created on 26. Dezember 2015, 04:48
 */

#ifndef OPERATORS_H
#define OPERATORS_H


#define BRAINFUCK_INCREMENT_POINTER '>'
#define BRAINFUCK_DECREMENT_POINTER '<'
#define BRAINFUCK_INCREMENT_VALUE '+'
#define BRAINFUCK_DECREMENT_VALUE '-'
#define BRAINFUCK_WRITE_VALUE '.'
#define BRAINFUCK_READ_VALUE ','
#define BRAINFUCK_BEGIN_LOOP '['
#define BRAINFUCK_END_LOOP ']'

#define C_INCREMENT_POINTER "    if(ptr==BRAINFUCK_STACK_SIZE-1)\n        ptr=0;\n    else\n        ptr++;\n"
#define C_DECREMENT_POINTER "    if(ptr==0)\n        ptr=BRAINFUCK_STACK_SIZE-1;\n    else\n        ptr--;\n"
#define C_INCREMENT_VALUE "    stack[ptr]++;\n    if(stack[ptr]>BRAINFUCK_MAX_VALUE)\n        stack[ptr]=BRAINFUCK_MIN_VALUE;\n"
#define C_DECREMENT_VALUE "    stack[ptr]--;\n    if(stack[ptr]<BRAINFUCK_MIN_VALUE)\n        stack[ptr]=BRAINFUCK_MAX_VALUE;\n"
#define C_WRITE_VALUE "    putchar(stack[ptr]);\n"
#define C_READ_VALUE "    stack[ptr]=getchar();\n"
#define C_BEGIN_LOOP "    while(stack[ptr]!=0)\n    {\n"
#define C_END_LOOP "    }\n"

    /* List of Brainfuck operators and equivalent C code
     * 
     * >  ->  "
     *     ptr++;\n
     *     if(ptr==BRAINFUCK_STACK_SIZE)\n
     *         ptr=0;\n"
     * 
     * <  ->  "
     *     ptr--;\n
     *     if(ptr==0)\n
     *         ptr=BRAINFUCK_STACK_SIZE;\n"
     * 
     * +  ->  "
     *     stack[ptr]++;\n
     *     if(stck[ptr]>BRAINFUCK_MAX_VALUE)\n
     *         stack[ptr]=BRAINFUCK_MIN_VALUE;\n"
     * 
     * -  ->  "
     *     stack[ptr]--;\n
     *     if(stck[ptr]>BRAINFUCK_MIN_VALUE)\n
     *         stack[ptr]=BRAINFUCK_MAX_VALUE;\n"
     * 
     * .  ->  "
     *     putchar(stack[ptr]);\n"
     * 
     * ,  ->  "
     *     stack[ptr]=getchar();\n"
     * 
     * [  ->  "
     *     while(stack[ptr]!=0)\n
     *     {\n"
     * 
     * ]  ->  "
     *     }\n"
     * 
     */


#endif /* OPERATORS_H */

