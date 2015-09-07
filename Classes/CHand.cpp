#include "CHand.h"

#include <functional>
#include <algorithm>
#include <limits>

typedef std::vector<uint8_t> vecFace;
typedef std::vector<uint8_t> vecSuit;
typedef std::vector<uint8_t> vecFaceDist;

typedef vecFace::iterator vecFaceIter;
typedef vecSuit::iterator vecSuitIter;
typedef vecFaceDist::iterator vecFaceDistIter;

const uint8_t face_max = 13;
const uint8_t suit_max = 4;
const uint8_t hand_max = 5;

enum class suitindex : uint8_t {
    club,
    diamond,
    heart,
    spade,
};

Hand::Hand() : _cards(), _value(0), _faceFrequency(vecFace(face_max)), _suitFrequency(vecSuit(suit_max)), _faceDistribution(vecFaceDist(face_max)) { }

Hand::Hand(const Hand& other) : _cards(other._cards), _value(other._value), _faceFrequency(other._faceFrequency), _suitFrequency(other._suitFrequency), _faceDistribution(other._faceDistribution)  { }

Hand& Hand::operator=(const Hand& rhs) {
    if(this == &rhs) return *this;

    this->_cards = rhs._cards;
    this->_value = rhs._value;
    this->_faceFrequency = rhs._faceFrequency;
    this->_suitFrequency = rhs._suitFrequency;
    this->_faceDistribution = rhs._faceDistribution;

    return *this;
}

bool Hand::operator==(const Hand& rhs) {
    if(this == &rhs) return true;
    return this->_value == rhs._value;
}

bool Hand::operator!=(const Hand& rhs) {
    return !(*this == rhs);
}

bool Hand::operator<(const Hand& rhs) {
    auto my_handtype = this->GetHandType();
    auto your_handtype = rhs.GetHandType();
    if(my_handtype < your_handtype) return true;
    if(your_handtype < my_handtype) return false;

    //Hand type guarenteed to be equal...
    auto my_highcard = this->GetHighCard();
    auto your_highcard = rhs.GetHighCard();
    if(my_highcard < your_highcard) return true;
    return false;
}

bool Hand::operator>=(const Hand& rhs) {
    return !(*this < rhs);
}

bool Hand::operator>(const Hand& rhs) {
    return this->_value > rhs._value;
}

bool Hand::operator<=(const Hand& rhs) {
    return !(*this > rhs);
}

bool Hand::AddCard(const Card& c) {
    std::size_t s = _cards.size();
    if(s == hand_max) return false;
    _cards.push_back(c);
    return true;
}

bool Hand::RemoveCard(const Card& c) {
    std::size_t s = _cards.size();
    if(s == 0) return false;
    for(std::size_t i = 0; i < s; ++i) {
        if(_cards[i] != c) continue;
        std::vector<Card>::const_iterator _iter = _cards.begin() + i;
        _cards.erase(_iter);
        return true;
    }
    return false;
}


void Hand::SetValue(uint32_t v) {
    _value = v;
}

uint32_t Hand::GetValue() const {
    return _value;
}

uint32_t Hand::GetValue() {
    return static_cast<const Hand&>(*this).GetValue();
}

