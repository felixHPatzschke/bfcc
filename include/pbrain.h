
/* 
 * File:   pbrain.h
 * Author: felix
 *
 * Created on 27. Dezember 2015, 19:18
 */

#ifndef PBRAIN_H
#define PBRAIN_H

#define PBRAIN_MAX_DEPTH 64

#define PBRAIN_CALL_FUNCTION ':'
#define PBRAIN_BEGIN_FUNCTION '('
#define PBRAIN_END_FUNCTION ')'

#define PBRAIN_CALL_FUNCTION_STRING ":"
#define PBRAIN_BEGIN_FUNCTION_STRING "("
#define PBRAIN_END_FUNCTION_STRING ")"

#define C_CALL_FUNCTION "    function[stack[ptr]]();\n"
#define C_BEGIN_FUNCTION_1 "    void pbrain_function"
#define C_BEGIN_FUNCTION_3 "(void){\n"
#define C_END_FUNCTION_1 "    }\n    function[stack[ptr]]=pbrain_function"
#define C_END_FUNCTION_3 ";\n"

#endif /* PBRAIN_H */

