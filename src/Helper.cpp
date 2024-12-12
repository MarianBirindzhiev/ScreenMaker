#include "Helper.h"

int HelperFunctions::gcd(int a, int b)
{
    if (b == 0) 
        return std::abs(a); 
   
    return gcd(b, a % b);
}

int HelperFunctions::lcm(int a, int b)
{
    return std::abs(a * b) / gcd(a,b);
}




