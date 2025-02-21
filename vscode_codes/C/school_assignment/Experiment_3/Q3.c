#include <stdio.h>

int main() 
{
    int ih, im, wh, wm, mh, mm, bh, bm;

    printf("Irish time(hh:mm):");
    scanf("%d:%d", &ih, &im);

    wh = (ih - 5) % 24;
    wm = im;

    mh = (ih + 3) % 24;
    mm = im;

    bh = (ih + 7) % 24;
    bm = im;

    printf("Washington:(%02d:%02d)\n", wh, wm);
    printf("Moscow:(%02d:%02d)\n", mh, mm);
    printf("Beijing:(%02d:%02d)\n", bh, bm);

    return 0;
}
