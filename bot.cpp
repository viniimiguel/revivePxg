#include "bot.h"



std::unordered_map<std::string, BYTE> keyMap = {

    {"F1", VK_F1}, {"F2", VK_F2}, {"F3", VK_F3}, {"F4", VK_F4},
    {"F5", VK_F5}, {"F6", VK_F6}, {"F7", VK_F7}, {"F8", VK_F8},
    {"F9", VK_F9}, {"F10", VK_F10}, {"F11", VK_F11}, {"F12", VK_F12},


    {"A", 'A'}, {"B", 'B'}, {"C", 'C'}, {"D", 'D'}, {"E", 'E'}, {"F", 'F'}, {"G", 'G'},
    {"H", 'H'}, {"I", 'I'}, {"J", 'J'}, {"K", 'K'}, {"L", 'L'}, {"M", 'M'}, {"N", 'N'},
    {"O", 'O'}, {"P", 'P'}, {"Q", 'Q'}, {"R", 'R'}, {"S", 'S'}, {"T", 'T'}, {"U", 'U'},
    {"V", 'V'}, {"W", 'W'}, {"X", 'X'}, {"Y", 'Y'}, {"Z", 'Z'},


    {"a", 'A'}, {"b", 'B'}, {"c", 'C'}, {"d", 'D'}, {"e", 'E'}, {"f", 'F'}, {"g", 'G'},
    {"h", 'H'}, {"i", 'I'}, {"j", 'J'}, {"k", 'K'}, {"l", 'L'}, {"m", 'M'}, {"n", 'N'},
    {"o", 'O'}, {"p", 'P'}, {"q", 'Q'}, {"r", 'R'}, {"s", 'S'}, {"t", 'T'}, {"u", 'U'},
    {"v", 'V'}, {"w", 'W'}, {"x", 'X'}, {"y", 'Y'}, {"z", 'Z'},


    {"1", '1'}, {"2", '2'}, {"3", '3'}, {"4", '4'}, {"5", '5'},
    {"6", '6'}, {"7", '7'}, {"8", '8'}, {"9", '9'}, {"0", '0'},


    {"ESC", VK_ESCAPE}, {"SPACE", VK_SPACE}, {"ENTER", VK_RETURN},
    {"UP", VK_UP}, {"DOWN", VK_DOWN}, {"LEFT", VK_LEFT}, {"RIGHT", VK_RIGHT},
    {"SHIFT", VK_SHIFT}, {"CTRL", VK_CONTROL}, {"ALT", VK_MENU},
    {"TAB", VK_TAB}, {"CAPS", VK_CAPITAL}, {"BACKSPACE", VK_BACK}, {"DELETE", VK_DELETE}
};


BYTE mapKey(const std::string& key) {
    auto it = keyMap.find(key);
    if (it != keyMap.end()) {
        return it->second;
    }
    else {
        return 0;
    }
}
void autoRevive(int& life, std::string path, int xStart, int yStart, int xEnd, int yEnd)
{
    char lang[4] = "eng";
    Screen* s1 = new Screen();
    s1->screenshotRegion(path, xStart, yStart, xEnd, yEnd);
    std::string text = s1->imageToText(path, lang);
    std::cout << text << std::endl;
    
	std::string onlyNumbers;
    for (char c : text)
    {
        if (std::isdigit(c))
        {
            onlyNumbers += c;
        }
    }

    if (!onlyNumbers.empty()) {
        try {
            int number = std::stoi(onlyNumbers);
            std::cout << "Numero inteiro: " << number << std::endl;
            life = number;
        }
        catch (const std::invalid_argument& e) {
            std::cerr << "Erro: Argumento invalido ao converter string para inteiro: " << e.what() << std::endl;
        }
        catch (const std::out_of_range& e) {
            std::cerr << "Erro: Numero fora do alcance ao converter string para inteiro: " << e.what() << std::endl;
        }
    }
    else {
        std::cout << "Nenhum numero encontrado." << std::endl;
    }
}



void op1()
{
    int x = 0, y = 0;
    std::string keyInput;
    std::string reviveInput;

    pokeBall(x, y);
    std::cout << "Digite a tecla para o macro: " << std::endl;
    std::cin >> keyInput;
    std::cout << "Digite a tecla que seu revive esta configurado: " << std::endl;
    std::cin >> reviveInput;

    BYTE key = mapKey(keyInput);
    BYTE rev = mapKey(reviveInput);

    if (key == 0) {
        std::cout << "Tecla do macro nao reconhecida" << std::endl;
        return;
    }
    if (rev == 0) {
        std::cout << "Tecla do revive nao reconhecida" << std::endl;
        return;
    }

    std::cout << "A tecla do macro digitada foi: " << keyInput << std::endl;
    std::cout << "A tecla do revive digitada foi: " << reviveInput << std::endl;

    while (true) {
        if (GetAsyncKeyState(key) & 0x8000) {
            revive(rev, x, y);
        }
        Sleep(100);
    }
}
void pokeBall(int& x, int& y) {
    Mal* mouse = new Mal();
    std::cout << "Coloque o mouse em cima do seu Pokemon pressione o botao {SHIFT} e aguarde o beep" << std::endl;
    while (true) {
        if (GetAsyncKeyState(VK_SHIFT)) {
            auto position = mouse->mGetPosition();
            Beep(550, 300);
            x = position.first;
            y = position.second;
            delete mouse;
            break;
        }
    }
}

void revive(BYTE key, int x, int y) {
    Mal* m1 = new Mal();
    Tec* t1 = new Tec();
    m1->mMoveTo(x, y, 0);
    Sleep(15);
    m1->mClick("right", 1, 100);
    Sleep(50);
    t1->press(key, 1, 100);
    Sleep(50);
    m1->mClick("right", 1, 100);
}
