
/* 
 * File:   debug.h
 * Author: felix
 *
 * Created on 27. Dezember 2015, 18:41
 */

#ifndef DEBUG_H
#define DEBUG_H

#define DEBUG

#include <string>
#include <iostream>

#ifdef DEBUG

std::string shortenFileName(std::string s)
{
    s.erase(s.begin(), s.begin()+s.find_last_of('/'));
    s.erase(s.begin(), s.begin()+s.find_last_of('\\'));
    return s;
}

#define LOG(msg) \
    std::cout << shortenFileName(__FILE__) << " in line " << __LINE__ << ":\n" << msg << std::endl

#else /* DEBUG */

#define LOG(msg)

#endif /* DEBUG */

#endif /* DEBUG_H */

