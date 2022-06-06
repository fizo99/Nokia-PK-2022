#include "ConnectedState.hpp"
#include "UeGui/IDialMode.hpp"

namespace ue {
    class DialNumberState : public ConnectedState{
    public:
        DialNumberState(Context& context);

        DialNumberState(Context &context, IUeGui::IDialMode &iDialMode);

        DialNumberState(Context &context, IUeGui::IDialMode &iDialMode);

        IUeGui::IDialMode& iDialMode;

        void acceptButton() override;
        void refuseButton() override;
    };


}