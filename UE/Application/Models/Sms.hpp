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
    void markAsRead();
    bool isRead();
    std::string getText();
};

