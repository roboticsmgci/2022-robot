#pragma once

#include <frc/smartdashboard/SendableChooser.h>
#include <frc/smartdashboard/SendableChooserBase.h>
#include <frc/XboxController.h>
#include <frc2/command/Command.h>

#include "commands/autonomous/OnlyTaxi.h"
#include "commands/autonomous/Ball1sus.h"

#include "subsystems/Drivetrain.h"


class RobotContainer {

    public:

        RobotContainer();
        frc2::Command* GetAutonomousCommand();

        Drivetrain m_drivetrain;

    private:

        // Autonomous
        frc::SendableChooser<frc2::Command*> m_chooser;
        OnlyTaxi m_onlyTaxi{m_drivetrain};
        Ball1sus m_ball1sus{m_drivetrain};

        // Joysticks
        frc::XboxController m_xbox{0};

        void ConfigureButtonBindings();

};
