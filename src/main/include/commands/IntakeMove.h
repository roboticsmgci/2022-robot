#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Intake.h"


class IntakeMove: public frc2::CommandHelper<frc2::CommandBase, IntakeMove> {
    
    public:

        IntakeMove(Intake& intake, double speed, double duration);
        void Initialize() override;
        void Execute() override;
        bool IsFinished() override;
        void End(bool interrupted) override;

    private:

        Intake* m_intake;
        double m_speed;
        double m_duration;

        int m_periods;
        int m_periodTarget;

};
