#pragma once

#include <frc/Joystick.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/smartdashboard/SendableChooserBase.h>
#include <frc2/command/Command.h>

#include "commands/autonomous/OnlyTaxi.h"

#include "subsystems/Drivetrain.h"
#include "subsystems/Intake.h"
#include "subsystems/Arm.h"


class RobotContainer {

    public:

        RobotContainer();
        frc2::Command* GetAutonomousCommand();

        Drivetrain m_drivetrain;

    private:

        Intake m_intake;
        Arm m_arm;

        // Autonomous
        frc::SendableChooser<frc2::Command*> m_chooser;
        OnlyTaxi m_onlyTaxi{m_drivetrain};

        // Joysticks
        frc::Joystick m_stick1{0};
        frc::Joystick m_stick2{1};
        frc::Joystick m_stick3{2};

        void ConfigureButtonBindings();

};
