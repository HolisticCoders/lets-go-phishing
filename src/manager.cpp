#include <algorithm> // shuffle
#include <iostream> // cout
#include <map> // map
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock

#include "json.hpp"

#include "mail.h"
#include "manager.h"
#include "resources.h"
#include "results.h"
#include "tweet.h"
#include "victim.h"
#include "ui/board.h"

using namespace std;
using namespace nlohmann;


Manager::Manager() {
    m_resources = new Resources("../resources/");
    m_categories = new string[m_resources->categories().size()];
    m_maritalStatus = new string[m_resources->maritalStatus().size()];
    m_professions = new string[m_resources->professions().size()];
    m_victims = new Victim[m_resources->victims().size()];

    // Get track of the victims name to associate them
    // to tweets.
    map<string, Victim*> victimNames;

    for (int i = 0; i < m_resources->professions().size(); i++) {
        m_professions[i] = m_resources->professions()[i];
    }
    for (int i = 0; i < m_resources->maritalStatus().size(); i++) {
        m_maritalStatus[i] = m_resources->maritalStatus()[i];
    }
    for (int i = 0; i < m_resources->categories().size(); i++) {
        m_categories[i] = m_resources->categories()[i];
    }
    for (int i = 0; i < m_resources->mails().size(); i++) {
        json data = m_resources->mails()[i];
        Mail* mail = new Mail(
            data["title"],
            data["content"],
            data["category"],
            data["risk"],
            data["reward"]
        );
        m_mails.push_back(mail);
    }
    for (int i = 0; i < m_resources->victims().size(); i++) {
        json data = m_resources->victims()[i];
        m_victims[i].setName(data["name"]);
        m_victims[i].setBio(data["bio"]);
        m_victims[i].setProfession(data["profession"]);
        m_victims[i].setMaritalStatus(data["maritalStatus"]);
        m_victims[i].setChildren(data["children"]);
        m_victims[i].setMoney(data["money"]);
        victimNames[data["name"]] = &m_victims[i];
    }
    for (int i = 0; i < m_resources->tweets().size(); i++) {
        json data = m_resources->tweets()[i];
        Tweet* tweet = new Tweet(
            victimNames[data["author"]],
            data["content"]
        );
        m_tweets.push_back(tweet);
    }
}

Manager::~Manager() {
    delete m_resources;
    delete [] m_categories;
    delete [] m_maritalStatus;
    delete [] m_professions;
    delete [] m_victims;

    for (Mail* mail: m_mails) {
        delete mail;
    }
    for (Tweet* tweet: m_tweets) {
        delete tweet;
    }
}


int Manager::categoryCount() {
    return m_resources->categories().size();
}
int Manager::mailCount() {
    return m_resources->mails().size();
}
int Manager::maritalStatusCount() {
    return m_resources->maritalStatus().size();
}
int Manager::professionsCount() {
    return m_resources->professions().size();
}
int Manager::tweetCount() {
    return m_resources->tweets().size();
}
int Manager::victimCount() {
    return m_resources->victims().size();
}

void Manager::endTurn() {
    trashMail(m_mail);
    drawTweets();
    Results* results = spamResults(m_mail, m_victim);
    m_player->addMoney(results->money);
    m_player->addWantedLevel(results->wantedLevel);
    m_board->showResults(results);
    m_mail = nullptr;
}

void Manager::trashMail(Mail* mail) {
    auto it = find(m_mails.begin(), m_mails.end(), mail);
    int index = distance(m_mails.begin(), it);
    deque<Mail*> tmpMails;

    // Fill the front of the queue, then grab the fifth (index 4)
    // mail and put it at the trashed mail index.
    for (int i = 0; i < index; i++) {
        tmpMails.push_back(m_mails[i]);
    }
    tmpMails.push_back(m_mails[4]);

    // Now fill the remaining of the queue and push
    // the trashed mail back.
    for (int i = index + 1; i < m_mails.size(); i++) {
        if (i == 4) {
            i = 5;
        }
        tmpMails.push_back(m_mails[i]);
    }
    tmpMails.push_back(m_mails[index]);

    m_mails.swap(tmpMails);
}
void Manager::drawMails() {}
void Manager::drawTweets() {
    // Create a new deque to discard the five front tweets
    // into.
    deque<Tweet*> tmpTweets;
    for (int i = m_tweets.size() - 1; i >= m_tweets.size() - 5; i--) {
        tmpTweets.push_back(m_tweets[i]);
    }
    for (int i = 0; i < m_tweets.size() - 5; i++) {
        tmpTweets.push_front(m_tweets[i]);
    }
    m_tweets.swap(tmpTweets);
}
void Manager::shuffleMails() {
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(m_mails.begin(), m_mails.end(), default_random_engine(seed));
}
void Manager::shuffleTweets() {
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(m_tweets.begin(), m_tweets.end(), default_random_engine(seed));
}

