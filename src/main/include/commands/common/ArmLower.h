#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>

#include "subsystems/Arm.h"


class ArmLower: public frc2::CommandHelper<frc2::SequentialCommandGroup, ArmLower> {
    
    public:

        ArmLower(Arm& arm);

    private:

        Arm* m_arm;

};
