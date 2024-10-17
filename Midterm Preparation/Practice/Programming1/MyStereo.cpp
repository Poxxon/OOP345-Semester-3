/*
This is just to test myself on what i understood from HomeStereo.h - .cpp by writing it my own here
*/


#include "MyStereo.h"

//constructor - initialize
HomeStereo::HomeStereo(int n, Switch* initSwitches) : numSwitches(n)
{
    switches = new Switch[numSwitches];
    for (int i = 0; i < numSwitches; ++i) {
        switches[i] = initSwitches[i];
    }
}

//copy constructor 
HomeStereo::HomeStereo(const HomeStereo& other) {
    copyFrom(other);
}

//move constructor
HomeStereo::HomeStereo(HomeStereo&& other) noexcept : switches(other.switches), numSwitches(other.numSwitches) 
{
    other.switches = nullptr;
    other.numSwitches = 0;
}

//copy assignment operator
HomeStereo& HomeStereo::operator=(const HomeStereo& other)
{
    if (this != &other) 
    {
        clear();
        copyFrom(other);
    }
    return *this;
}

//move assignment operator
HomeStereo& HomeStereo::operator=(HomeStereo&& other) noexcept 
{
    if (this != &other)
    {
        clear();
        switches = other.switches;
        numSwitches = other.numSwitches;
        other.switches = nullptr;
        other.numSwitches = 0;
    }
    return *this;
}

//destructor
HomeStereo::~HomeStereo() {
    clear();
}

//utility function to clear memory
void HomeStereo::clear() 
{
    delete[] switches;
    switches = nullptr;
    numSwitches = 0;
}

//utility function to copy from another object
void HomeStereo::copyFrom(const HomeStereo& other)
{
    numSwitches = other.numSwitches;
    switches = new Switch[numSwitches];
    for (int i = 0; i < numSwitches; ++i)
    {
        switches[i] = other.switches[i];
    }
}


//display function
std::ostream& HomeStereo::displayOutputState(std::stream& os) const
{
    for (int i = 0; i < numSwitches; ++i)
    {
        os << "Channel name: " << switches[i].name << " - State [";

        if (isSwitchOn(switches[i]))
        {
            os << "on";
        } else {
            os << "off";
        }
        os << "]" std::endl;
    }
    return os;
}

//utility function to check if a switch is "on"
bool HomeStereo::isSwitchOn(const Switch& sw) const 
{
    switch (sw.sType)
    {
        case StateType::boolean:
            return sw.sState.stateAsBool;
        case StateType::character:
            return sw.sSate.stateAsChar == "O";
        case StateType::number:
            return sw.sState.stateAsNum == 1;
        default:
            return false;
    }
}