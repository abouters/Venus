#include "Venus.h"

Venus::Venus(CanControl* _canN ,int dip){
    memberinit();
    _can = _canN;
    this->dip = dip;
}

void Venus::memberinit(){
    for(int i=0; i<8; i++){
        is_solenoid[i] = false;
    }
}

void Venus::init(){
	_can->init(CAN_BITRATE);
}

void Venus::setStatus(int pos, bool solenoid){
    is_solenoid[pos-1] = solenoid;
}

void Venus::send(){
    static CAN_message_t msg;
    msg.id = BASE_ADDR + dip;
    msg.len = 8;

    for(int i=0; i<8; i++){
        msg.buf[i] = 0;
    }

    msg.buf[0] = (is_solenoid[7]<<7) + (is_solenoid[6]<<6) + (is_solenoid[5]<<5) + (is_solenoid[4]<<4) + 
                 (is_solenoid[3]<<3) + (is_solenoid[2]<<2) + (is_solenoid[1]<<1) + (is_solenoid[0]);
    msg.buf[1] = (is_solenoid[11]<<3) + (is_solenoid[10]<<2) + (is_solenoid[9]<<1) + is_solenoid[8];

    _can->CANMsgWrite(msg);
}