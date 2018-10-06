#ifndef ENUMS_H
#define ENUMS_H
// Sampled from nice website:
// https://www.123test.com/professions/
enum Professions {
    Teacher,
    Scientist,
    Trader,
    Gardener,
    Plumber,
    Pilot,
    Engineer,
    Driver,
    FactoryEmployee,
    Veterinarian,
    SoftwareDeveloper,
    SystemAdministrator,
    FilmDirector,
    Lawyer,
    Judge,
    Chemist,
    Architext,
    Farmer,
    Lobbyist,
    Bartender,
    Cook,
    Hairdresser,
    FireFighter,
    PoliceOfficer,
    Cashier,
    SalesPerson,
    Hunter,
    GarbageCollector,  // This is a funny one.
    Manager,
};

enum MaritalStatus {
    Single,
    Maried,
    Separated,
    Divorced,
    Widowed,
};

// This was taken from here:
// https://www.statista.com/statistics/263452/most-common-content-of-spam-messages-worldwide-by-category/
enum SpamCategories {
    Malware,
    HealthCare,
    Dating,
    Stocks,
    Jobs,
    Phishing,
    Finance,
    Adult,
    Products,
};
#endif
