#include <string>

using namespace std;


// This is a forward declaration
// of the Victim class.
// This allows us to have a pointer
// to a Victim in the Tweet class.
class Victim;


class Tweet {
    public:

        // Constructors
        Tweet() {
            m_author = nullptr;
            m_title = "Tweet";
            m_content = "";
        }

        Tweet(Victim* author, const string& title, const string& content)
            : m_author{author}, m_title{title}, m_content{content}
        {}

        // Accessors
        Victim* author() {
            return m_author;
        }
        string title() {
            return m_title;
        }
        string content() {
            return m_content;
        }

        // Mutators
        void setAuthor(Victim* author) {
            m_author = author;
        }
        void setTitle(const string& title) {
            m_title = title;
        }
        void setContent(const string& content) {
            m_content = content;
        }

    private:
        Victim* m_author;  // This is made possible by the forward declaration.
        string m_title;
        string m_content;
};

