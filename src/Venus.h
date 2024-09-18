#ifndef VENUS_H_
#define VENUS_H_

#define BASE_ADDR 0x400
#define CAN_BITRATE 1000000

#include <CAN.h>
#include <FlexCAN_T4.h>

class Venus : public CanControl{
    public:
        Venus(CanControl* _can, int dip); //基板(venus)のポテンショメーターの数字をaddrに入力する

        void init();    //bitrateを指定する基板側(venus)で1e6[Hz]に指定している
        void memberinit();
        void setStatus(int pos, bool solenoid);    //基板(venus)右側から0,1,2,3,4,5の順番
        void send();    //データを基板(venus)に送信する
        
    private:
        CanControl* _can;
        bool is_solenoid[12];
        uint8_t dip;
};

#endif