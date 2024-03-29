#include <regex>
#include <map>
#include <string>
#include <stdio.h>
using namespace std;
#include <iostream>



//ამოწმებს რომაული რიცხვის სისწორეს
//source - https://www.geeksforgeeks.org/validating-roman-numerals-using-regular-expression/
bool ValidationOfRomanNumerals(string str)
{
 
    const regex pattern("^M{0,3}(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})$");
 
    if (str.empty()) {
        return false;
    }
 
    if (regex_match(str, pattern)) {
        return true;
    }
    else {
        return false;
    }
}