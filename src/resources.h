#include <fstream>
#include <string>

#include <json.hpp>


using namespace std;
using namespace nlohmann;


// Get a specific resource file content from the
// "resources" folder.
json getResource(const char* path) {
    string fullPath = "../resources/";
    fullPath.append(path);
    ifstream input(fullPath);
    json data;
    input >> data;
    return data;
}

