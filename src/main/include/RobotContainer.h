#pragma once

#include <frc/Joystick.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/smartdashboard/SendableChooserBase.h>
#include <frc2/command/Command.h>

#include "commands/autonomous/Ball1.h"
#include "commands/autonomous/Ball1sus.h"
#include "commands/autonomous/Ball2.h"
#include "commands/autonomous/Ball2b.h"
#include "commands/autonomous/Ball3.h"
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
        Ball1sus m_ball1sus{m_drivetrain};
        Ball1 m_ball1{m_drivetrain, m_intake};
        Ball2 m_ball2{m_arm, m_drivetrain, m_intake};
        Ball2b m_ball2b{m_arm, m_drivetrain, m_intake};
        Ball3 m_ball3{m_arm, m_drivetrain, m_intake};

        // Joysticks
        frc::Joystick m_stick1{0};
        frc::Joystick m_stick2{1};
        frc::Joystick m_stick3{2};

        void ConfigureButtonBindings();

};
