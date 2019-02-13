/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   OutputStream.cpp
 * Author: Florian Leuze
 * 
 * Created on 13. Februar 2019, 16:10
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