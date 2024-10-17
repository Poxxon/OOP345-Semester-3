#include "HomeStereo.h"

// Constructor
HomeStereo::HomeStereo(int n, Switch* initSwitches) : numSwitches(n)
{
    switches = new Switch[numSwitches];
    for (int i = 0; i < numSwitches; ++i)
    {
        switches[i] = initSwitches[i]; // Copying each switch
    }
}

// Copy Constructor
HomeStereo::HomeStereo(const HomeStereo& other)
{
    copyFrom(other);
}

// Move Constructor
HomeStereo::HomeStereo(HomeStereo&& other) noexcept : switches(other.switches), numSwitches(other.numSwitches)
{
    other.switches = nullptr;
    other.numSwitches = 0;
}

// Copy Assignment Operator
HomeStereo& HomeStereo::operator=(const HomeStereo& other)
{
    if (this != &other)
    {
        clear();
        copyFrom(other);
    }
    return *this;
}

// Move Assignment Operator
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

// Destructor
HomeStereo::~HomeStereo()
{
    clear();
}

// Utility function to clear memory
void HomeStereo::clear()
{
    delete[] switches;
    switches = nullptr;
    numSwitches = 0;
}

// Utility function to copy from another object
void HomeStereo::copyFrom(const HomeStereo& other)
{
    numSwitches = other.numSwitches;
    switches = new Switch[numSwitches];
    for (int i = 0; i < numSwitches; ++i)
    {
        switches[i] = other.switches[i];
    }
}

// displayOutputState function
std::ostream& HomeStereo::displayOutputState(std::ostream& os) const
{
    for (int i = 0; i < numSwitches; ++i)
    {
        os << "Channel Name: " << switches[i].name << " - State [";

        if (isSwitchOn(switches[i]))
        {
            os << "on";
        }
        else
        {
            os << "off";
        }
        os << "]" << std::endl;
    }
    return os;
}

// Utility function to check if a switch is "on"
bool HomeStereo::isSwitchOn(const Switch& sw) const
{
    switch (sw.sType)
    {
        case StateType::boolean:
            return sw.sState.stateAsBool;
        case StateType::character:
            return sw.sState.stateAsChar == 'O';
        case StateType::number:
            return sw.sState.stateAsNum == 1;
        default:
            return false;
    }
}
