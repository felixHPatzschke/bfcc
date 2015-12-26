
/* 
 * File:   main.cpp
 * Author: felix
 *
 * Created on 26. Dezember 2015, 03:43
 */

#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "operators.h"


#define DEBUG


inline bool checkBrackets(std::string b)
{
    return true;
}

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
                }else if(consecutive_value_increments == 0)
                {
                    // In case of something like this: ><: Do nothing
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
        
        
        
        bfCodePoint++;
    }
    
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

int main(int argc, char** argv)
{
#ifdef DEBUG
    printf("Run Arguments:\n");
    for(int c=0; c<argc; c++)
    {
        printf(argv[c]);
        printf("\n");
    }
#endif
    
    char* inputFileName;
    std::string cFileName = "";
    std::string outputFileName = "";
    
    std::string fileContent = "";
    std::string cCode = "";
    
#ifdef DEBUG
    inputFileName = "mandelbrot.b";
    outputFileName = "mandelbrot.exe";
    
#else
    if(argc == 0)
    {
        std::cin >> inputFileName;        
    }else if(argc == 1)
    {
        std::cin >> inputFileName;
    }else if(argc >= 2)
    {
        inputFileName = argv[2];
    }else
    {
        return EXIT_FAILURE;
    }
#endif /* DEBUG */

#ifdef DEBUG
    printf("Parsing file ");
    printf(inputFileName);
    printf("...\n");
#endif
    
    std::ifstream ifs(inputFileName);
    fileContent.assign( (std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()) );
    
#ifdef DEBUG
    std::cout << fileContent << std::endl;
#endif
    if(!checkBrackets(fileContent))
        return EXIT_FAILURE;
    cCode = parseBF(fileContent);
#ifdef DEBUG
    std::cout << cCode << std::endl;
#endif
    
    cFileName = inputFileName;
    cFileName.append(".c");
#ifdef DEBUG
    std::cout << (cFileName) << std::endl;
#endif
    
    std::ofstream outstream(cFileName.c_str());
    outstream << cCode;
    outstream.close();
    
    std::string gccCommand = "gcc \"" + cFileName + "\" -o \"" + outputFileName + "\"";
#ifdef DEBUG
    std::cout << (gccCommand) << std::endl;
#endif
    std::system(gccCommand.c_str());
    
    return EXIT_SUCCESS;
}

