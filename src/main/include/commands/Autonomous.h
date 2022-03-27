// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>

#include "subsystems/Drivetrain.h"
#include "subsystems/Intake.h"

/**
 * The main autonomous command to pickup and deliver the soda to the box.
 */

class Autonomous: public frc2::CommandHelper<frc2::SequentialCommandGroup, Autonomous> {
    
    public:

        Autonomous(Drivetrain& drivetrain, Intake& intake);

    private:

        Drivetrain* m_drivetrain;
        Intake* m_intake;

};
