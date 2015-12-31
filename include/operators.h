
/* 
 * File:   operators.h
 * Author: felix
 *
 * Created on 26. Dezember 2015, 04:48
 */

#ifndef OPERATORS_H
#define OPERATORS_H


#include "pbrain.h"
#define PBRAIN


#define BRAINFUCK_INCREMENT_POINTER '>'
#define BRAINFUCK_DECREMENT_POINTER '<'
#define BRAINFUCK_INCREMENT_VALUE '+'
#define BRAINFUCK_DECREMENT_VALUE '-'
#define BRAINFUCK_WRITE_VALUE '.'
#define BRAINFUCK_READ_VALUE ','
#define BRAINFUCK_BEGIN_LOOP '['
#define BRAINFUCK_END_LOOP ']'

#define BRAINFUCK_INCREMENT_POINTER_STRING ">"
#define BRAINFUCK_DECREMENT_POINTER_STRING  "<"
#define BRAINFUCK_INCREMENT_VALUE_STRING "+"
#define BRAINFUCK_DECREMENT_VALUE_STRING "-"
#define BRAINFUCK_WRITE_VALUE_STRING  "."
#define BRAINFUCK_READ_VALUE_STRING  ","
#define BRAINFUCK_BEGIN_LOOP_STRING  "["
#define BRAINFUCK_END_LOOP_STRING  "]"


#define MAX_CONSECUTIVES 64


#define C_INCREMENT_POINTER_ONCE "    if(ptr==BRAINFUCK_STACK_SIZE-1) ptr=0;\n    else ptr++;\n"
#define C_DECREMENT_POINTER_ONCE "    if(ptr==0) ptr=BRAINFUCK_STACK_SIZE-1;\n    else ptr--;\n"
#define C_INCREMENT_VALUE_ONCE "    stack[ptr]++;\n"//    if(stack[ptr]>BRAINFUCK_MAX_VALUE)\n        stack[ptr]=BRAINFUCK_MIN_VALUE;\n"
#define C_DECREMENT_VALUE_ONCE "    stack[ptr]--;\n"//    if(stack[ptr]<BRAINFUCK_MIN_VALUE)\n        stack[ptr]=BRAINFUCK_MAX_VALUE;\n"
#define C_INCREMENT_POINTER_CONSECUTIVE_1 "    ptr+="
#define C_DECREMENT_POINTER_CONSECUTIVE_1 "    ptr-="
#define C_INCREMENT_VALUE_CONSECUTIVE_1 "    stack[ptr]+="
#define C_DECREMENT_VALUE_CONSECUTIVE_1 "    stack[ptr]-="
#define C_CONSECUTIVE_2 ";\n"
#define C_INCREMENT_POINTER_CONSECUTIVE_3 "    if(ptr>=BRAINFUCK_STACK_SIZE)\n    ptr-=BRAINFUCK_STACK_SIZE;\n"
#define C_DECREMENT_POINTER_CONSECUTIVE_3 "    if(ptr<0)\n    ptr+=BRAINFUCK_STACK_SIZE;\n"
#define C_INCREMENT_VALUE_CONSECUTIVE_3 ""//    \n"
#define C_DECREMENT_VALUE_CONSECUTIVE_3 ""//    \n"
#define C_WRITE_VALUE "    putchar(stack[ptr]);\n"
#define C_READ_VALUE "    stack[ptr]=getchar();\n"
#define C_BEGIN_LOOP "    while(stack[ptr]!=BRAINFUCK_ESCAPE_VALUE){\n"
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

