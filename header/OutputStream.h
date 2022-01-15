/**
 * @file OutputStream.h
 * @author Florian Leuze (3308288) <st155013@stud.uni-stuttgart.de>
 * @date 13.02.2019
 * @brief OutputStream Class header
 */

#ifndef OUTPUTSTREAM_H
#define OUTPUTSTREAM_H
#include <mutex>
#include <thread>
#include <iostream>
#include <string>
#include <sstream>

/**
 *@brief Defines interface to access the ostream in a threadsafe manner. Still somewhat buggy :(
 */
class OutputStream {
public:
    /**
     * @brief Standard Constructor.
     */
    OutputStream();
    /**
     * @brief Standard copy Constructor.
     * @param orig - Reference to original IPAddress-type object
     */
    OutputStream(const OutputStream& orig);
    /**
     * @brief Standard Deconstructor.
     */
    virtual ~OutputStream();
    /**
     * @brief Starts thread to write output to ostream.
     * @param std::string s - Shall contain the string that has to be written to the ostream.
     */
    void writeOutput(std::string s);
    /**
     * @brief Converts a std::stringstream to an std::string
     * @param std::ostringstream s - ostringstream that needs to be converted.
     * @return std::string
     */
    static std::string ostreamToString(std::ostringstream s);
    /**
     * @brief Worker that writes string where *data points to the ostream.
     * @param void *data - has to point to std::string
     */
    static void outputWorker(void *data);
    static const std::string endl; /**< constant endl for convenience when using + with std::string*/
private:
    std::string output; /**< Member used to temporarily store the incoming ostream. */
    std::thread *outputStream;/**< outputstream object to make cout thread safe __still somewhat buggy__*/
};
#endif /* OUTPUTSTREAM_H */

