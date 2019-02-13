/**
 * @file IPRange.h
 * @author Florian Leuze (3308288) <st155013@stud.uni-stuttgart.de>
 * @date 12.02.2019
 * @brief Class to store an ip range, a list containing all ips withing the range and offerinc sockets to access those
 */

#ifndef IPRANGE_H
#define IPRANGE_H
#include <chrono>
#include <thread>
#include "../header/IPAddress.h"

using namespace std;

class IPRange {
public:
    IPRange();
    IPRange(const IPRange& orig);
    virtual ~IPRange();
    int* getIp();
    void generateList();
    void errorSignal();
    bool getDeletable();
    bool getDone();
    std::vector<IPAddress>::iterator getEnd();
    std::vector<IPAddress>::iterator getFirst();
    size_t getSize();
    IPAddress *getIP(size_t n);
    void reset();
private:
    bool error, deletable, done;
    int ip[8];
    IPAddress *first;
    IPAddress *last;
    std::vector<IPAddress> rangeList;
};

#endif /* IPRANGE_H */

