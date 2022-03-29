#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Intake.h"

class IntakeYeet : public frc2::CommandHelper<frc2::CommandBase, IntakeYeet> {
    public:
        explicit IntakeYeet(Intake& intake);
        void Initialize() override;
        void Execute() override;
        void End(bool interrupted) override;
    
    private:
        Intake* m_intake;
        double speed = 1;
};