#include "RosalilaGraphics/RosalilaGraphics.h"
#include "RosalilaInputs/RosalilaInputs.h"
#include "RosalilaSound/RosalilaSound.h"
#include <iostream>

using namespace std;

int main()
{
    RosalilaGraphics* rosalila_graphics = new RosalilaGraphics();
    Receiver* receiver = new Receiver();
    Sound* sound = new Sound();
    Image* image = rosalila_graphics->getTexture("test.png");
    sound->playMusic("music.ogg");
    sound->addSound("test sound","test.ogg");

    int x=0;
    int y=0;

    while(true)
    {
        if(receiver->IsKeyPressed(SDLK_DOWN))
        {
            sound->playSound("test sound");
            y++;
        }else if(receiver->IsKeyPressed(SDLK_UP))
        {
            sound->playSound("test sound");
            y--;
        }else if(receiver->IsKeyPressed(SDLK_RIGHT))
        {
            sound->playSound("test sound");
            x++;
        }else if(receiver->IsKeyPressed(SDLK_LEFT))
        {
            sound->playSound("test sound");
            x--;
        }

        rosalila_graphics->draw2DImage
        (   image,//Image*
            image->getWidth(),image->getHeight(),//width, height
            x,y,//x,y
            1.0,//scale
            0.0,//rotation
            false,//flip horizontally
            0,0,//depth effect x,y
            Color(255,255,255,255),//collor effect
            false);//camera alignment

        receiver->updateInputs();
        rosalila_graphics->updateScreen();
    }
    return 0;
}
