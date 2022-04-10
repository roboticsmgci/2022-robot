#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>

#include "subsystems/Arm.h"
#include "subsystems/Drivetrain.h"
#include "subsystems/Intake.h"


class GrabBall: public frc2::CommandHelper<frc2::SequentialCommandGroup, GrabBall> {
    
    public:

        GrabBall(Arm& arm, Drivetrain& drivetrain, Intake& intake);

    private:

        Arm* m_arm;
        Drivetrain* m_drivetrain;
        Intake* m_intake;

};
