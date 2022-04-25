#pragma once
#include <Messages/PhoneNumber.hpp>

class Sms {
private:
    std::string text;
    common::PhoneNumber from;
    common::PhoneNumber to;
    bool read = false;

public:
    Sms();
    Sms(const std::string &text, const common::PhoneNumber &from, const common::PhoneNumber &to, bool read);

    void markAsRead();
    bool isRead();
    std::string getText();
};

