/*
ID:lxlenovos1
LANG:C
TASK:wormhole
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define NUM 12
int wormhole_num;
int total = 0;

/***
 Cycles in digraphs.
 ***/
struct wormhole_pos {
    int x; 
    int y;
};

struct wormhole_pos worm[NUM];

int check_parallel(struct wormhole_pos a, struct wormhole_pos b)
{
    return (a.y == b.y ? 1 : 0);
}

int check_cross(struct wormhole_pos a1, struct wormhole_pos a2, struct wormhole_pos b1, struct wormhole_pos b2) 
{
    
}

int check_forever_loop(int value) {
    int i, j;

    /*check wormhole*/
    if value == wormhole_num - 1:
        
        for (i = value; value < wormhole_num; i++)
            check_forever_loop(i);
    }
}

check_forever_loop(0);

void main(void)
{
    FILE *fin, *fout;
    int i;
    int result = 0;

    fin = fopen("wormhole.in", "r");
    fout = fopen("wormhole.out", "w");
    
    assert(fin != NULL && fout != NULL);

    fscanf(fin, "%d", &wormhole_num);
    printf("wormhole_num is:%d\n", wormhole_num);

    for(i = 0; i < wormhole_num; i++) {
        fscanf(fin, "%d %d", &worm[i].x, &worm[i].y);
        printf("x:%d y:%d\n", worm[i].x, worm[i].y);
    }

    result = check_forever_loop();

    fprintf(fout, "%d\n", result);
    exit(0);
}
