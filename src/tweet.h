#ifndef TWEET_H
#define TWEET_H

#include <string>
#include "victim.h"

using namespace std;

class Tweet {
    public:

        // Constructors
        Tweet() : m_author{nullptr}, m_content{""} {}

        Tweet(Victim* author, const string content)
            : m_author{author}, m_content{content}
        {}

        // Accessors
        Victim* author() {
            return m_author;
        }
        string content() {
            return m_content;
        }

        // Mutators
        void setAuthor(Victim* author) {
            m_author = author;
        }
        void setContent(const string content) {
            m_content = content;
        }

    private:
        Victim* m_author;  // This is made possible by the forward declaration.
        string m_content;
};
#endif
