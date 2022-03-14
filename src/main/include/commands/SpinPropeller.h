#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Propeller.h"

class SpinPropeller : public frc2::CommandHelper<frc2::CommandBase, SpinPropeller> {
    public:
        explicit SpinPropeller(Propeller& propeller);
        void Initialize() override;
        bool IsFinished() override;
        void End(bool interrupted) override;
    
    private:
        Propeller* m_propeller;
};