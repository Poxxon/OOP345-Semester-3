#ifndef HOMESTEREO_H
#define HOMESTEREO_H

#include <iostream>
#include <cstring>  // for strcpy and strcmp

// The Switch definition
enum class StateType
{
    boolean,
    character,
    number
};

typedef struct
{
    char name[20]; // name of channel
    StateType sType; // stores the state object
    union
    {
        bool stateAsBool;
        char stateAsChar;
        int stateAsNum;
    } sState;
} Switch;

class HomeStereo
{
private:
    Switch* switches;      // dynamically allocated array of Switch objects
    int numSwitches;       // number of switches in the array

public:
    // Constructor
    HomeStereo(int n, Switch* initSwitches);

    // Copy Constructor
    HomeStereo(const HomeStereo& other);

    // Move Constructor
    HomeStereo(HomeStereo&& other) noexcept;

    // Copy Assignment Operator
    HomeStereo& operator=(const HomeStereo& other);

    // Move Assignment Operator
    HomeStereo& operator=(HomeStereo&& other) noexcept;

    // Destructor
    ~HomeStereo();

    // displayOutputState function
    std::ostream& displayOutputState(std::ostream& os = std::cout) const;

    // Utility function to check if a switch is "on"
    bool isSwitchOn(const Switch& sw) const;

private:
    // Utility to clean up memory
    void clear();

    // Utility to copy Switch array from another object
    void copyFrom(const HomeStereo& other);
};

#endif
