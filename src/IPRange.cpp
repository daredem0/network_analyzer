/**
 * @file IPRange.cpp
 * @author Florian Leuze (3308288) <st155013@stud.uni-stuttgart.de>
 * @date 12.02.2019
 * @brief IPRange Class cpp
 */

#include "../header/IPRange.h"

IPRange::IPRange(){
    error = false;
    done = false;
}

IPRange::IPRange(const IPRange& orig) {
}

IPRange::~IPRange() {
}

int* IPRange::getIp(){
    return ip;
}

void IPRange::errorSignal(){
    error = true;
    deletable = false;
    done = false;
}

bool IPRange::getDeletable(){
    return deletable;
}

//not working yet. Segfault. Propably some problem with getOKtet or setOktet
void IPRange::generateList(){
    deletable = false;
    OutputStream stream;
    try{
        if(error == true)
            throw "external exception";
        first = new IPAddress(ip);
        if(error == false) stream.writeOutput("First address: " + first->ipToString() + OutputStream::endl);
        last = new IPAddress(ip+4);
        if(error == false) stream.writeOutput("Last address: " +last->ipToString() + OutputStream::endl);
        rangeList.push_back(*first);
        int i = 0, carryover = 0;
        bool loop = true;
        std::vector<IPAddress>::iterator it = rangeList.begin();
        while(loop){
            //check if we need to do a carry over
            if(it->getOktet(4) < last->getOktet(4)      ||
                    it->getOktet(3) < last->getOktet(3) ||
                    it->getOktet(2) < last->getOktet(2) ||
                    it->getOktet(1) < last->getOktet(1)-1)
                loop = true;
            else
                loop = false;
            //make temporary ip addess and increment last octet by one
            IPAddress *ipTemp = new IPAddress(*it);
            ipTemp->setOktet(1, ipTemp->getOktet(1)+1);
            ++it;
            //check if we need to carryover
            if(ipTemp->getOktet(1) == 256){
                ipTemp->setOktet(2, ipTemp->getOktet(2)+1);
                ipTemp->setOktet(1, 1);

                if(ipTemp->getOktet(2) == 256){
                    ipTemp->setOktet(3, ipTemp->getOktet(3)+1);
                    ipTemp->setOktet(2, 0);

                    if(ipTemp->getOktet(3) == 256){
                        ipTemp->setOktet(4, ipTemp->getOktet(4)+1);
                        ipTemp->setOktet(3, 0);

                        if(ipTemp->getOktet(4) == 256){
                            break;;
                        }
                    }
                }
            }
            it = rangeList.insert(it, *ipTemp);
            //cout << "IP: " << it->ipToString() << endl;
            //std::this_thread::sleep_for(std::chrono::milliseconds(500));
            if(error == false) stream.writeOutput("IP: " + rangeList.back().ipToString() + OutputStream::endl);
            ++i;
            delete ipTemp;
            if(error == true){
                deletable = true;
                ostringstream buffer;
                error = false;
                rangeList.clear();
                buffer << "Deletable set, will return." << endl;
                stream.writeOutput(buffer.str());
                done = false;
                return;
            }
        }
        done = true;
        stream.writeOutput("Now in vector" + OutputStream::endl);
        for(std::vector<IPAddress>::iterator it2 = rangeList.begin(); it2 < rangeList.end(); ++it2){
            stream.writeOutput("IP: " + (*it2).ipToString() + OutputStream::endl);
        }
    }
    catch(...){
        stream.writeOutput("Exception cought" + OutputStream::endl);
    }
    deletable = true;
}

bool IPRange::getDone(){
    return done;
}

void IPRange::reset(){
    //rangeList.clear();
}
std::vector<IPAddress>::iterator IPRange::getEnd(){
    return rangeList.end();
}
std::vector<IPAddress>::iterator IPRange::getFirst(){
    return rangeList.begin();
}
size_t IPRange::getSize(){
    return rangeList.size();
}
IPAddress *IPRange::getIP(size_t n){
    if(n <= rangeList.size())
        return &(rangeList[n]);
    else
        return NULL;
}
