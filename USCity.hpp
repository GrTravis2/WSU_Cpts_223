#ifndef USCITY_H
#define USCITY_H

#include <string>
#include <iostream>

class USCity {

    private:
    //int mZip;
    std::string mLat, mLng, mCityName, mStateId, mStateName, mZCTA, mParentZCTA, mPop, mDensity, mCountyFIPS, mCountyName, mCountyWeights, mCountyNamesAll, mCountyFIPSAll, mImprecise, mMilitary, mTimezone;

    public:

    // constructor
    USCity(
        const std::string& lat,
        const std::string& lng,
        const std::string& cityName,
        const std::string& stateId,
        const std::string& stateName,
        const std::string& ZCTA,
        const std::string& parentZCTA,
        const std::string& pop,
        const std::string& density,
        const std::string& countyFIPS,
        const std::string& countyName,
        const std::string& countyWeights,
        const std::string& countyNamesAll,
        const std::string& countyFIPSAll,
        const std::string& imprecise,
        const std::string& military,
        const std::string& timezone
    );

    // destructor
    ~USCity();

    // getters

    // setters

    //public methods

    // friends :)
    friend std::ostream& operator<<(std::ostream& lhs, const USCity& rhs);

};

typedef enum cityFields {
    LAT,
    LNG,
    CITYNAME,
    STATEID,
    STATENAME,
    ZCTA,
    PARENTZCTA,
    POP,
    DENSITY,
    COUNTYFIPS,
    COUNTYNAME,
    COUNTYWEIGHTS,
    COUNTYNAMESALL,
    COUNTYFIPSALL,
    IMPRECISE,
    MILITARY,
    TIMEZONE,
    LAST = TIMEZONE,
}CITYFIELDS;

#endif