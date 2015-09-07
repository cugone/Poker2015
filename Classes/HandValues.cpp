#include "HandValues.h"

#include <cctype>
#include <algorithm>

namespace hand {

std::string TypeToString(const hand::type& h) {
    switch(h) {
        case hand::type::highcard:
            return std::string("High Card");
        case hand::type::onepair:
            return std::string("One Pair");
        case hand::type::twopair:
            return std::string("Two Pair");
        case hand::type::threekind:
            return std::string("Three Of A Kind");
        case hand::type::straight:
            return std::string("Straight");
        case hand::type::flush:
            return std::string("Flush");
        case hand::type::fullhouse:
            return std::string("Fullhouse");
        case hand::type::fourkind:
            return std::string("Four Of A Kind");
        case hand::type::straightflush:
            return std::string("Straight Flush");
        default:
            return std::string("Unknown hand type.");
    }
    return std::string("This string should never display.");
}

hand::type GetTypeFromString(const std::string& type_value) {

    std::string type_value_upper(type_value);
    std::transform(std::begin(type_value_upper), std::end(type_value_upper), std::begin(type_value_upper), std::toupper);
    if(type_value_upper == "HIGH CARD" || type_value_upper == "HIGHCARD") {
        return type::highcard;
    } else if(type_value_upper == "ONE PAIR" || type_value_upper == "ONEPAIR") {
        return type::onepair;
    } else if(type_value_upper == "TWO PAIR" || type_value_upper == "TWOPAIR") {
        return type::twopair;
    } else if(type_value_upper == "THREE KIND" || type_value_upper == "THREEKIND" || type_value_upper == "THREE OF A KIND") {
        return type::threekind;
    } else if(type_value_upper == "STRAIGHT") {
        return type::straight;
    } else if(type_value_upper == "FLUSH") {
        return type::flush;
    } else if(type_value_upper == "FULLHOUSE") {
        return type::fullhouse;
    } else if(type_value_upper == "FOUR KIND" || type_value_upper == "FOURKIND" || type_value_upper == "FOUR OF A KIND") {
        return type::fourkind;
    } else if(type_value_upper == "STRAIGHT FLUSH" || type_value_upper == "STRAIGHTFLUSH") {
        return type::straightflush;
    } else {
        throw std::exception("Hand Type value not recognized.");
    }
}

std::ostream& operator<<(std::ostream& out_stream, const hand::type& h) {
    out_stream << TypeToString(h);
    return out_stream;
}

}