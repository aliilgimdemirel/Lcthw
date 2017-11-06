#include <stdio.h>

/* This is a comment. */
int main(int argc, char *argv[])
{
    /* How to DECLARE and ASSIGN a variable at the same time
    type name = value;
     */
    int distance = 100;

    long int longDistance = 1234567890123; //%li

    unsigned int unsignedDistance = 1234567890; //%u

    unsigned long int unsignedLongDistance = 123456789012345678; //%lu

    long long int longLongDistance = 1234567890123456789; //%lli

    unsigned long long int unsignedLongLongDistance = 1234567890123456789; //%llu

    double bigDoubleDistance = 0.12345678901234567890;

    float bigFloatDistance = 0.12345678901234567890;

    long double bigLongDoubleDistance = 0.12345678901234567890;


    // this is also a comment
    printf("You are %d miles away.\n", distance);
    
    // this is also a comment
    printf("You are %li longDistance miles away.\n", longDistance);
    
    // this is also a comment
    printf("You are %u unsignedDistance miles away.\n", unsignedDistance);
 
    // this is also a comment
    printf("You are %lu unsignedLongDistance miles away.\n", unsignedLongDistance);
 
    // this is also a comment
    printf("You are %lli longLongDistance miles away.\n", longLongDistance);
 
    // this is also a comment
    printf("You are %llu unsignedLongLongDistance miles away.\n", unsignedLongLongDistance);
 
    
    /* this is where I will try to print a double
    Real floating-point type, usually referred to as a double-precision floating-point type.
    */ 
    printf("Bigger double! distances like %.30F miles are hard to be covered on foot.\n", bigDoubleDistance);
 
    /* this is where I will try to print a float
    Real floating-point type, usually referred to as a single-precision floating-point type.
    */
    printf("Bigger float! distances like %.30f miles are hard to be covered on foot.\n", bigFloatDistance);

    /* this is where I will try to print a float
    Real long-floating-point type, usually referred to as a single-precision floating-point type.
    */
    printf("Bigger Longer Double! distances like %.30LF miles are hard to be covered on foot.\n", bigLongDoubleDistance);


    
    // this is where I will try to print a double

    
    // this is where I will try to print a double    

    return 0;
}
