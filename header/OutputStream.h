/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   OutputStream.h
 * Author: Florian Leuze
 *
 * Created on 13. Februar 2019, 16:10
 */

#ifndef OUTPUTSTREAM_H
#define OUTPUTSTREAM_H
#include <mutex>
#include <thread>
#include <iostream>
#include <string>
#include <sstream>

class OutputStream {
public:
    OutputStream();
    OutputStream(const OutputStream& orig);
    virtual ~OutputStream();
    void writeOutput(std::string s);
    static const std::string endl;
    static std::string ostreamToString(std::ostringstream s);
    static void outputWorker(void *data);
private:
    std::string output;
    int a;
    std::thread *outputStream;
};
#endif /* OUTPUTSTREAM_H */

