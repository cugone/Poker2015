#include "CardValues.h"

namespace cardvalue {

using Ts = std::underlying_type_t<suit>;
using Tf = std::underlying_type_t<face>;

face GetFaceFromString(const std::string& face_value) {

    std::string face_value_upper(face_value);
    std::transform(std::begin(face_value_upper), std::end(face_value_upper), std::begin(face_value_upper), std::toupper);
    if(face_value_upper == "A" || face_value_upper == "ACE") {
        return face::ace;
    } else if(face_value_upper == "K" || face_value_upper == "KING") {
        return face::king;
    } else if(face_value_upper == "Q" || face_value_upper == "QUEEN") {
        return face::queen;
    } else if(face_value_upper == "J" || face_value_upper == "JACK") {
        return face::jack;
    } else if(face_value_upper == "10" || face_value_upper == "TEN") {
        return face::ten;
    } else if(face_value_upper == "9" || face_value_upper == "NINE") {
        return face::nine;
    } else if(face_value_upper == "8" || face_value_upper == "EIGHT") {
        return face::eight;
    } else if(face_value_upper == "7" || face_value_upper == "SEVEN") {
        return face::seven;
    } else if(face_value_upper == "6" || face_value_upper == "SIX") {
        return face::six;
    } else if(face_value_upper == "5" || face_value_upper == "FIVE") {
        return face::five;
    } else if(face_value_upper == "4" || face_value_upper == "FOUR") {
        return face::four;
    } else if(face_value_upper == "3" || face_value_upper == "THREE") {
        return face::three;
    } else if(face_value_upper == "2" || face_value_upper == "TWO") {
        return face::two;
    } else {
        throw std::exception("Face value not recognized.");
    }
}

suit GetSuitFromString(const std::string& suit_value) {

    std::string suit_value_upper(suit_value);
    std::transform(std::begin(suit_value_upper), std::end(suit_value_upper), std::begin(suit_value_upper), std::toupper);
    if(suit_value_upper == "S" || suit_value_upper == "SPADE") {
        return suit::spade;
    } else if(suit_value_upper == "D" || suit_value_upper == "DIAMOND") {
        return suit::diamond;
    } else if(suit_value_upper == "H" || suit_value_upper == "HEART") {
        return suit::heart;
    } else if(suit_value_upper == "C" || suit_value_upper == "CLUB") {
        return suit::club;
    } else {
        throw std::exception("Suit value not recognized.");
    }
}

uint8_t operator|(face lhs, suit rhs) {
    return (static_cast<Tf>(lhs) | static_cast<Ts>(rhs));
}

uint8_t operator|(suit lhs, face rhs) {
    return (static_cast<Ts>(lhs) | static_cast<Tf>(rhs));
}

bool operator==(face lhs, uint8_t rhs) {
    return (static_cast<Tf>(lhs) == static_cast<Ts>(rhs));
}

bool operator==(suit lhs, uint8_t rhs) {
    return (static_cast<Ts>(lhs) == static_cast<Tf>(rhs));
}

bool operator==(uint8_t lhs, suit rhs) {
    return (static_cast<Tf>(lhs) == static_cast<Ts>(rhs));
}

bool operator==(uint8_t lhs, face rhs) {
    return (static_cast<Ts>(lhs) == static_cast<Tf>(rhs));
}

bool operator!=(face lhs, uint8_t rhs) {
    return !(static_cast<Tf>(lhs) == static_cast<Ts>(rhs));
}

bool operator!=(suit lhs, uint8_t rhs) {
    return !(static_cast<Ts>(lhs) == static_cast<Tf>(rhs));
}

bool operator!=(uint8_t lhs, suit rhs) {
    return !(static_cast<Tf>(lhs) == static_cast<Ts>(rhs));
}

bool operator!=(uint8_t lhs, face rhs) {
    return !(static_cast<Ts>(lhs) == static_cast<Tf>(rhs));
}

uint8_t operator|(face lhs, uint8_t rhs) {
    return (static_cast<Tf>(lhs) | static_cast<Ts>(rhs));
}

uint8_t operator|(suit lhs, uint8_t rhs) {
    return (static_cast<Ts>(lhs) | static_cast<Tf>(rhs));
}

uint8_t operator|(uint8_t lhs, suit rhs) {
    return (static_cast<Tf>(lhs) | static_cast<Ts>(rhs));
}

uint8_t operator|(uint8_t lhs, face rhs) {
    return (static_cast<Ts>(lhs) | static_cast<Tf>(rhs));
}

uint8_t operator&(face lhs, suit rhs) {
    return (static_cast<Tf>(lhs) & static_cast<Ts>(rhs));
}

uint8_t operator&(suit lhs, face rhs) {
    return (static_cast<Ts>(lhs) & static_cast<Tf>(rhs));
}

face operator&(face lhs, uint8_t rhs) {
    return static_cast<face>(static_cast<Tf>(lhs) & static_cast<uint8_t>(rhs));
}

suit operator&(suit lhs, uint8_t rhs) {
    return static_cast<suit>(static_cast<Ts>(lhs) & static_cast<uint8_t>(rhs));
}

face operator&(uint8_t lhs, face rhs) {
    return static_cast<face>(static_cast<Tf>(lhs) & static_cast<uint8_t>(rhs));
}

suit operator&(uint8_t lhs, suit rhs) {
    return static_cast<suit>(static_cast<Ts>(lhs) & static_cast<uint8_t>(rhs));
}


}