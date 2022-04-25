#include "Sms.hpp"

Sms::Sms() {
    text = "text"; // TODO: tymczasowy do testow
}

Sms::Sms(const std::string &text, const common::PhoneNumber &from, const common::PhoneNumber &to, bool read) :
text(text), from(from), to(to), read(read) {}

void Sms::markAsRead() {
    read = true;
}

bool Sms::isRead() {
    return read;
}

std::string Sms::getText() {
    return text;
}
