/*
This is just to test myself on what i understood from HomeStereo.h - .cpp by writing it my own here
*/


#ifdef MYSTEREO_H
#define MYSTEREO_H

#include <iostream>
#include <cstring>


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


// HomeStereo class

class HomeStereo {
    private:
    Switch* switches; //dynamically allocated array to store the switch objects
    int numSwitches; //number of switches in an array

    public:

    //Rule of 5:
    //Constructor - initialize 
    //Copy constructor - deep copy the current object to other object
    //Copy Assignment operator - overloaded function to copy from one object to another
    //Move constructor - to move the current object to another and empty the original object
    //Move Assignment operator - overloaded function to move everything from one object to another and nullifying the original

    //constructor
    HomeStereo(int n, Switch* initSwitches);

    //copy constructor
    HomeStereo(const HomeStereo& other);

    //copy assignment operator
    HomeStereo& operator=(const HomeStereo& other);

    //move constructor
    HomeStereo(HomeStereo&& other) noexcept; //for move we use &&

    //move assignment operator
    HomeStereo& operator=(HomeStereo&& other) noexcept; //make sure to use noexcept on move

    //destructor
    ~HomeStereo();

    //display function
    std::ostream& displayOutputState(std::ostream os = std::cout) const;

    //utility function to see if the switch is on
    bool isSwitchOn(const Switch& sw) const;

    private:
    //helper function to clear up the memory
    void clear()

    //helper function to copy switch array from another object
    void copyFrom(const HomeStereo& other);

};

#endif