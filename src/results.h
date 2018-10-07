#ifndef RESULTS_H
#define RESULTS_H

#include <string>

using namespace std;


struct Results {
    int money;
    int wantedLevel;
    string message;
    Results(const int& money, const int& wantedLevel, const string& message) : money{money}, wantedLevel{wantedLevel}, message{message} {};
};


#endif
