/**
 * @file IPAddress.h
 * @author Florian Leuze (3308288) <st155013@stud.uni-stuttgart.de>
 * @date 12.02.2019
 * @brief IPAddress Class header
 */

#ifndef IPADDRESS_H
#define IPADDRESS_H

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include "../header/OutputStream.h"

/**
 *@brief The IPAddress clas is mainly a container to store a single IP Value. 
 * It has rudimentary error detection and offers interfaces to access it's values.
 */
class IPAddress {
public:
    //CONSTRUCTORS/DECONSTRUCTORS/************************************************************/
    /**
    * @brief Standard constructor. Sets error to zero and builds new int type array for *ip
    */
    IPAddress();
    /**
     * @brief Copies the ip array from aIp to its private member ip
     * @param int *aIp - Pointer to int Array that contains a single IP Address. No error detection! Make sure pointer points to int[4] array.
     */
    IPAddress(int* aIp);
    /**
     * @brief Takes sIp, extracts the IP from the string and stores it.
     * @param std::string sIp - String that contains the IP address in form X.X.X.X; No error detection! 
     */
    IPAddress(std::string sIp);
    /**
     * @brief Copy Constructor. Copies the ip Array from the original object to the new one piecewise.
     * @param orig - Reference to original IPAddress-type object
     */
    IPAddress(const IPAddress& orig);
    /**
     * Standard deconstructor. Frees space allocated for int *ip
     */
    virtual ~IPAddress();
    /**
     * @brief Converts the stored IP to a std::string and returns it.
     * @return std::string with IP in form X.X.X.X
     */
    std::string ipToString();
    /**
     * @brief Method to choose a single object of the ip array. 
     * @param uint okt - okt needs to be 1 <= okt <=4, while 1 is the lowest octet aka on the left and 4 is the highest octet aka on the right.
     * @return uint with octet
     */
    uint getOktet(uint okt); //1-4 from right to leaft
    /**
     * @brief Method to set single octet in the ip array. This function is somewhat bad and should be rewritten. Would be good to implement enum type to make sure no wrong parameters are given.
     * @param uint okt - okt needs to be 1 <= okt <=4, while 1 is the lowest octet aka on the left and 4 is the highest octet aka on the right.
     * @param uint value - Needs to contain the value that shall be written
     */
    void setOktet(uint okt, uint value); 
private:
    int *ip; /**< Pointer to int[4] type array that will contain the ip address in following style |X|X|X|X|, for example |192|168|0|1|.*/
    int error; /**< Not implemented*/
};

#endif /* IPADDRESS_H */

