// sample2.cpp

// header.h
#include <iostream>
using namespace std;

enum class StateType
{
	boolean,
	character,
	number
};

typedef struct
{
  char name[20];
	StateType sType;	
	union
	{
		bool stateAsBool;
		char stateAsChar;
		int stateAsNum;
	} sState;
} Switch;

class HomeStereo {
	
	Switch* m_arr{};
	size_t num{};

public:

    // Constructor
	HomeStereo(Switch* s, size_t n) {
		num = n;
		m_arr = new Switch[num];
		for (auto i = 0u; i < n; ++i) {
			m_arr[i] = s[i];
		}
	}

  /*
	Channel Name: xxxxxx - State [on/off]< endl >
	*/

	ostream& display(ostream& os = std::cout) {
		for (auto i = 0u; i < num; ++i) {
			cout << "Channel Name: " << m_arr[i].name << " - State [";
			switch (m_arr[i].sType) {
			case StateType::boolean:
				if (m_arr[i].sState.stateAsBool == true)
					cout << "ON";
				break;
			case StateType::number:
				if (m_arr[i].sState.stateAsNum == 1)
					cout << "ON";
				break;
			case StateType::character:
				if (m_arr[i].sState.stateAsChar == 'O')
					cout << "ON";
				break;
			default:
				cout << "OFF";
			}
			cout << "]" << endl;
		}
	}

    // Destructor
	~HomeStereo() {
		delete[] m_arr;
	}

    // Copy constructor
	HomeStereo(const HomeStereo& src) {
		*this = src;
	}

    // Copy assignment operator
	HomeStereo& operator=(const HomeStereo& src) {
		if (this != &src) {
			delete[] m_arr;
			m_arr = nullptr;
			num = src.num;
			if (src.m_arr) {
				m_arr = new Switch[num];
				for (auto i = 0u; i < num; ++i)
					m_arr[i] = src.m_arr[i];
			}
		}
		return *this;
	}

    // Move constructor
	HomeStereo(HomeStereo&& src) {
		*this = std::move(src);
	}

    // Move assignment operator
	HomeStereo& operator=(HomeStereo&& src) {
		if (this != &src) {
			delete[] m_arr;
			m_arr = nullptr;
			num = src.num;
			m_arr = src.m_arr;
			src.m_arr = nullptr;
			src.num = 0;
		}
		return *this;
	}
};


int main() {

	Switch s1{"S1" , StateType::boolean, false  };
	Switch s2{ .name = {"S2"} , .sType = {StateType::number}, .sState = {.stateAsNum = {5}} };

	cout << s1.sState.stateAsBool << endl;
	if (s1.sState.stateAsBool == false)
        ostream& display();
		cout << "Here1" << endl;
	cout << s2.sState.stateAsNum << endl;
	if (s2.sState.stateAsNum == 5)
		cout << "Here2" << endl;
}
