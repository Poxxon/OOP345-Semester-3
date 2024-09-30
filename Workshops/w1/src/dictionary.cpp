//==============================================
// Name:           Pouya Rad
// Student Number: 164382228
// Email:          prad@myseneca.ca
// Section:        NDD
//==============================================

#include "dictionary.h"
#include "settings.h"

namespace seneca {

    Dictionary::Dictionary() : m_words(nullptr), m_size(0), m_capacity(0) {}

    Dictionary::Dictionary(const char* filename) : m_words(nullptr), m_size(0), m_capacity(0) {
        std::ifstream file(filename);
        if (!file) {
            std::cerr << "Error: Cannot open file " << filename << std::endl;
            return;
        }

        std::string line;
        while (getline(file, line)) {
            if (m_size == m_capacity) {
                resize();  // Ensure we have enough capacity
            }

            std::istringstream iss(line);
            std::string word, pos, definition;

            if (getline(iss, word, ',') && getline(iss, pos, ',') && getline(iss, definition)) {
                m_words[m_size].m_word = word;
                m_words[m_size].m_definition = definition;
                m_words[m_size].m_pos = parsePartOfSpeech(pos);  // Parse part of speech
                ++m_size;
            }
        }

        file.close();
    }

    Dictionary::~Dictionary() {
        delete[] m_words;  // Free dynamically allocated array
    }

    // Copy constructor (deep copy)
    Dictionary::Dictionary(const Dictionary& other) : m_size(other.m_size), m_capacity(other.m_capacity) {
        m_words = new Word[m_capacity];
        for (size_t i = 0; i < m_size; ++i) {
            m_words[i] = other.m_words[i];  // Deep copy each word
        }
    }

    // Copy assignment operator (deep copy)
    Dictionary& Dictionary::operator=(const Dictionary& other) {
        if (this != &other) {
            delete[] m_words;  // Free existing resources

            m_size = other.m_size;
            m_capacity = other.m_capacity;
            m_words = new Word[m_capacity];
            
            for (size_t i = 0; i < m_size; ++i) {
                m_words[i] = other.m_words[i];  // Deep copy each word
            }
        }
        return *this;
    }

    // Move constructor
    Dictionary::Dictionary(Dictionary&& other) noexcept 
        : m_words(other.m_words), m_size(other.m_size), m_capacity(other.m_capacity) {
        other.m_words = nullptr;
        other.m_size = 0;
        other.m_capacity = 0;
    }

    // Move assignment operator
    Dictionary& Dictionary::operator=(Dictionary&& other) noexcept {
        if (this != &other) {
            delete[] m_words;  // Free current resources

            m_words = other.m_words;
            m_size = other.m_size;
            m_capacity = other.m_capacity;

            other.m_words = nullptr;
            other.m_size = 0;
            other.m_capacity = 0;
        }
        return *this;
    }

    void Dictionary::resize() {
        size_t newCapacity = m_capacity == 0 ? 2 : m_capacity * 2;
        Word* newWords = new Word[newCapacity];  // Allocate new larger array

        // Copy existing words into the new array
        for (size_t i = 0; i < m_size; ++i) {
            newWords[i] = m_words[i];
        }

        delete[] m_words;  // Free the old array
        m_words = newWords;  // Update the pointer to the new array
        m_capacity = newCapacity;  // Update the capacity
    }

    PartOfSpeech Dictionary::parsePartOfSpeech(const std::string& pos) const {
        if (pos == "n." || pos == "n. pl.") return PartOfSpeech::Noun;
        if (pos == "pron.") return PartOfSpeech::Pronoun;
        if (pos == "a.") return PartOfSpeech::Adjective;
        if (pos == "adv.") return PartOfSpeech::Adverb;
        if (pos == "v." || pos == "v. i." || pos == "v. t." || pos == "v. t. & i.") return PartOfSpeech::Verb;
        if (pos == "prep.") return PartOfSpeech::Preposition;
        if (pos == "conj.") return PartOfSpeech::Conjunction;
        if (pos == "interj.") return PartOfSpeech::Interjection;
        return PartOfSpeech::Unknown;
    }

    std::string partOfSpeechToString(PartOfSpeech pos) {
        switch (pos) {
            case PartOfSpeech::Noun: return "noun";
            case PartOfSpeech::Pronoun: return "pronoun";
            case PartOfSpeech::Adjective: return "adjective";
            case PartOfSpeech::Adverb: return "adverb";
            case PartOfSpeech::Verb: return "verb";
            case PartOfSpeech::Preposition: return "preposition";
            case PartOfSpeech::Conjunction: return "conjunction";
            case PartOfSpeech::Interjection: return "interjection";
            default: return "unknown";
        }
    }

    void Dictionary::searchWord(const char* word) const {
    bool found = false;
    size_t firstWordLength = 0;  // Used for indentation of subsequent definitions

    for (size_t i = 0; i < m_size; ++i) {
        if (m_words[i].m_word == word) {
            found = true;
            if (firstWordLength == 0) {
                // First definition, print the word
                std::cout << m_words[i].m_word;
                firstWordLength = m_words[i].m_word.length();  // Store the length for indentation
            } else {
                // Subsequent definitions, indent based on word length
                std::cout << std::string(firstWordLength, ' ') << "";
            }
            
            std::cout << " -";

            // Print part of speech if verbose is enabled
            if (g_settings.m_verbose && m_words[i].m_pos != PartOfSpeech::Unknown) {
                std::cout << " (" << partOfSpeechToString(m_words[i].m_pos) << ")";
            }

            // Print the definition
            std::cout << " " << m_words[i].m_definition << std::endl;

            if (!g_settings.m_show_all) {
                return;  // Exit if we're only showing the first definition
            }
        }
    }

    if (!found) {
        std::cout << "Word '" << word << "' was not found in the dictionary." << std::endl;
    }
}

    
}
