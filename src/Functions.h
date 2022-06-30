#pragma once
#include <iostream>

std::string stringRightAlign(int newlength, std::string str = " ", char char_ = ' ');
std::string stringLeftAlign(int newlength, std::string str = " ", char char_ = ' ');
std::string stringCenterAlign(int newlength, std::string str = " ", char char_ = ' ');
void instruction();
int GetNum(int returnNum = -1);
