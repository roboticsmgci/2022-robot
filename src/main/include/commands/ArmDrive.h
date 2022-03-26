#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Arm.h"

class ArmDrive : public frc2::CommandHelper<frc2::CommandBase, ArmDrive> {
    public:
        explicit ArmDrive(std::function<double()> speed, Arm& arm);
        void Execute() override;
        void End(bool interrupted) override;
    
    private:
        std::function<double()> m_speed;
        Arm* m_arm;
};