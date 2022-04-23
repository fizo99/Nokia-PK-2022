#include "Sms.hpp"

Sms::Sms() {
    text = "text"; // TODO: zmienic podczas implementacji na pobieranie tresci
}

void Sms::markAsRead() {
    read = true;
}

bool Sms::isRead() {
    return read;
}

std::string Sms::getText() {
    return text;
}