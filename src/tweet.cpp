#include <string>

using namespace std;


// This is a forward declaration
// of the Victim class.
// This allows us to have a pointer
// to a Victim in the Tweet class.
class Victim;


class Tweet {
    public:
        Tweet() {
            
        }
    private:
        Victim* m_author;  // This is made possible by the forward declaration.
        string m_title;
        string m_body;
};

