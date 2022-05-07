#include "BtsPort.hpp"
#include "Messages/IncomingMessage.hpp"
#include "Messages/OutgoingMessage.hpp"

namespace ue
{

BtsPort::BtsPort(common::ILogger &logger, common::ITransport &transport, common::PhoneNumber phoneNumber)
    : logger(logger, "[BTS-PORT]"),
      transport(transport),
      phoneNumber(phoneNumber)
{}

void BtsPort::start(IBtsEventsHandler &handler)
{
    this->handler = &handler;
    transport.registerMessageCallback([this](BinaryMessage msg) {handleMessage(msg);});
    transport.registerDisconnectedCallback([this]{this->handler->handleDisconnected(); });
}

void BtsPort::stop()
{
    transport.registerDisconnectedCallback(nullptr);
    transport.registerMessageCallback(nullptr);
    handler = nullptr;
}

void BtsPort::handleMessage(BinaryMessage msg)
{
    try
    {
        common::IncomingMessage reader{msg};
        auto msgId = reader.readMessageId();
        auto from = reader.readPhoneNumber();
        auto to = reader.readPhoneNumber();

        switch (msgId)
        {
        case common::MessageId::Sib:
        {
            auto btsId = reader.readBtsId();
            handler->handleSib(btsId);
            break;
        }
        case common::MessageId::AttachResponse:
        {
            bool accept = reader.readNumber<std::uint8_t>() != 0u;
            if (accept)
                handler->handleAttachAccept();
            else
                handler->handleAttachReject();
            break;
        }
        case common::MessageId::Sms:
        {
            auto action = reader.readNumber<std::uint8_t>();
            if(action == 0) {
                std::string text = reader.readRemainingText();
                handler->handleSmsReceive(action, text, from, to);
            }
            else {
                // TODO
            };
        }
        // TODO: default option when phoneNumber not found
        default:
            logger.logError("unknow message: ", msgId, ", from: ", from);

        }
    }
    catch (std::exception const& ex)
    {
        logger.logError("handleMessage error: ", ex.what());
    }
}
void BtsPort::sendSms(common::PhoneNumber toPhoneNumber, std::string text) {

    common::OutgoingMessage outgoingMessage = common::OutgoingMessage(common::MessageId::Sms, phoneNumber, toPhoneNumber);
    outgoingMessage.writeNumber(static_cast<uint8_t>(0)); // TODO: przesylanie parametru ACTION w celu wyboru czy wysylanie sms czy wyjscie, czy cos innego
    outgoingMessage.writeText(text);

    transport.sendMessage(outgoingMessage.getMessage());
}


common::PhoneNumber BtsPort::getOwnPhoneNumber() {
    return phoneNumber;
}


void BtsPort::sendAttachRequest(common::BtsId btsId)
{
    logger.logDebug("sendAttachRequest: ", btsId);
    common::OutgoingMessage msg{common::MessageId::AttachRequest,
                                phoneNumber,
                                common::PhoneNumber{}};
    msg.writeBtsId(btsId);
    transport.sendMessage(msg.getMessage());
}



}