Results* Manager::spamResults(Mail *mail, Victim *victim) {
    // So this part is purely opinion based.
    // It's was also done in a limited amount
    // of time, with a great deal of mental
    // fatigue, so some of the choices made
    // here might be very conventional or
    // totally whimsical.
    //
    // Basically we add a number of factors
    // based on the category of the mail and
    // the victim profile.
    //
    // When this is done, a little weighted
    // radomness yields the results.
    //
    // TODO: Add a tag system on victims, mails
    // and tweets to further customize the results.

    cout << "Victim: " << victim->name() << endl;
    cout << "Profession: " << victim->profession() << endl;
    cout << "Marital Status: " << victim->maritalStatus() << endl;
    cout << "Children: " << victim->children() << endl;
    cout << "Account Balance: " << victim->money() << endl;
    cout << "Mail Category: " << mail->category() << endl;

    float bias = 0;
    if (mail->category() == "Stocks") {
        // The more you have, the more you want.
        if (
            victim->profession() == "Trader"
            || victim->profession() == "Lobbyist"
            || victim->profession() == "SalesPerson"
        ) {
            bias += .5;
            cout << "Loving the stock money! (+.5)" << endl;
        }
        if (victim->money() > 10000) {
            bias += .3;
            cout << "Loving the stock money! (+.3)" << endl;
        }
        if (victim->money() > 1000000) {
            bias += .5;
            cout << "Loving the stock money! (+.5)" << endl;
        }
        if (victim->money() > 10000000) {
            bias += .8;
            cout << "Loving the stock money! (+.8)" << endl;
        }
    } else if (mail->category() == "Malware") {
        // Those guys surely know you don't have
        // to open these. Hopefully.
        if (
            victim->profession() == "Engineer"
            || victim->profession() == "SoftwareDeveloper"
            || victim->profession() == "SystemAdministrator"
        ) {
            bias -= .5;
            cout << "Getting away from malware... (-.5)" << endl;
        }
    } else if (mail->category() == "HealthCare") {
        // Who's not for health care ?
        // By the way, less rich people are
        // more subject to illness, so they
        // take the bait easier on those spams.
        bias += .1;
        cout << "Money for a sore throat. (+.1)" << endl;
        if (victim->children() > 0) {
            bias += .2;
            cout << "Money for a sore throat. (+.2)" << endl;
        }
        if (
            victim->profession() == "Veterinarian"
            || victim->profession() == "FireFighter"
        ) {
            bias += .2;
            cout << "Money for a sore throat. (+.2)" << endl;
        }
        if (victim->money() < 1000) {
            bias += .2;
            cout << "Money for a sore throat. (+.2)" << endl;
        }
    } else if (mail->category() == "Dating") {
        // Well... You know how it is.
        // Some might fell good alone.
        // Some might not.
        // So it's a little bias, you know,
        // sometimes it might be cool to hang out
        // with somebody else.
        if (
            victim->maritalStatus() == "Single"
            || victim->maritalStatus() == "Separated"
            || victim->maritalStatus() == "Divorced"
            || victim->maritalStatus() == "Widowed"
        ) {
            bias += .2;
            cout << "Looking for your soul mate. (+.2)" << endl;
        }
    } else if (mail->category() == "Jobs") {
        // Some jobs are really not that great.
        // Some don't even have a job.
        // So yeah, all in all it's always
        // the same kind of people falling in here.
        if (victim->money() < 1000) {
            bias += .2;
            cout << "Need a job! (+.2)" << endl;
        }
        if (
            victim->profession() == "Cashier"
            || victim->profession() == "GarbageCollector"
        ) {
            bias += .2;
            cout << "Need a job! (+.2)" << endl;
        }
    } else if (mail->category() == "Phishing") {
        // Everyone gets one of those sometime.
        // A little bit carefree and you're phished.
        bias += .1;
        cout << "Hooked on phishing. :D (+.1)" << endl;
        // But those guys are still prepared.
        // I hope.
        if (
            victim->profession() == "Engineer"
            || victim->profession() == "SoftwareDeveloper"
            || victim->profession() == "SystemAdministrator"
        ) {
            bias -= .5;
            cout << "This guy is not. D: (-.5)" << endl;
        }
    } else if (mail->category() == "Adult") {
        // Like sex toys, enhancers, etc...
        // Obviously it's a little bit more
        // difficult to buy and hide those from
        // the kids, so the victim might hesitate
        // a bit before guying.
        if (victim->children() > 0) {
            bias -= .1;
            cout << "Look away kids... :3 (-.1)" << endl;
        }
        // Still, as successful as dating sites.
        // Or more, this is like a fallback when
        // the "Dating" category fails to entertain. :D
        if (
            victim->maritalStatus() == "Single"
            || victim->maritalStatus() == "Separated"
            || victim->maritalStatus() == "Divorced"
            || victim->maritalStatus() == "Widowed"
        ) {
            bias += .2;
            cout << "Wanking is caring. (+.2)" << endl;
        }
    } else if (mail->category() == "Products") {
        // All goods fall in this category, from
        // groceries to spaceships (!).
        // Yep, we even sell spaceships, how cool is that ?
        // So in general, the more money you have,
        // the more you can buy.
        // Also, if you have a family to provide for and
        // this leads to good deals, you'll more enclined
        // to bite.
        if (victim->children() > 1) {
            bias += .2;
            cout << "Yeah I need those, this is cheaper than Primark. (+.2)" << endl;
        }
        if (victim->maritalStatus() == "Maried") {
            bias += .2;
            cout << "Honey look how cheap it is on this website! (+.2)" << endl;
        }
        if (victim->money() > 5000) {
            bias += .2;
            cout << "I'm buying one. (+.2)" << endl;
        }
        if (victim->money() > 10000) {
            bias += .3;
            cout << "I'm buying two. (+.3)" << endl;
        }
        if (victim->money() > 1000000) {
            bias += .5;
            cout << "I'm buying everything. (+.5)" << endl;
        }
        if (victim->money() > 10000000) {
            bias += .8;
            cout << "I'm buying the compagny. (+.8)" << endl;
        }
        // And the usual suspects.
        if (
            victim->profession() == "Trader"
            || victim->profession() == "Lobbyist"
            || victim->profession() == "SalesPerson"
        ) {
            bias += .2;
            cout << "Well let's add that to our collection. (+.2)" << endl;
        }
    } else if (mail->category() == "SocialCare"){
        // Some very welcome help, what's not to
        // like here ?
        // Everyone starts with a little positive
        // bias, some get a very negative one
        // afterward to balance it.
        bias += .2;
        cout << "Thanks for the money. I love socialism. (+.2)" << endl;
        if (victim->money() < 1000) {
            bias += .1;
            cout << "Actually, I need it really. (+.1)" << endl;
        }
        if (victim->money() > 10000) {
            bias -= .3;
            cout << "Just kidding, they're trying to make me poor. (-.3)" << endl;
        }
        if (victim->money() > 100000) {
            bias -= .4;
            cout << "Just kidding, they're trying to make me poor. OMG will the??? (-.4)" << endl;
        }
        if (
            victim->profession() == "Trader"
            || victim->profession() == "Lobbyist"
            || victim->profession() == "SalesPerson"
        ) {
            bias -= .5;
            cout << "Obviously, sarcasm. Failed state. (-.5)" << endl;
        }
    } else if (mail->category() == "Gambling"){
        if (
            victim->profession() == "Trader"
        ) {
            // It's like the essence of trading.
            // Actually it's not, but who cares,
            // we're making a game here.
            bias += .3;
            cout << "Yeah, well, a little risky, but I guess I'll try it. Just to be sure... (+.3)" << endl;
        }
        if (victim->money() > 100000) {
            bias += .5;
            cout << "Hell yeah, I like that! (+.5)" << endl;
        }
    }
    cout << "Bias: " << bias << endl;
    const int value = GetRandomValue(-100, 100);
    bias += (float)value / 100;
    cout << "Result: " << bias << endl;
    if (bias > 0) {
        return new Results(mail->reward(), 0, "Your victim has fallen prey to your mischievous intelligence...");
    }
    return new Results(0, mail->risk(), "Your victim didn't bite, you have been reported!");
}

