#pragma once

#include "Logger/PrefixedLogger.hpp"
#include "Messages/PhoneNumber.hpp"
#include "IEventsHandler.hpp"
#include "Context.hpp"

namespace ue {

    using common::PhoneNumber;
    using common::ILogger;

    class Application : public IEventsHandler {
    public:
        Application(PhoneNumber phoneNumber,
                    ILogger &iLogger,
                    IBtsPort &bts,
                    IUserPort &user,
                    ITimerPort &timer);

        ~Application();

        // ITimerEventsHandler interface
        void handleTimeout() override;

        // IBtsEventsHandler interface
        void handleSib(common::BtsId btsId) override;

        void handleAttachAccept() override;

        void handleAttachReject() override;

        void handleDisconnected() override;

        void handleSmsReceive(uint8_t action, const std::string &text,
                              common::PhoneNumber fromPhoneNumber, common::PhoneNumber toPhoneNumber) override;

        void handleFailedSmsSend() override;

        void handleCallRequest(common::PhoneNumber phoneNumber) override;

        void handleUknownRecipient(common::PhoneNumber phoneNumber) override;

        void handleCallAccept(common::PhoneNumber phoneNumber) override;

        void handleCallDrop(common::PhoneNumber phoneNumber) override;

        //IUserEventsHandler interface:
        void handleCallAccept(common::PhoneNumber phoneNumber) override;

        void handleStartDial() override;

        void handleCallRequest(common::PhoneNumber) override;

        void handleCallDrop(common::PhoneNumber) override;

    private:
        Context context;
        common::PrefixedLogger logger;

    };

}
