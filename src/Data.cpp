/**
 * @file Data.cpp
 * @author Florian Leuze (3308288) <st155013@stud.uni-stuttgart.de>
 * @date 11.02.2019
 * @brief Data class cpp file
 */

#include "../header/Data.h"

Data::Data(){
}

Data::Data(const Data& orig) {
}

Data::~Data() {
    delete ip;
}

void Data::setIPRange(std::string firstIP, std::string lastIP){
    this->ip = new Network(firstIP, lastIP);
}