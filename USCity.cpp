
#include "USCity.hpp"

// constructor
USCity::USCity( // intitialize all the fields as std::string per instructions
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
) :
    mLat(lat),
    mLng(lng),
    mCityName(cityName),
    mStateId(stateId),
    mStateName(stateName),
    mZCTA(ZCTA),
    mParentZCTA(parentZCTA),
    mPop(pop),
    mDensity(density),
    mCountyFIPS(countyFIPS),
    mCountyName(countyName),
    mCountyWeights(countyWeights),
    mCountyNamesAll(countyNamesAll),
    mCountyFIPSAll(countyFIPSAll),
    mImprecise(imprecise),
    mMilitary(military),
    mTimezone(timezone)
{};
// destructor
USCity::~USCity() {} // -> do nothing, no heap

// output stream, printing and writing
std::ostream& operator<<(std::ostream& lhs, const USCity& rhs) {
    lhs << 
    rhs.mLat << ", " <<
    rhs.mLng << ", " <<
    rhs.mCityName << ", " <<
    rhs.mStateId << ", " <<
    rhs.mStateName << ", " <<
    rhs.mZCTA << ", " <<
    rhs.mParentZCTA << ", " <<
    rhs.mPop << ", " <<
    rhs.mDensity << ", " <<
    rhs.mCountyFIPS << ", " <<
    rhs.mCountyName << ", " <<
    rhs.mCountyWeights << ", " <<
    rhs.mCountyNamesAll << ", " <<
    rhs.mCountyFIPSAll << ", " <<
    rhs.mImprecise << ", " <<
    rhs.mMilitary << ", " <<
    rhs.mTimezone << ", " << std::endl;

    return lhs;
}