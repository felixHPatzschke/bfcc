
/* 
 * File:   parsing.h
 * Author: felix
 *
 * Created on 27. Dezember 2015, 18:38
 */

#ifndef PARSING_H
#define PARSING_H

#include "debug.h"
#include "operators.h"
#include "optimization.h"

inline std::string parseBF(std::string b)
{
    std::string res;
    std::string parsed = "";
    const char* cbc = b.c_str();
    
    std::ifstream ifs("skeleton.c");
    res.assign( (std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()) );
    
    std::size_t bfCodePoint = 0;
    
    signed int consecutive_pointer_increments = 0;
    signed int consecutive_value_increments = 0 ;
    
#ifdef DEBUG
    parsed.append("    // Parsed Brainfuck code starts here\n");
#endif
    
    while(bfCodePoint <= b.length())
    {
        if(consecutive_pointer_increments==0 && consecutive_value_increments==0)
        {
            if(cbc[bfCodePoint] == BRAINFUCK_INCREMENT_POINTER)
            {
                consecutive_pointer_increments++;
            }else if(cbc[bfCodePoint] == BRAINFUCK_DECREMENT_POINTER)
            {
                consecutive_pointer_increments--;
            }else if(cbc[bfCodePoint] == BRAINFUCK_INCREMENT_VALUE)
            {
                consecutive_value_increments++;
            }else if(cbc[bfCodePoint] == BRAINFUCK_DECREMENT_VALUE)
            {
                consecutive_value_increments--;
            }else if(cbc[bfCodePoint] == BRAINFUCK_READ_VALUE)
            {
                parsed.append(C_READ_VALUE);
            }else if(cbc[bfCodePoint] == BRAINFUCK_WRITE_VALUE)
            {
                parsed.append(C_WRITE_VALUE);
            }else if(cbc[bfCodePoint] == BRAINFUCK_BEGIN_LOOP)
            {
                parsed.append(C_BEGIN_LOOP);
            }else if(cbc[bfCodePoint] == BRAINFUCK_END_LOOP)
            {
                parsed.append(C_END_LOOP);
            }else if(cbc[bfCodePoint] == BRAINFUCK_NULL_LOOP_FLAG_CHAR) // Raw parsing ends here, code optimization starts here 
            {
                parsed.append(C_NULL_LOOP);
            }else if(cbc[bfCodePoint] == BRAINFUCK_EMPTY_LOOP_FLAG_CHAR)
            {
                parsed.append(C_EMPTY_LOOP);
            }
        }else if(consecutive_value_increments==0)   //consecutive_pointer_increments != 0
        {
            if(cbc[bfCodePoint] == BRAINFUCK_INCREMENT_POINTER)
            {
                consecutive_pointer_increments++;
            }else if(cbc[bfCodePoint] == BRAINFUCK_DECREMENT_POINTER)
            {
                consecutive_pointer_increments--;
            }else
            {
                if(consecutive_pointer_increments == 1)
                {
                    parsed.append(C_INCREMENT_POINTER_ONCE);
                }else if(consecutive_pointer_increments == -1)
                {
                    parsed.append(C_DECREMENT_POINTER_ONCE);
                }else if(consecutive_pointer_increments == 0)
                {
                    // In case of something like this: ><: Do nothing
                }else if(consecutive_pointer_increments >= 0)
                {
                    std::ostringstream oss;
                    oss << C_INCREMENT_POINTER_CONSECUTIVE_1 << (consecutive_pointer_increments) << C_CONSECUTIVE_2 << C_INCREMENT_POINTER_CONSECUTIVE_3;
                    parsed.append(oss.str());
                }else if(consecutive_pointer_increments <= 0)
                {
                    std::ostringstream oss;
                    oss << C_DECREMENT_POINTER_CONSECUTIVE_1 << (-1*consecutive_pointer_increments) << C_CONSECUTIVE_2 << C_DECREMENT_POINTER_CONSECUTIVE_3;
                    parsed.append(oss.str());
                }
                consecutive_pointer_increments = 0;
                bfCodePoint--;
            }
            
        }else if(consecutive_pointer_increments==0)   //consecutive_value_increments != 0
        {
            if(cbc[bfCodePoint] == BRAINFUCK_INCREMENT_VALUE)
            {
                consecutive_value_increments++;
            }else if(cbc[bfCodePoint] == BRAINFUCK_DECREMENT_VALUE)
            {
                consecutive_value_increments--;
            }else
            {
                if(consecutive_value_increments == 1)
                {
                    parsed.append(C_INCREMENT_VALUE_ONCE);
                }else if(consecutive_value_increments == -1)
                {
                    parsed.append(C_DECREMENT_VALUE_ONCE);
                }else if(consecutive_value_increments == 0) // Actually, this shouldn't even be posssible
                {
                    // In case of something like this: -+: Do nothing
                }else if(consecutive_value_increments >= 0)
                {
                    std::ostringstream oss;
                    oss << C_INCREMENT_VALUE_CONSECUTIVE_1 << (consecutive_value_increments) << C_CONSECUTIVE_2 << C_INCREMENT_VALUE_CONSECUTIVE_3;
                    parsed.append(oss.str());
                }else if(consecutive_value_increments <= 0)
                {
                    std::ostringstream oss;
                    oss << C_DECREMENT_VALUE_CONSECUTIVE_1 << (-1*consecutive_value_increments) << C_CONSECUTIVE_2 << C_DECREMENT_VALUE_CONSECUTIVE_3;
                    parsed.append(oss.str());
                }
                consecutive_value_increments = 0;
                bfCodePoint--;
            }
            
        }
        
        // TODO: MAX_CONSECUTIVES
        
        bfCodePoint++;
    }
    
#ifdef DEBUG
    parsed.append("    // Parsed Brainfuck code ends here\n");
#endif
    
    size_t startPos = 0;
    while((startPos = res.find("//ParseOutputFlag", startPos)) != std::string::npos)
    {
        res.replace(startPos, 17, "#define BRAINFUCK_COMPILE_OUTPUT");
        startPos += 4;
    }
    startPos = 0;
    while((startPos = res.find("//ParseOutput", startPos)) != std::string::npos)
    {
        res.replace(startPos, 13, parsed);
        startPos += 4;
    }
#ifdef DEBUG
    startPos = 0;
    while((startPos = res.find("//DebugFlag", startPos)) != std::string::npos)
    {
        res.replace(startPos, 11, "#define DEBUG");
        startPos += 4;
    }
#endif
    
    return res;
    
}

#endif /* PARSING_H */

