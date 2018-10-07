#include <string>

#include <json.hpp>


using namespace std;
using namespace nlohmann;


class Resources {
    public:
        Resources() : m_root{""} {};
        Resources(const string root) : m_root{root} {};
        string root() { return m_root; }
        void setRoot(const string root) { m_root = root; }
        json getResource(const char* path);
    private:
        string m_root;
};
