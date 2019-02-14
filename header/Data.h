/**
 * @file Data.h
 * @author Florian Leuze (3308288) <st155013@stud.uni-stuttgart.de>
 * @date 11.02.2019
 * @brief Data Class header
 */

#ifndef DATA_H
#define DATA_H
#include "../header/Network.h"

/**
 *@brief Data storage. Propably not used in final release
 * Members are:
 * ip - Stores a Network-type object
 */
class Data {
public:
  //CONSTRUCTORS/DECONSTRUCTORS/************************************************************/
  /**
   * @brief Creates a empty Data type object
   */
    Data();
    Data(const Data& orig);
    virtual ~Data();
    //SETTERS/************************************************************/
    /**
    * @brief Set the x Value
    * @param std::string firstIP sets first ip in the range. Calls method from Network object
    * @param std::string lastIP sets last ip in the range. Calls method from Network object
    */
    void setIPRange(std::string firstIP, std::string lastIP);
    Network *ip; /**<Network object to store values*/
private:
};

#endif /* DATA_H */

