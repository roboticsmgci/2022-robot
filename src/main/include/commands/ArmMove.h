#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Arm.h"


class ArmMove: public frc2::CommandHelper<frc2::CommandBase, ArmMove> {
    
    public:

        ArmMove(Arm& arm, double speed, double duration);

        void Initialize() override;
        void Execute() override;
        bool IsFinished() override;
        void End(bool interrupted) override;

    private:

        Arm* m_arm;
        double m_speed;
        double m_duration;

        int period_target;
        int periods;

};
