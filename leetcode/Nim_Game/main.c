/*
 * 292:Nim Game
 */

#include <stdio.h>
#include <stdlib.h>

typedef int bool;
#define true 1
#define false 0

bool canWinNim(int n) {
    if (n <= 3 && n >= 0)
        return true;
    else if (n == 4)
        return false;
    else {
        //针对自身和对手的最优策略
        //if (n - 1 == 0 || n - 2 <= 0 || n -3 <= 0) //对手
        if (n >= 3)
            canWinNim(n - 3);
        else if (n >= 2)
            canWinNim(n - 2);
        else 
            canWinNim(n - 1);
    } 
    return false;    
}

int main(void)
{
    printf("result is:%d\n", canWinNim(10));
    //printf("result is:%d\n", canWinNim(4));
    //printf("result is:%d\n", canWinNim(3));
    //printf("result is:%d\n", canWinNim(100));
    return 0;
}
