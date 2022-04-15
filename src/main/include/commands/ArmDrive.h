#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Arm.h"


class ArmDrive: public frc2::CommandHelper<frc2::CommandBase, ArmDrive> {

    public:

        explicit ArmDrive(Arm& arm, std::function<double()> speed);
        void Execute() override;
        void End(bool interrupted) override;
    
    private:

        Arm* m_arm;
        std::function<double()> m_speed;

};