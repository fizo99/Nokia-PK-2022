#include "SmsDb.hpp"

ue::SmsDb::SmsDb() {
    smsList.push_back(Sms()); // co to?
}

void ue::SmsDb::addSms(std::string text,
                       common::PhoneNumber FromPhoneNumber,
                       common::PhoneNumber ToPhoneNumber)
{
    // jak dodac czas do tego chrono?
    smsList.push_back(Sms{text, FromPhoneNumber, ToPhoneNumber});
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

    //jak koncowo z tym optional?
}

void ue::SmsDb::markSmsAsFailed()
{
    if(smsList.empty() == true)
    {
        //pusty
    }

    smsList.back().isFialed();
}

