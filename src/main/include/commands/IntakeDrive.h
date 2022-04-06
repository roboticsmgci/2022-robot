#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Intake.h"

class IntakeDrive : public frc2::CommandHelper<frc2::CommandBase, IntakeDrive> {
    public:
        IntakeDrive(Intake& intake, double speed);
        void Initialize() override;
        void Execute() override;
        void End(bool interrupted) override;
    
    private:
        Intake* m_intake;
        double m_speed;
};
