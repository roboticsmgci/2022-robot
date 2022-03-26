#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Arm.h"

class ArmDown: public frc2::CommandHelper<frc2::CommandBase, ArmDown> {

    public:
        explicit ArmDown(Arm& arm);
        void Initialize() override;
        void Execute() override;
        void End(bool interrDownted) override;

    private:
        Arm* m_arm;
        const double speed = -0.3;

};
