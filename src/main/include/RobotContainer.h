// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/Joystick.h>
#include "frc/smartdashboard/SendableChooser.h"
#include "frc/smartdashboard/SendableChooserBase.h"
#include <frc2/command/Command.h>

#include "commands/autonomous/Ball2.h"
#include "commands/autonomous/Ball2b.h"
#include "commands/autonomous/Ball3.h"
#include "commands/autonomous/OnlyTaxi.h"

#include "subsystems/Drivetrain.h"
#include "subsystems/Intake.h"
#include "subsystems/Arm.h"

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
        Arm m_arm;

        Ball2 m_ball2{m_arm, m_drivetrain, m_intake};
        Ball2 m_ball2b{m_arm, m_drivetrain, m_intake};
        Ball3 m_ball3{m_arm, m_drivetrain, m_intake};
        OnlyTaxi m_only_taxi{m_drivetrain, m_intake};

        frc::SendableChooser<frc2::Command*> m_chooser;

        double speed = 0;

        void ConfigureButtonBindings();
};
