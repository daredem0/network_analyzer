/**
 * @file Network.cpp
 * @author Florian Leuze (3308288) <st155013@stud.uni-stuttgart.de>
 * @date 08.02.2019
 * @brief Network Class cpp
 */

#include "../header/Network.h"

using namespace std;

Network::Network(){
    thPing = NULL;
    outputStream = new OutputStream();
}

Network::Network(std::string first, std::string last){
    thPing = NULL;
    error = 0;
    outputStream = new OutputStream();
    range = new IPRange();
    ostringstream buffer;
    for(int j = 0; j < 8; ++j){
        *(range->getIp()+j) = 0;
    }
    buffer << "initialized decryption of ip addresses" << std::endl;
    outputStream->writeOutput(buffer.str());
    std::string temp, temp2;
    int i = 0;
    for(std::string::iterator it = first.begin(); it != first.end(); ++it){
        temp2 = *it; //store the value wher iterator points in a temporary string. No idea why C++ wont accept the comparison of *it with "."
        if (temp2 != "."){ 
            temp += *it; 
        }
        else{
            *(range->getIp()+i) = std::stoi(temp);
            ++i;
            temp = "";
        }
    }
    (range->getIp())[i] = std::stoi(temp);
    ++i;
    temp = "";
    
    i = 4;
    for(std::string::iterator it = last.begin(); it != last.end(); ++it){
        temp2 = *it;
        if (temp2 != "."){
            temp += *it;
        }
        else{
            *(range->getIp()+i) = std::stoi(temp);
            ++i;
            temp = "";
        }
    }
    *(range->getIp()+i) = std::stoi(temp);
    ++i;
    temp = "";
    check();
    if(error == 0)
        outputStream->writeOutput("decryption done. Seems all went fine" + OutputStream::endl);
    else
        outputStream->writeOutput("something seems off. You might want to check your address" + OutputStream::endl);
}

Network::Network(const Network& orig) {
}

Network::~Network() {
    delete thPing;
    delete range;
    delete outputStream;
}

int* Network::getIP(){
    return (range->getIp());
}

//0 for first address, 1 for second address, every other value for individual address
std::string Network::ipToString(int ip){
    std::string temp = "";
    if(ip >= 0 && ip <3){
        switch(ip){
            case 0:
                for(int i = 0; i<4; ++i){
                    temp += std::to_string(*(range->getIp()+i));
                    if(i<3)
                        temp += ".";
                }
                return temp;
            case 1:
                for(int i = 4; i<8; ++i){
                    temp += std::to_string(*(range->getIp()+i));
                    if(i<7)
                        temp += ".";
                }
                return temp;
            default:
                return "";
        }
    }
    else{
        //do something
        return "";
    }
}

int Network::checkIP(){
    switch(error){
        case -3:
            outputStream->writeOutput("Some octet is higher than 255. Please insert an IP in the appropriate range (0 <= octet <= 255)." + OutputStream::endl);
            break;
        case -2:
            outputStream->writeOutput("First address is higher than last address. That doesn't make sense." + OutputStream::endl);
            break;
        case -1:
            outputStream->writeOutput("Last octet seems to be zero in either first or last address. Are you sure you want that?" + OutputStream::endl);
            break;
        case 0:
            outputStream->writeOutput("No complaints" + OutputStream::endl);
            break;
    }
    return error;
}

void Network::check(){    
    //check last octet
    if(*(range->getIp()+3) == 0 || *(range->getIp()+7) == 0)
        error = -1;
    
    //check if last address is higher than first address. First compare first octet
    if(*(range->getIp()) > *(range->getIp()+4))
        error = -2;
    else if(*(range->getIp()) == *(range->getIp()+4)){
        if(*(range->getIp()+1) > *(range->getIp()+5))
            error = -2;
        else if (*(range->getIp()+1) == *(range->getIp()+5)){
            if(*(range->getIp()+2) > *(range->getIp()+6))
                error = -2;
            else if (*(range->getIp()+2) == *(range->getIp()+6)){
                if(*(range->getIp()+3) > *(range->getIp()+7))
                    error = -2;
            }
        }
    }
    
    //check if some octet has a value > 255
    for(int i = 0; i < 8; ++i){
        if(*(range->getIp()+i) > 255)
            error = -3;
    }
 }

void Network::reserveList(size_t n){
    pingResults.reserve(n);
}

void Network::pingWorker(void *data, void *list){
    std::mutex m;
    OutputStream *stream = new OutputStream();
    outputStream->writeOutput("In ping worker" + OutputStream::endl);
    ((IPRange*)data)->generateList();
    ((std::vector<Ping>*)list)->reserve(((IPRange*)data)->getSize());
    //int i = 0;
    if(((IPRange*)data)->getDone()){
        for(std::vector<IPAddress>::iterator it = ((IPRange*)data)->getFirst(); it < ((IPRange*)data)->getEnd(); ++it){
            //cout << "Run: " << i << endl;
            //cout << "Length: " << ((IPRange*)data)->getSize() << endl;
            //++i;
            //cout << "IP: " << (*it).ipToString() << endl;
            ping((*it).ipToString());
        }
    }
    delete stream;
}

