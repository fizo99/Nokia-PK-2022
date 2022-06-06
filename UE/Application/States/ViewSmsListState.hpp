#pragma once

#include "ConnectedState.hpp"

namespace ue {

    class ViewSmsListState : public ConnectedState {
    public:
        ViewSmsListState(Context& context);
        void acceptButton() override;
        void refuseButton() override;
        void handleSmsReceive(uint8_t action, const std::string& text, common::PhoneNumber fromPhoneNumber, common::PhoneNumber toPhoneNumber) override;
    };

}


