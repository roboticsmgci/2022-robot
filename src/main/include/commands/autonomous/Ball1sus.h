#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>

#include "subsystems/Drivetrain.h"


class Ball1sus: public frc2::CommandHelper<frc2::SequentialCommandGroup, Ball1sus> {
    
    public:

        Ball1sus(Drivetrain& drivetrain);

    private:

        Drivetrain* m_drivetrain;

};
