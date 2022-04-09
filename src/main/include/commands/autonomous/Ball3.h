#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>

#include "subsystems/Arm.h"
#include "subsystems/Drivetrain.h"
#include "subsystems/Intake.h"


class Ball3: public frc2::CommandHelper<frc2::SequentialCommandGroup, Ball3> {
    
    public:

        Ball3(Arm& arm, Drivetrain& drivetrain, Intake& intake);

    private:

        Arm* m_arm;
        Drivetrain* m_drivetrain;
        Intake* m_intake;

};
