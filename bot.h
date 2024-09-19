#pragma once
#include "mouse.h"
#include "tec.h"
#include <unordered_map>
#include <iostream>
#include "screen.h"
#include <cctype>

BYTE mapKey(const std::string& key);
void pokeBall(int& x, int& y);
void revive(BYTE key, int x, int y);
void op1();
void autoRevive(int& life, std::string path, int xStart, int yStart, int xEnd, int yEnd);