void Hand::CalculateValue() {
    
    CalculateFaceFrequency();
    CalculateFaceDistribution();
    CalculateSuitFrequency();

    uint8_t hand_type = static_cast<uint8_t>(hand::type::highcard);
    this->SetHighCard(CalculateHighCard());
    if(IsStraightFlush()) {
        hand_type = static_cast<uint8_t>(hand::type::straightflush);
    } else if(IsFourOfAKind()) {
        for(std::size_t i = 0; i < _faceFrequency.size(); ++i) {
            if(_faceFrequency[i] == 4) {
                this->SetHighCard(Card(static_cast<cardvalue::face>((i + 2) << 4U), cardvalue::suit::spade));
                hand_type = static_cast<uint8_t>(hand::type::fourkind);
            }
        }
    } else if(IsFullHouse()) {
        for(std::size_t i = 0; i < _faceFrequency.size(); ++i) {
            if(_faceFrequency[i] != 3) continue;

            auto threekind_face = static_cast<cardvalue::face>((i + 2) << 4U);
            for(auto& c : _cards) {
                auto curFace = c.GetFace();
                if(curFace != threekind_face) continue;
                this->SetHighCard(c);
            }
        }
        hand_type = static_cast<uint8_t>(hand::type::fullhouse);
    } else if(IsFlush()) {
        hand_type = static_cast<uint8_t>(hand::type::flush);
    } else if(IsStraight()) {
        hand_type = static_cast<uint8_t>(hand::type::straight);
    } else if(IsThreeOfAKind()) {
        for(std::size_t i = 0; i < _faceFrequency.size(); ++i) {
            if(_faceFrequency[i] != 3) continue;

            auto threekind_face = static_cast<cardvalue::face>((i + 2) << 4U);
            for(auto& c : _cards) {
                auto curFace = c.GetFace();
                if(curFace != threekind_face) continue;
                this->SetHighCard(c);
            }
        }
        hand_type = static_cast<uint8_t>(hand::type::threekind);
    } else if(IsTwoPair()) {

        bool first_pair_found = false;
        cardvalue::face first_pair_face = cardvalue::face::two;
        cardvalue::face second_pair_face = cardvalue::face::two;
        for(std::size_t i = 0; i < _faceFrequency.size(); ++i) {
            if(_faceFrequency[i] != 2) continue;
            if(!first_pair_found) {
                first_pair_found = true;
                first_pair_face = static_cast<cardvalue::face>((i + 2) << 4U);
            } else {
                second_pair_face = static_cast<cardvalue::face>((i + 2) << 4U);
                for(auto& c : _cards) {
                    auto curFace = c.GetFace();
                    if(first_pair_face < second_pair_face) {
                        this->SetHighCard(Card(second_pair_face, static_cast<cardvalue::suit>(c.GetSuit())));
                    } else {
                        this->SetHighCard(Card(first_pair_face, static_cast<cardvalue::suit>(c.GetSuit())));
                    }
                }
            }
        }
        hand_type = static_cast<uint8_t>(hand::type::twopair);
    } else if(IsPair()) {
        for(std::size_t i = 0; i < _faceFrequency.size(); ++i) {
            if(_faceFrequency[i] != 2) continue;
            auto pair_face = static_cast<cardvalue::face>((i + 2) << 4U);
            for(auto& c : _cards) {
                auto curFace = c.GetFace();
                if(curFace != pair_face) continue;
                this->SetHighCard(Card(pair_face, static_cast<cardvalue::suit>(c.GetSuit())));
            }
        }
        hand_type = static_cast<uint8_t>(hand::type::onepair);
    } else {
        /* DO NOTHING, hand_type defaults to hand::type::highcard */
    }
    uint16_t hand_mask = 0xFF00U;
    uint16_t not_hand_mask = ~hand_mask;
    _value &= not_hand_mask;
    _value |= hand_type << 8;
}

void Hand::CalculateFaceFrequency() {

    std::fill(std::begin(_faceFrequency), std::end(_faceFrequency), 0);

    auto b = std::begin(this->_cards);
    auto e = std::end(this->_cards);

    std::for_each(b, e, [=](const Card& c) {
        auto curFace = c.GetFace();
        auto index = (curFace >> 4) - 2;
        this->_faceFrequency[index]++;
    });

}

void Hand::CalculateFaceDistribution() {

    _faceDistribution[0] = _faceFrequency[0];
    std::size_t s = _faceDistribution.size();
    for(std::size_t i = 1; i < s; ++i) {
        _faceDistribution[i] = _faceFrequency[i] + _faceDistribution[i - 1];
    }


}

