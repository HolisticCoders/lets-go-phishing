#include "raylib.h"

// forward declaration to tell the compiler that the class Tweet exists;
class Tweet;

class GUI_Tweet {
    public:
        GUI_Tweet(){}
        /* GUI_Tweet(Tweet* tweet, const int& x, const int& y, const int& tweetCount) : */
        /*     m_tweet{tweet}, */
        /*     m_x{x}, */
        /*     m_y{y}, */
        /*     m_height{(550 - tweetCount * (tweetCount + 1))/tweetCount} {} */

        void update(){
            DrawRectangle(m_x, m_y, m_width, m_height, m_color);
        }

        int height() {
            return m_height;
        }
        void setX(int x){
            m_x = x;
        }
        void setY(int y){
            m_y = y;
        }
        void setWidth(int width){
            m_width = width;
        }
        void setHeight(int height){
            m_height = height;
        }
        /* void setTweet(Tweet* tweet){ */
        /*     m_tweet = tweet; */
        /* } */

    private:
        int m_x;
        int m_y;
        int m_width = 310;
        int m_height = (550 - 10 * (5 + 1))/5; 
        Color m_color = GRAY;
        /* Tweet* m_tweet = nullptr; */
};
