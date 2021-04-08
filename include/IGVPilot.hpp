#include "simple-zigbee.hpp"

#include <iostream>
#include <fstream>
#include <thread>

namespace igv{

typedef enum: uint8_t { 

    MASTER = 0xaa, 
    CLIENT = 0xff 

} CommandMode;

enum CommandType: bool{ GET = false, SET = true};

enum GettableParameters: uint8_t{

    SPEED,
    DIRECTION,
    LATITUDE,
    LONGITUDE,
    LCAMIMAGE,
    OCAMIMAGE,
    LIDARMAP

};

enum SettableParameters: uint8_t{

    SPEED, 
    DIRECTION

};

union CommandBody{
    
    GettableParameters paramtoget,
    struct { SettableParameters paramtoset, uint16_t sizeofparam };

};

struct Command{

    CommandType ct;
    CommandBody cb;

};


struct Packet{


}

/**
 * @class IGVPilot 
 * @brief Pilot Class
 */
class IGVPilot{

public:
    
    void Connect();
    bool isConnected();

    void ReceiveData(RecvData& data);
    
    void Init(CommandMode cm);

    void Send(Command command);

private:


};
}