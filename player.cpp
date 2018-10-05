class Player {
    public:
        Player() {
            m_wantedLevel = 0;
            m_money = 0;
        }
        void setMoney(const int& money) {
            m_money = money;
        }
        void setWantedLevel(const int& wantedLevel) {
            m_wantedLevel = wantedLevel;
        }
        void addMoney(const int& money) {
            m_money += money;
        }
        void addWantedLevel(const int& wantedLevel) {
            m_wantedLevel += wantedLevel;
        }
        int money() {
            return m_money;
        }
        int wantedLevel() {
            return m_wantedLevel;
        }
    private:
        int m_wantedLevel;
        int m_money;
};

