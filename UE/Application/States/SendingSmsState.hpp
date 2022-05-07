#include "ConnectedState.hpp"
#include "UeGui/ISmsComposeMode.hpp"

namespace ue {
    class SendingSmsState : ConnectedState {
    private:
        IUeGui::ISmsComposeMode& iSmsComposeMode;
    public:
        SendingSmsState(Context& context);

        void showSmsButton() override;
        void closeSmsButton() override;
    };
}