int Network::pingAll(){
    outputStream->writeOutput("Ping initialized" + OutputStream::endl);
    pingResults.clear();
    thPing = new std::thread(&Network::pingWorker, this, (void *)range, (void *)&pingResults);
    std::ostringstream buffer;
    OutputStream stream;
    stream.writeOutput(buffer.str());
    thPing->detach();
    delete thPing;
    return 0;
}

int Network::ping(std::string ip){
    OutputStream stream;
    cout << "ping initialized" << endl;
    cout << ip << endl;
    FILE *tstream;
    std::string command = "ping -c " + to_string(trials) + " -w " + to_string(time) + " " + ip;
    cout << "generated command: " << command << endl;
    tstream = popen(command.c_str(), "r");
    int temp = 0;
    std::vector<std::string> message;
    while (!feof(tstream)) 
    { 
        char buf[ 1024 ] = {0}; 

        if ( fgets(buf, sizeof(buf), tstream) > 0 ) 
        { 
            cout << "Line " << temp << " " << std::string(buf);
            message.push_back(std::string(buf));
            ++ temp;
        } 
    } 
    Ping *ping = new Ping(message, &stream);
    pingResults.push_back(*ping);
    delete ping;
    pclose( tstream ); 
}

/*int Network::ping(){
    outputStream->writeOutput("ping initialized" + OutputStream::endl);
    ostringstream buffer;
    FILE *tstream;
    std::string command = "ping -c " + to_string(trials) + " -w " + to_string(time) + " " + ipToString(0);
    buffer << "generated command: " << command << endl;
    outputStream->writeOutput(buffer.str());
    tstream = popen(command.c_str(), "r");
    int temp = 0;
    std::vector<std::string> message;
    while (!feof(tstream)) 
    { 
        char buf[ 1024 ] = {0}; 

        if ( fgets(buf, sizeof(buf), tstream) > 0 ) 
        { 
            buffer << "Line " << temp << " " << std::string(buf);
            outputStream->writeOutput(buffer.str());
            message.push_back(std::string(buf));
            ++ temp;
        } 
    } 
    Ping *ping = new Ping(message, outputStream);
    cout << "before push results" << endl;
    pingResults.push_back(*ping);
    cout << "after" << endl;
    delete ping;
    cout << "after delete" << endl;
    pclose( tstream ); 
    cout << "after close" << endl;
}*/

int Network::ping(){
    std::cout << "ping initialized" << endl;
    FILE *tstream;
    std::string command = "ping -c " + to_string(trials) + " -w " + to_string(time) + " " + ipToString(0);
    cout << "generated command: " << command << endl;
    tstream = popen(command.c_str(), "r");
    int temp = 0;
    std::vector<std::string> message;
    while (!feof(tstream)) 
    { 
        char buf[ 1024 ] = {0}; 

        if ( fgets(buf, sizeof(buf), tstream) > 0 ) 
        { 
            cout << "Line " << temp << " " << std::string(buf);
            message.push_back(std::string(buf));
            ++ temp;
        } 
    } 
    Ping *ping = new Ping(message);
    pingResults.push_back(*ping);
    delete ping;
    pclose( tstream ); 
}
    
void Network::printPing(){
   for(std::vector<Ping>::iterator it = pingResults.begin(); it != pingResults.end(); ++it) {
       it->printPing();
   }
}

void Network::pingShortRes(){
    if(pingResults.empty()){
        return;
        cout << "list empty" << endl;
    }
    else{
        for(std::vector<Ping>::iterator it = pingResults.begin(); it < pingResults.end(); ++it) {
            (*it).printShort();
        }
    }
}

void Network::threadKill(){
    try{
        if(threadActive()){
            ostringstream buffer;
            range->errorSignal();
            range->reset();
            delete thPing;
            thPing = NULL;
        }
    }
    catch(...){
        outputStream->writeOutput("Thread not deletable" + OutputStream::endl);
    }
}

void Network::threadActiveWorker(void *data, void *ptr){
    if((std::thread *)ptr != NULL)
        *((bool *)data) = true;
    else 
        *((bool *)data) = false;
}

bool Network::threadActive(){
    bool temp;
    org = new std::thread(&Network::threadActiveWorker, this, (void *)&temp, (void *)thPing);
    org->join();
    delete org;
    return temp;
}

std::string Network::firstIP_toString(){
    return ipToString(0);
}
std::string Network::lastIP_toString(){
    return ipToString(1);
}

