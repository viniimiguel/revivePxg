#include "bot.h"
#include "tec.h"



int main()
{
    int life = 0;

    std::string path = "C:\\Users\\vinicius\\Desktop\\OpenCoding\\refatoracaoCppautocontrol\\macroPxg\\MacroRevive\\images\\screenshot.png";
    int xStart = 0;
    int yStart = 0;
    int xEnd = 0;
    int yEnd = 0;
    Screen* s1 = new Screen();
    s1->recordCordenites(xStart, yStart, xEnd, yEnd);
    delete s1;
    while(true)
    {
        autoRevive(life, path, xStart, yStart, xEnd,yEnd);
        if(life < 100)
        {
            std::cout << "TA MORRENDO" << std::endl;
        }
    }


    return 0;
}
