/**
 * @file Network.h
 * @author Florian Leuze (3308288) <st155013@stud.uni-stuttgart.de>
 * @date 08.02.2019
 * @brief Network Class header
 */

#ifndef NETWORK_H
#define NETWORK_H
#include <string>
#include <iostream>
#include <cstdio>
#include <vector>
#include <gtk/gtk.h>
#include <thread>
#include <sstream>
#include "../header/Ping.h"
#include "../header/IPRange.h"


using namespace std;

/**
 *@brief The Network class orchestrates the whole network access including pings and stores results of the network examinations. It was
 * written thread safe and supports multithreading.
 */
class Network {
public:
    /**
     * @brief Standard COnstructor, sets thPing to NULL and builds new OutputStream type object.
     */
    Network();
    /**
     * @brief Constructor which also initialises a new ip address. __IP decryption should be exported to IPRange Class__.
     * @param std::string first - Contains first IP of the range in form of X.X.X.X. Not error safe!
     * @param std::string last - Contains last IP of the range in form of X.X.X.X. Not error safe!
     */
    Network(std::string first, std::string last);
    /**
     * @brief Standard copy Constructor.
     * @param orig - Reference to original IPAddress-type object
     */
    Network(const Network& orig);
    /**
     * @brief Deconstructor. Frees memory allocated for thPing, range and outputStream.
     */
    virtual ~Network();
    /**
     * @brief Extracts pointer to int[8] Array containing ip Address from the IPRange object.
     * @return int*
     */
    int* getIP();
    /**
     * @brief Returns depending on parameter the first or last ip stored in range object. Old implementation, should be coded new. ip = 0 -> first address, ip = 1-> last address
     * @param int ip - Must be either 1 or 0
     * @return std::string
     */
    std::string ipToString(int ip);
    /**
     * @brief Checks the error value and prints output to outPutstream depending on the value. Furthermore returns the error vlaue
     * @return int error
     */
    int checkIP();
    /**
     * @brief Same as ping(std::string ip), just takes the first ip of the range. Mainly for debugging convenience, might be deleted soon.
     * @return 0
     */
    int ping();
    /**
     * @brief Generates a ping command for the ip in parameter and pushes it to terminal using popen. Takes the stream from terminal and evaluates it. Furthermore stores it in a std::vector linewise. 
     * Lastly generates Ping-type object with read values and pushes it to the pingResults std::vector.
     * @param std::string ip
     * @return Nothing, might be implemented for error detection.
     */
    int ping(std::string ip);
    /**
     * @brief Will make a new detached thread to ping all ip addresses in the range and start the pingWorker. Cleans up after itself.
     * @return  0
     */
    int pingAll();
    /**
     * @brief Iterates through std::vector containing ping results and calls member function of Ping to fully print the ping.
     */
    void printPing();
    /**
     * @brief Iterates through std::vector containing ping results and calls member function of Ping to shortly print the ping.
     */
    void pingShortRes();
    /**
     * @brief Returns first ip as a std::string
     * @return std::string
     */
    std::string firstIP_toString();
    /**
     * @brief Returns last ip as a std::string
     * @return std::string
     */
    std::string lastIP_toString();
    /**
     * @brief Starts the thread active worker and joins it when done. Gives address to thPing to the worker. Cleans up after itself. Returns a true or false value to indicate activeness of the thread.
     * @return bool
     */
    bool threadActive();
    /**
     * @brief Checks if the ping thread is active. Sets errorSignal() in IPRange object to safely end IPRange scanning. Then resets it and deletes thPing. Sets the member pointer to thPing to NULL.
     */
    void threadKill();
    /**
     * @brief Reserves n space in pingResluts vector.
     * @param size_t n - Space that shall be reserved in vector.
     */
    void reserveList(size_t n);
    std::vector<Ping> pingResults;/**< std::vector containing all pings with results.*/
    std::thread *thPing; /**< Pointer to Ping thread.*/
    std::thread *org; /**< Pointer to organisation thread.*/
private:
    /**
     * @brief Worker to organise pings in extra thread.
     * @param void *data - Pointer to IPRange type object. 
     * @param void *list - Pointer to std::vector that stored iprange to get its size
     */
    void pingWorker(void *data, void *list);
    /**
     * @brief Checks if the pointer it received is NULL. If so then it rights false to where *data points. Otherwise true.
     * @param void *data - Pointer to bool value where we will write the state of the thread.
     * @param void *ptr Pointer to the thread that shall be examinated.
     */
    void threadActiveWorker(void *data, void *ptr);
    /**
     * @brief Checks the IP for wrong user inputs. Sets error value.
     */
    void check();
    IPRange *range;/**<IPRange type object containing information about the ip range.*/
    int error; /**< Error value.*/
    const int trials = 1; /**< const to define how often a ping shall be tried. Use low number because its slow as fuck already.*/
    const int time = 1; /**< const to define how many pings shall be sent. Use low number because its slow as fuck already.*/
    OutputStream *outputStream;/**< outputstream object to make cout thread safe __still somewhat buggy__*/
};

#endif /* NETWORK_H */