void Hand::CalculateSuitFrequency() {

    std::fill(_suitFrequency.begin(), _suitFrequency.end(), 0);

    std::vector<Card>::iterator b = this->_cards.begin();
    std::vector<Card>::iterator e = this->_cards.end();

    std::for_each(b, e, [=](const Card& c) {
        cardvalue::suit curSuit = static_cast<cardvalue::suit>(c.GetSuit());
        switch(curSuit) {
            case cardvalue::suit::club:
                _suitFrequency[static_cast<uint8_t>(suitindex::club)]++;
                break;
            case cardvalue::suit::diamond:
                _suitFrequency[static_cast<uint8_t>(suitindex::diamond)]++;
                break;
            case cardvalue::suit::heart:
                _suitFrequency[static_cast<uint8_t>(suitindex::heart)]++;
                break;
            case cardvalue::suit::spade:
                _suitFrequency[static_cast<uint8_t>(suitindex::spade)]++;
                break;
        };
    });

}

Card Hand::CalculateHighCard() {
    std::size_t s = _cards.size();
    uint8_t hc = 0;
    for(std::size_t i = 0; i < s; ++i) {
        if(_cards[i].GetValue() > hc) hc = _cards[i].GetValue();
    }
    return Card(static_cast<cardvalue::face>(hc & 0xF0), static_cast<cardvalue::suit>(hc & 0x0F));
}

void Hand::SetHighCard(const Card& c) {
    uint16_t high_card_mask = 0x00FFU;
    auto card_value = c.GetValue();
    _value = (_value & (~high_card_mask)) | card_value;
}

Card Hand::GetHighCard() const {
    uint16_t high_card_mask = 0x00FF;
    uint8_t high_card_value = _value & high_card_mask;
    cardvalue::face face = static_cast<cardvalue::face>((high_card_value & 0xF0));
    cardvalue::suit suit = static_cast<cardvalue::suit>(high_card_value & 0x0F);
    return Card(face, suit);
}

Card Hand::GetHighCard() {
    return static_cast<const Hand&>(*this).GetHighCard();
}

bool Hand::IsPair() const {
    return std::count(std::begin(_faceFrequency), std::end(_faceFrequency), 2) == 1;
}

bool Hand::IsPair() {
    return static_cast<const Hand&>(*this).IsPair();
}

bool Hand::IsTwoPair() const {
    return std::count(std::begin(_faceFrequency), std::end(_faceFrequency), 2) == 2;
}

bool Hand::IsTwoPair() {
    return static_cast<const Hand&>(*this).IsTwoPair();
}

bool Hand::IsThreeOfAKind() const {
    return std::count(std::begin(_faceFrequency), std::end(_faceFrequency), 3) == 1;
}

bool Hand::IsThreeOfAKind() {
    return static_cast<const Hand&>(*this).IsThreeOfAKind();
}

