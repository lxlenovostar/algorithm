/*
 * 292:Nim Game
 */

#include <stdio.h>
#include <stdlib.h>

typedef int bool;
#define true 1
#define false 0

bool canWinNim(int n) {
    return (n % 4 != 0);
}

int main(void)
{
    printf("result is:%d\n", canWinNim(10));
    //printf("result is:%d\n", canWinNim(4));
    //printf("result is:%d\n", canWinNim(3));
    //printf("result is:%d\n", canWinNim(100));
    return 0;
}
