#include <iostream>
#include <string>
#include <fstream>

#include "json.hpp"

#include "resources.h"

using namespace std;
using namespace nlohmann;

// Get a specific resource file content from the
// "resources" folder.
json Resources::getResource(const char* path) {
    string fullPath = m_root;
    fullPath.append(path);
    cout << "Resource path: " << fullPath << endl;
    json data;
    ifstream input(fullPath);
    if (!input.good()) {
        input.close();
        return data;
    }
    input >> data;
    input.close();
    return data;
}

