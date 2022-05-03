#pragma once
#include <Models/Sms.hpp>
#include <vector>
#include <string>
#include <optional>

namespace ue {

    class SmsDb {

    private:
        std::vector<Sms> smsList;
    public:
        SmsDb();
        void addSms(std::string, common::PhoneNumber, common::PhoneNumber, bool = false); // tu chyba tez chrono trzeba dodac?
        std::vector<Sms> getSmsList();
        std::optional<Sms> retrieveSms(int index);
        void markSmsAsFailed();
    };

}
