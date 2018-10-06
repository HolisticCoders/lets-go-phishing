#include <string>
#include "enums.cpp"

using namespace std;


class Mail {
    public:

        // Constructors
        Mail() {
            m_title = "";
            m_content = "";
            m_category = Phishing;
        }

        Mail(const string& title, const string& content, const SpamCategories& category) {
            m_title = title;
            m_content = content;
            m_category = category;
        }

        // Accessors
        string title() {
            return m_title;
        }
        string content() {
            return m_content;
        }
        SpamCategories category() {
            return m_category;
        }

        // Mutators
        void setTitle(const string& title) {
            m_title = title;
        }
        void setContent(const string& content) {
            m_content = content;
        }
        void setCategory(const SpamCategories& category) {
            m_category = category;
        }

    private:

        string m_title;
        string m_content;
        SpamCategories m_category;
};
