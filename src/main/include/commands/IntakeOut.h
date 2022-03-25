#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Intake.h"

class IntakeOut : public frc2::CommandHelper<frc2::CommandBase, IntakeOut> {
    public:
        explicit IntakeOut(Intake& intake);
        void Initialize() override;
        void End(bool interrupted) override;
    
    private:
        Intake* m_intake;
        double speed = 1.0;
};