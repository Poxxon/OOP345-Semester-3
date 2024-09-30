//==============================================
// Name:           Pouya Rad
// Student Number: 164382228
// Email:          prad@myseneca.ca
// Section:        NDD
//==============================================

#ifndef SENECA_DICTIONARY_H
#define SENECA_DICTIONARY_H

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "logger.h"

namespace seneca {

    enum class PartOfSpeech {
        Unknown,
        Noun,
        Pronoun,
        Adjective,
        Adverb,
        Verb,
        Preposition,
        Conjunction,
        Interjection
    };

    struct Word {
        std::string m_word;
        std::string m_definition;
        PartOfSpeech m_pos = PartOfSpeech::Unknown;
    };

    class Dictionary {
    private:
        Word* m_words = nullptr;       // Dynamically allocated array of words
        size_t m_size = 0;             // Number of words in the dictionary
        size_t m_capacity = 0;         // Capacity of the array

        void resize();                 // Helper to resize the array
        PartOfSpeech parsePartOfSpeech(const std::string& pos) const;

    public:
        Dictionary();                  // Default constructor
        Dictionary(const char* filename);  // Constructor that loads from file
        ~Dictionary();                 // Destructor

        // Implement copy constructor and copy assignment
        Dictionary(const Dictionary& other);                    // Copy constructor
        Dictionary& operator=(const Dictionary& other);         // Copy assignment operator

        Dictionary(Dictionary&& other) noexcept;                    // Move constructor
        Dictionary& operator=(Dictionary&& other) noexcept;         // Move assignment

        void searchWord(const char* word) const;           // Search for a word and print definitions
    };

}

#endif // SENECA_DICTIONARY_H
