/**
 * @file Ping.h
 * @author Florian Leuze (3308288) <st155013@stud.uni-stuttgart.de>
 * @date 12.02.2019
 * @brief Ping Class header
 */

#ifndef PING_H
#define PING_H

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "../header/IPAddress.h"
using namespace std;

/**
 *@brief Stores values that we found doing the ping, offers interfaces to access and generate those values.
 */
class Ping {
public:
    /**
     * @brief Constructor
     * @param std::vector<std::string> message - Contains the message that the Ping object has to evaluate.
     */
    Ping(std::vector<std::string> message);
    /**
     * @brief Constructor
     * @param std::vector<std::string> message - Contains the message that the Ping object has to evaluate.
     * @param OutputStream *0 - OutputStream-type object pointer
     */
    Ping(std::vector<std::string> message, OutputStream *o);
    /**
     * @brief Copy Constructor, copies every member
     * @param orig - Reference to original IPAddress-type object
     */
    Ping(const Ping& orig);
    /**
     * @brief Deconstructor, delets ip, clears message list, delets outputStream;
     */
    virtual ~Ping(); 
    /**
     * @brief Generates IPAddress-type object
     * @param std::string sIp - IP-Address of the object
     */
    void setIP(std::string sIp);
    /**
     * @brief Outdated
     * @param message
     */
    void setMessage(std::string message);
    /**
     * @brief Method to set the inNetwork value.
     * @param bool in - True for in network, false for not.
     */
    void setInNetwork(bool in);
    /**
     * @brief Returns pointer to IPAddress-type object which contains the ip extracted from the ping.
     * @return IPAddress *
     */
    IPAddress* getIP();
    /**
     * @brief Returns the complete stored ping answer
     * @return std::vector<std::string> fullMessage
     */
    std::vector<std::string> getFullMessage();
    /**
     * @brief Returns the inNetwork value.
     * @return bool inNetwork
     */
    bool getInNetwork();
    /**
     * @brief Prints the whole ping with all information that were extracted.
     */
    void printPing();
    /**
     * @brief Only prints ip address and reachability.
     */
    void printShort();
private:
    /**
     * @brief Extracts response values from the full message and stores them in member values.
     */
    void initPing();
    /**
     * @brief Returns the length of a std::tring
     * @param std::string s - String to examinate
     * @return length of s
     */
    size_t length(std::string s);
    /**
     * @brief Finds values in a string and returns the extracted values as double.
     * @param std::string source - Source where we need to search for values.
     * @param std::string target - Target that we want to find in source.
     * @return Found target as double.
     */
    double find(std::string source, std::string target); 
    /**
     * @brief Finds ip address in a string. Absolutely not generic.
     * @param std::string s - String where we wanna search.
     * @return String that only contains the IP Address
     */
    std::string findIP(std::string s);
    IPAddress *ip; /**< Extracted IP Address.*/
    std::vector<std::string> fullMessage; /**<Full ping response.*/
    bool inNetwork; /**<Was the IP reachable?*/
    uint ttl; /**<Time to live.*/
    double time; /**<Response time.*/
    uint loss; /**<Packet loss in percent.*/
    uint bytes; /**<Transmitted bytes.*/
    uint pTransmit; /**<Transmitted package count.*/
    uint pReceive; /**Received package count.*/
    OutputStream *outputStream;/**< outputstream object to make cout thread safe __still somewhat buggy__*/
};

#endif /* PING_H */

