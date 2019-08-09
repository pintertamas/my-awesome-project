#include "global.h"
#include "game.h"

void ballbounce(){
    vy += gravity;
    ypos += vy;
    if(ypos > screenHeight - radius)
    {
        ypos = screenHeight - radius;
        vy *= bounce;
    }
    DrawCircle((int)xpos,(int)ypos,10,MAROON);
    printf("%2f\n", vy);
}