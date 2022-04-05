#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>

#include "subsystems/Drivetrain.h"
#include "subsystems/Intake.h"


class GrabBall: public frc2::CommandHelper<frc2::SequentialCommandGroup, GrabBall> {
    
    public:

        GrabBall(Drivetrain& drivetrain, Intake& intake);

    private:

        Drivetrain* m_drivetrain;
        Intake* m_intake;

};
