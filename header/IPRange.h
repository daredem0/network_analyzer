/**
 * @file IPRange.h
 * @author Florian Leuze (3308288) <st155013@stud.uni-stuttgart.de>
 * @date 12.02.2019
 * @brief IPRange Class header
 */

#ifndef IPRANGE_H
#define IPRANGE_H
#include <chrono>
#include <thread>
#include "../header/IPAddress.h"

using namespace std;

/**
 *@brief The IPRange class stores and organises the whole scan Range. The Input of the user will be stored here. Furhtermore it generates and stores a list
 * with all IP-Addresses in between the entered first and last address. To make this class thread-safe some controll mechanims were implemented although still somewhat buggy.
 */
class IPRange {
public:
    /**
     * @brief Standard Conctructor, sets error and done to false.
     */
    IPRange();
    /**
     * Standard copy Constructor.
     * @param orig - Reference to original IPAddress-type object
     */
    IPRange(const IPRange& orig);
    /**
     * Standard Deconstructor.
     */
    virtual ~IPRange();
    /**
     * @brief Simply returns pointer to ip array. Careful, with big power comes big responsibility. This is actually a bad idea. 
     * @return int* to ip[8] type array
     */
    int* getIp();
    /**
     * Generates the vector containing all IP Addresses to be scanned. Also generating those addresses. This method is mostly thread safe. 
     * Error handling was implemented. Prints lots of information to terminal. __This needs to be reduced still__.
     * When finished successfully this method sets done to true. If the error bit will be set externally (this makes sure we can abort this method since it can be somewhat 
     * time consuming for big ranges), this method sets deletable to false, error to false, clears the vector containing addresses and sets done to false.
     */
    void generateList();
    /**
     * Sets error true and deletable as well as done to false.
     */
    void errorSignal();
    /**
     * @brief Method to get status of this object incase we need to know if it can be deleted.
     * @return bool deletable
     */
    bool getDeletable();
    /**
     * @brief Method to get status of generateList(). 
     * @return bool done, true if List was generated successfully (I know, its a vector not a list.)
     */
    bool getDone();
    /**
     * @brief Returns an iterator __after__ the last member of the std::vector containinng the address range.
     * @return std::vector<IPAddress>::iterator
     */
    std::vector<IPAddress>::iterator getEnd();
    /**
     * @brief Returns an iterator to the first member of the std::vector containinng the address range.
     * @return std::vector<IPAddress>::iterator
     */
    std::vector<IPAddress>::iterator getFirst();
    /**
     * @brief Returns the size of thhe std::vector that contains the address range.
     * @return size_t
     */
    size_t getSize();
    /**
     * Returns a specific IP of the rainge list defined through n.
     * @param size_t n . Specifies the position in the list that shall be returned. Somewhat error safe.
     * @return IPAddress *
     */
    IPAddress *getIP(size_t n);
    /**
     * @brief Does nothing so far. Will be deleted somewhen propably.
     */
    void reset();
private:
    bool error;/**< Value which can be set from external through interface in case list-generation has to be aborted safely.*/
    bool deletable;/**< Value which can be asked from external through interface to be able to safely delete the object.*/
    bool done; /**< Will be set when the list was generated successfully.*/
    int ip[8]; /**< Contains the first IP in [0]-[3] and the last in [4]-[7]. Note that this will be exchanged to IPAddress-type objects*/
    IPAddress *first; /**< IP-Address type object containing the first address. */
    IPAddress *last; /**< IP-Address type object containing the last address.*/
    std::vector<IPAddress> rangeList; /**< Contains the whole IP-Range.*/
};

#endif /* IPRANGE_H */

