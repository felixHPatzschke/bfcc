
/* 
 * File:   optimization.h
 * Author: felix
 *
 * Created on 27. Dezember 2015, 18:46
 */

#ifndef OPTIMIZATION_H
#define OPTIMIZATION_H

#include "debug.h"
#include "operators.h"
#include <string>


#define BRAINFUCK_NULL_LOOP_A "[-]"
#define BRAINFUCK_NULL_LOOP_B "[+]"
#define BRAINFUCK_NULL_LOOP_FLAG_STRING "0"
#define BRAINFUCK_NULL_LOOP_FLAG_CHAR '0'
#define C_NULL_LOOP "    stack[ptr]=BRAINFUCK_ESCAPE_VALUE;\n"

#define BRAINFUCK_EMPTY_LOOP "[]"
#define BRAINFUCK_EMPTY_LOOP_FLAG_STRING 'E'
#define BRAINFUCK_EMPTY_LOOP_FLAG_CHAR 'E'
#define C_EMPTY_LOOP "    if(stack[ptr]!=BRAINFUCK_ESCAPE_VALUE) return EXIT_FAILURE;\n"

#define BRAINFUCK_NULL_LOOP_TERMINATED_LOOP_STRING_1 "["
#define BRAINFUCK_NULL_LOOP_TERMINATED_LOOP_STRING_2 "0]"
#define BRAINFUCK_NULL_LOOP_TERMINATED_LOOP_FLAG_1_STRING "{"
#define BRAINFUCK_NULL_LOOP_TERMINATED_LOOP_FLAG_2_STRING "}"
#define BRAINFUCK_NULL_LOOP_TERMINATED_LOOP_FLAG_1_CHAR '{'
#define BRAINFUCK_NULL_LOOP_TERMINATED_LOOP_FLAG_2_CHAR '0}'
#define C_NULL_LOOP_TERMINATED_LOOP_1 "    if(stack[ptr]==BRAINFUCK_ESCAPE_VALUE){\n"
#define C_NULL_LOOP_TERMINATED_LOOP_2 "    stack[ptr]=BRAINFUCK_ESCAPE_VALUE;\n    }\n"


inline std::string clean(std::string *b)
{
    const char* cs = b->c_str();
    std::string res = "";
    std::size_t p = 0;
    while(p<=b->length())
    {
        if(cs[p] == BRAINFUCK_INCREMENT_POINTER)
            res.append(BRAINFUCK_INCREMENT_POINTER_STRING);
        else if(cs[p] == BRAINFUCK_DECREMENT_POINTER)
            res.append(BRAINFUCK_DECREMENT_POINTER_STRING);
        else if(cs[p] == BRAINFUCK_INCREMENT_VALUE)
            res.append(BRAINFUCK_INCREMENT_VALUE_STRING);
        else if(cs[p] == BRAINFUCK_DECREMENT_VALUE)
            res.append(BRAINFUCK_DECREMENT_VALUE_STRING);
        else if(cs[p] == BRAINFUCK_WRITE_VALUE)
            res.append(BRAINFUCK_WRITE_VALUE_STRING);
        else if(cs[p] == BRAINFUCK_READ_VALUE)
            res.append(BRAINFUCK_READ_VALUE_STRING);
        else if(cs[p] == BRAINFUCK_BEGIN_LOOP)
            res.append(BRAINFUCK_BEGIN_LOOP_STRING);
        else if(cs[p] == BRAINFUCK_END_LOOP)
            res.append(BRAINFUCK_END_LOOP_STRING);
        
        p++;
    }
    return res;
}

inline void flag_null_loops(std::string *b)
{
    std::size_t startPos = 0;
    while((startPos = b->find("[-]", startPos)) != std::string::npos)
    {
        b->replace(startPos, 3, BRAINFUCK_NULL_LOOP_FLAG_STRING);
        startPos += 4;
    }
    startPos = 0;
    while((startPos = b->find("[+]", startPos)) != std::string::npos)
    {
        b->replace(startPos, 3, BRAINFUCK_NULL_LOOP_FLAG_STRING);
        startPos += 4;
    }
}

inline void flag_empty_loops(std::string *b)
{
    
}

inline void flag_null_loop_terminated_loops(std::string *b)
{
    
}

inline void optimize(std::string *b)
{
    flag_null_loops(b);
    flag_empty_loops(b);
    flag_null_loop_terminated_loops(b);
    
}

#endif /* OPTIMIZATION_H */

