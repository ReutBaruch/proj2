#include "StringReverse.h"

string StringReverse::solve(string problem){
    printf("String\n");
    string result = "";
    int i = problem.length() - 1;
    for(; i >= 0; i--){
        result += problem[i];
    }
    return result;
}
