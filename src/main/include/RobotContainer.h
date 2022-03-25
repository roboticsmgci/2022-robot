// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/Joystick.h>
#include <frc2/command/Command.h>

#include "commands/Autonomous.h"

#include "subsystems/Drivetrain.h"
#include "subsystems/Intake.h"

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer {

    public:
        RobotContainer();
        frc2::Command* GetAutonomousCommand();

    private:
        frc::Joystick m_stick1{0};
        frc::Joystick m_stick2{1};
        frc::Joystick m_stick3{2};

        Drivetrain m_drivetrain;
        Intake m_intake;

        Autonomous m_autonomousCommand{m_drivetrain};

        double speed = 0;

        void ConfigureButtonBindings();
};
