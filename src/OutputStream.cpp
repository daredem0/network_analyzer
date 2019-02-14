/**
 * @file OutputStream.cpp
 * @author Florian Leuze (3308288) <st155013@stud.uni-stuttgart.de>
 * @date 13.02.2019
 * @brief OutputStream Class cpp
 */

#include "../header/OutputStream.h"

const std::string OutputStream::endl = "\n";

OutputStream::OutputStream() {
}

OutputStream::OutputStream(const OutputStream& orig) {
}

OutputStream::~OutputStream() {
}

void OutputStream::writeOutput(std::string s){
    std::mutex mutex_output;
    mutex_output.lock();
    output = s;
    mutex_output.unlock();
    mutex_output.lock();
    outputStream = new std::thread(&OutputStream::outputWorker, (void *)&s);
    outputStream->join();
    mutex_output.unlock();
    delete outputStream;
}

void OutputStream::outputWorker(void *data){
    std::mutex mutex_output;
    mutex_output.lock();
    std::cout << *((std::string *)data);
    mutex_output.unlock();
}
std::string OutputStream::ostreamToString(std::ostringstream s){
    return s.str();
}