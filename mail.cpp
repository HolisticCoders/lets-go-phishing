#include <string>
#include "enums.cpp"

using namespace std;


class Mail {
    public:
        Mail(const string& title, const string& content, const SpamCategories& category) {
            m_title = title;
            m_content = content;
            m_category = category;
        }
    private:
        string m_title;
        string m_content;
        SpamCategories m_category;
};
