#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Arm.h"

class ArmMove: public frc2::CommandHelper<frc2::CommandBase, ArmMove> {

    public:
        ArmMove(std::function<double()> speed,
                Arm& arm);
        void Execute() override;
        void Stall();
        void End(bool interrupted) override;

    private:
        std::function<double()> m_speed;
        const double stall_speed = 0;
        Arm* m_arm;

};
