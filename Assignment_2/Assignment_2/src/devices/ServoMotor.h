#ifndef __MOTOR__
#define __MOTOR__

class ServoMotor
{
private:
    int pin;
    unsigned angle : 8;
public:
    ServoMotor(/* args */);
    ~ServoMotor();
};

ServoMotor::ServoMotor(/* args */)
{
}

ServoMotor::~ServoMotor()
{
}


#endif