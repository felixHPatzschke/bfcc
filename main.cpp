
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
#include "parsing.h"
#include "optimization.h"


inline bool checkBrackets(std::string b)
{
    return true;
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
    
    if(!checkBrackets(fileContent))
        return EXIT_FAILURE;
    fileContent = clean(&fileContent);
    optimize(&fileContent);
#ifdef DEBUG
    std::cout << fileContent << std::endl;
#endif
    cCode = parseBF(fileContent);
    
    cFileName = inputFileName;
    cFileName.append(".c");
    
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

