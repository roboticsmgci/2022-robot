#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Arm.h"

class ArmUp: public frc2::CommandHelper<frc2::CommandBase, ArmUp> {

    public:
        explicit ArmUp(Arm& arm);
        void Initialize() override;
        void Execute() override;
        void End(bool interrupted) override;

    private:
        Arm* m_arm;
        const double speed = 0.3;

};
