/**
 * @file OutputStream.h
 * @author Florian Leuze (3308288) <st155013@stud.uni-stuttgart.de>
 * @date 13.02.2019
 * @brief Defined socket to access the ostream; threadsafe
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

