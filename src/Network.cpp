/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IPAddress.cpp
 * Author: Florian Leuze
 * E-Mail: FlorianLeuze@aol.com
 * Universität Stuttgart
 *
 * Created on 8. Februar 2019, 18:44
 */

#include "../header/Network.h"

using namespace std;

Network::Network(std::string first, std::string last) {
    error = 0;
    range = new IPRange();
    for(int j = 0; j < 8; ++j){
        *(range->getIp()+j) = 0;
    }
    std::cout << "initialized decryption of ip addresses" << std::endl;
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
        cout << "decryption done. Seems all went fine" << endl;
    else
        cout << "something seems off. You might want to check your address" << endl;
}

Network::Network(const Network& orig) {
}

Network::~Network() {
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
        case -2:
            cout << "First address is higher than last address. That doesn't make sense." << endl;
            break;
        case -1:
            cout << "Last octet seems to be zero in either first or last address. Are you sure you want that=" << endl;
            break;
        case 0:
            cout << "No complaints" << endl;
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
 }

int Network::pingAll(){
    range->generateList();
}

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
   //for(std::vector<std::string>::iterator it = fullPingResults.begin(); it != fullPingResults.end(); ++it) {
    //std::cout << *it << std::endl;
   //}
}

std::string Network::firstIP_toString(){
    return ipToString(0);
}
std::string Network::lastIP_toString(){
    return ipToString(1);
}