bool Hand::IsStraight() const {

    bool isFiveHigh = (_faceFrequency[12] == 1 && _faceFrequency[0] == 1 && _faceFrequency[1] == 1 && _faceFrequency[2] == 1 && _faceFrequency[3] == 1);
    if(isFiveHigh) return true;

    bool isSixHigh = (_faceFrequency[0] == 1 && _faceFrequency[1] == 1 && _faceFrequency[2] == 1 && _faceFrequency[3] == 1 && _faceFrequency[4] == 1);
    if(isSixHigh) return true;

    bool isSevenHigh = (_faceFrequency[1] == 1 && _faceFrequency[2] == 1 && _faceFrequency[3] == 1 && _faceFrequency[4] == 1 && _faceFrequency[5] == 1);
    if(isSevenHigh) return true;

    bool isEightHigh = (_faceFrequency[2] == 1 && _faceFrequency[3] == 1 && _faceFrequency[4] == 1 && _faceFrequency[5] == 1 && _faceFrequency[6] == 1);
    if(isEightHigh) return true;

    bool isNineHigh = (_faceFrequency[3] == 1 && _faceFrequency[4] == 1 && _faceFrequency[5] == 1 && _faceFrequency[6] == 1 && _faceFrequency[7] == 1);
    if(isNineHigh) return true;

    bool isTenHigh = (_faceFrequency[4] == 1 && _faceFrequency[5] == 1 && _faceFrequency[6] == 1 && _faceFrequency[7] == 1 && _faceFrequency[8] == 1);
    if(isTenHigh) return true;

    bool isJackHigh = (_faceFrequency[5] == 1 && _faceFrequency[6] == 1 && _faceFrequency[7] == 1 && _faceFrequency[8] == 1 && _faceFrequency[9] == 1);
    if(isJackHigh) return true;

    bool isQueenHigh = (_faceFrequency[6] == 1 && _faceFrequency[7] == 1 && _faceFrequency[8] == 1 && _faceFrequency[9] == 1 && _faceFrequency[10] == 1);
    if(isQueenHigh) return true;

    bool isKingHigh = (_faceFrequency[7] == 1 && _faceFrequency[8] == 1 && _faceFrequency[9] == 1 && _faceFrequency[10] == 1 && _faceFrequency[11] == 1);
    if(isKingHigh) return true;

    bool isAceHigh = (_faceFrequency[8] == 1 && _faceFrequency[9] == 1 && _faceFrequency[10] == 1 && _faceFrequency[11] == 1 && _faceFrequency[12] == 1);
    if(isAceHigh) return true;

    return false;
}

bool Hand::IsStraight() {
    return static_cast<const Hand&>(*this).IsStraight();
}

bool Hand::IsFlush() const {
    return std::count(std::begin(_suitFrequency), std::end(_suitFrequency), 5) == 1;
}

bool Hand::IsFlush() {
    return static_cast<const Hand&>(*this).IsFlush();
}

bool Hand::IsFullHouse() const {
    if(IsThreeOfAKind() == false) return false;
    return IsPair();
}

bool Hand::IsFullHouse() {
    return static_cast<const Hand&>(*this).IsFullHouse();
}

bool Hand::IsFourOfAKind() const {
    return std::count(std::begin(_faceFrequency), std::end(_faceFrequency), 4) == 1;
}

bool Hand::IsFourOfAKind() {
    return static_cast<const Hand&>(*this).IsFourOfAKind();
}

bool Hand::IsStraightFlush() const {
    return IsFlush() && IsStraight();
}

bool Hand::IsStraightFlush() {
    return static_cast<const Hand&>(*this).IsStraightFlush();
}

std::size_t Hand::size() const {
    return _cards.size();
}

std::size_t Hand::size() {
    return static_cast<const Hand&>(*this).size();
}

bool Hand::empty() const {
    return _cards.empty();
}

bool Hand::empty() {
    return static_cast<const Hand&>(*this).empty();
}

std::vector<Card>::const_iterator Hand::begin() const {
    return this->_cards.begin();
}
std::vector<Card>::iterator Hand::begin() {
    return this->_cards.begin();
}

std::vector<Card>::const_iterator Hand::end() const {
    return this->_cards.end();
}
std::vector<Card>::iterator Hand::end() {
    return this->_cards.end();
}

const Card& Hand::GetCardAt(std::size_t index) const {
    return _cards[index];
}

Card& Hand::GetCardAt(std::size_t index) {
    return const_cast<Card&>(static_cast<const Hand&>(*this).GetCardAt(index));
}

hand::type Hand::GetHandType() const {
    uint16_t hand_type_mask = 0xFF00U;
    return static_cast<hand::type>(((_value & hand_type_mask) >> 8));
}

hand::type Hand::GetHandType() {
    return static_cast<const Hand&>(*this).GetHandType();
}

void Hand::SortHand() {
    std::sort(std::begin(_cards), std::end(_cards), std::greater<Card&>());
}
