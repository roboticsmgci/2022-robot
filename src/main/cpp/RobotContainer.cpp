// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/button/JoystickButton.h>

#include <cmath>

#include "commands/TankDrive.h"
#include "commands/ArmDrive.h"
#include "commands/IntakeDrive.h"

// Testing
#include "commands/TankTurn.h"
#include "commands/common/GrabBall.h"
#include "commands/common/ScoreBall.h"
#include "commands/common/ArmLower.h"
#include "commands/TankMoveGyro.h"

RobotContainer::RobotContainer() {

    m_chooser.SetDefaultOption("Only Taxi", &m_only_taxi);
    m_chooser.AddOption("2 Ball", &m_ball2);
    m_chooser.AddOption("2 Ball b", &m_ball2b);
    m_chooser.AddOption("3 Ball", &m_ball3);

    frc::SmartDashboard::PutData(&m_chooser);

    // Initialize all of your commands and subsystems here
    // ((-m_stick2.GetThrottle() + 2) / 3)
    m_drivetrain.SetDefaultCommand(
        TankDrive(
            [this] {
                return ( - 
                    (
                        // tank
                        (
                            m_stick2.GetY()
                                * (int)!(m_stick2.GetRawButton(1) || m_stick2.GetRawButton(1))
                            + (m_stick1.GetY() + m_stick2.GetY()) / 2
                                * (int)(m_stick2.GetRawButton(1) || m_stick2.GetRawButton(1))
                        ) * (int)!(bool)round((-m_stick1.GetThrottle() + 1) / 2)
                        // tank
                        +
                        // arcade
                        (m_stick2.GetY()
                            * (
                                1 - std::abs(
                                    m_stick2.GetZ()
                                        * (int)!m_stick2.GetRawButton(1)
                                )
                            )
                        + m_stick2.GetZ()
                            * 0.75
                            * (int)!m_stick2.GetRawButton(1)
                        
                        ) * (int)round((-m_stick1.GetThrottle() + 1) / 2)
                        // arcade
                    ) * ((-m_stick2.GetThrottle() + 2) / 3)
                );
            },
            [this] {
                return ( -
                    (
                        // tank
                        (
                            m_stick1.GetY()
                                * (int)!(m_stick2.GetRawButton(1) || m_stick2.GetRawButton(1))
                            + (m_stick1.GetY() + m_stick2.GetY()) / 2
                                * (int)(m_stick2.GetRawButton(1) || m_stick2.GetRawButton(1))
                        ) * (int)!(bool)round((-m_stick1.GetThrottle() + 1) / 2)
                        // tank
                        + 
                        // arcade
                        (
                            m_stick2.GetY()
                                * (
                                    1 - std::abs(
                                        m_stick2.GetZ()
                                            * (int)!m_stick2.GetRawButton(1)
                                    )
                                )
                            - m_stick2.GetZ()
                                * 0.75
                                * (int)!m_stick2.GetRawButton(1)
                        ) * (int)round((-m_stick1.GetThrottle() + 1) / 2)
                        // arcade
                    ) * ((-m_stick2.GetThrottle() + 2) / 3)
                );
            },
            m_drivetrain
        )
    );

/* no u
*/

    m_arm.SetDefaultCommand(
        ArmDrive(
            [this] {
                return (
                    m_stick3.GetY() / 5
                );
            },
            m_arm
        )
    );

    // Configure the button bindings
    ConfigureButtonBindings();

    // if (m_stick2.GetRawButton(3)){
    //     speed += 0.01;
    // }
    // if (m_stick2.GetRawButton(5)){
    //     speed -= 0.01;
    // }
}

void RobotContainer::ConfigureButtonBindings() {
    frc2::JoystickButton(&m_stick3,3).WhenHeld(
        IntakeDrive(m_intake, 0.5)
    );
    frc2::JoystickButton(&m_stick3,4).WhenHeld(
        IntakeDrive(m_intake, -1)
    );

}

frc2::Command* RobotContainer::GetAutonomousCommand() {
    // An example command will be run in autonomous
    return m_chooser.GetSelected();
}
