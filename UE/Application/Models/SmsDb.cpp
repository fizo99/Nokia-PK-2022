#include "SmsDb.hpp"

ue::SmsDb::SmsDb() {
    smsList.push_back(Sms());
}

void ue::SmsDb::addSms(std::string text, common::PhoneNumber fromPhoneNumber, common::PhoneNumber toPhoneNumber) {
    Sms sms = Sms(text, fromPhoneNumber, toPhoneNumber, std::chrono::system_clock::now());
    smsList.push_back(sms);
}
std::vector<Sms> ue::SmsDb::getSmsList() {
    return smsList;
}

std::optional<Sms> ue::SmsDb::retrieveSms(int index) {
    if(smsList.size() > index) {
        smsList[index].markAsRead();
        return smsList[index];
    }
    return std::nullopt;
}

void markLastSmsSentAsFailed() {
    if(!std::vector::empty(smsList))
    {
        smsList.back().markAsNotReceived();
    }
}
