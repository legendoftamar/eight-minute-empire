//
// Created by MJ on 2019-10-04.
//

#include <iostream>
#include <limits>
#include "BiddingFacility.h"

BiddingFacility::BiddingFacility(int *availableCoin, int *playerAge): availableCoin(availableCoin), playerAge(playerAge) {
    amountBid = new int();
}

void BiddingFacility::bid() {
    while (true) {
        int *input = new int();
        cout << "\t please enter a bid between 0 and " << *availableCoin << ": ";
        cin >> *input;

        if (cin.fail() || *input > *availableCoin || *input < 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            *amountBid = *input;
            break;
        }
    }
}

int* BiddingFacility::getAmountBid() {
    return amountBid;
}

int* BiddingFacility::getPlayerAge() {
    return playerAge;
}

bool BiddingFacility::largerBidThan(BiddingFacility *biddingFacility) {
    // in the case of being compared to nullptr (eg if first comparison of set)
    if (biddingFacility == nullptr){
        return true;
    }

    // in the case of a tie
    if (this->amountBid ==biddingFacility->getAmountBid()) {

        // and the ages are the same
        if (this->playerAge == biddingFacility->getPlayerAge()) {
            return rand()%2;
        } else {
            return (this->playerAge > biddingFacility->getPlayerAge());
        }
    }

    return this->amountBid > biddingFacility->getAmountBid();
}

void BiddingFacility::payBid() {
    *availableCoin = *availableCoin - *amountBid;
}