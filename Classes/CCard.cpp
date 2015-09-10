/*******************************************************************************
* solution: Poker
* project:  Poker
* file:     Classes\CCard.cpp
* author:   Casey Ugone
* summary:  Implements the card class
*           Copyright (c) 2015 Blisspoint Softworks. All rights reserved.
*
*******************************************************************************/
#include "CCard.h"

Card::Card() : _value(0) { }

Card::Card(const cardvalue::face& face, const cardvalue::suit& suit) : _value(face | suit) { }

Card::Card(const Card& other) : _value(other._value) { }

void Card::SetValue(uint8_t value) {
    _value = value;
}

uint8_t Card::GetValue() const {
    return _value;
}

uint8_t Card::GetValue() {
    return static_cast<const Card&>(*this).GetValue();
}

void Card::SetFace(cardvalue::face face) {
    _value = (_value & 0x0FU) | (face & 0xFFU);
}

uint8_t Card::GetFace() const {
    return (_value & 0xF0U);
}

uint8_t Card::GetFace() {
    return static_cast<const Card&>(*this).GetFace();
}

void Card::SetSuit(cardvalue::suit suit) {
    _value = (_value & 0xF0U) | (suit & 0x0FU);
}

uint8_t Card::GetSuit() const {
    return (_value & 0x0FU);
}

uint8_t Card::GetSuit() {
    return static_cast<const Card&>(*this).GetSuit();
}

Card& Card::operator=(const Card& rhs) {
    if(this == &rhs) return *this;

    this->_value = rhs._value;

    return *this;
}

bool Card::operator==(const Card& rhs) {
    return this->GetFace() == rhs.GetFace();
}

bool Card::operator!=(const Card& rhs) {
    return !(*this == rhs);
}

bool Card::operator<(const Card& rhs) {
    return this->GetFace() < rhs.GetFace();
}

bool Card::operator>(const Card& rhs) {
    return this->GetFace() > rhs.GetFace();
}


bool Card::operator<=(const Card& rhs) {
    return !(*this > rhs);
}

bool Card::operator>=(const Card& rhs) {
    return !(*this < rhs);
}

