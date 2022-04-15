#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>

#include "subsystems/Drivetrain.h"
#include "subsystems/Intake.h"


class Ball1: public frc2::CommandHelper<frc2::SequentialCommandGroup, Ball1> {
    
    public:

        Ball1(Drivetrain& drivetrain, Intake& intake);

    private:

        Drivetrain* m_drivetrain;
        Intake* m_intake;

};
