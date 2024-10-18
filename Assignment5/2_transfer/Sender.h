//
// Created by delirio on 2022/4/30.
//

#ifndef TRANSFER_SENDER_H
#define TRANSFER_SENDER_H
#include <string>
using namespace std;

class Sender {
// set members

public:
// design the constructor here

// some methods to be implemented
    string getOriginData();
    string bitStuffing (string data);
    string framing();
private:
    string originData;
    int MTU;
};

#endif //TRANSFER_SENDER_H
