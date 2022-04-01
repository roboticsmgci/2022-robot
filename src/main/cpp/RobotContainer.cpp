// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/button/JoystickButton.h>

#include <cmath>

#include "commands/TankDrive.h"
#include "commands/IntakeIn.h"
#include "commands/IntakeOut.h"
#include "commands/IntakeYeet.h"
#include "commands/ArmUp.h"
#include "commands/ArmDown.h"
#include "commands/ArmDrive.h"

RobotContainer::RobotContainer() {
    // Initialize all of your commands and subsystems here
    // ((-m_stick2.GetThrottle() + 2) / 3)
    m_drivetrain.SetDefaultCommand(
        TankDrive(
            [this] {
                return (
                    (
                        // tank
                        //tank is get y
                        (
                         //Get y if neither button is pressed
                            m_stick2.GetY()
                                * (int)!(m_stick2.GetRawButton(1) || m_stick2.GetRawButton(1))
                         //Average of get y if either button is pressed (opposite of previous)
                            + (m_stick1.GetY() + m_stick2.GetY()) / 2
                                * (int)(m_stick2.GetRawButton(1) || m_stick2.GetRawButton(1))
                         //Use any of that if throttle is positive
                        ) * (int)!(bool)round((-m_stick1.GetThrottle() + 1) / 2)
                        // tank
                        +
                        // arcade
                        //arcade is
                        (m_stick2.GetY()
                         //The more the z, the less the y
                            * (
                                1 - std::abs(
                                    //Get z if button is not pressed, else 0
                                    m_stick2.GetZ()
                                        * (int)!m_stick2.GetRawButton(1)
                                )
                            )
                         //Add 75% z if the button is not pressed
                        + m_stick2.GetZ()
                            * 0.75 * (int)!m_stick2.GetRawButton(1)
                        //Use it if throttle is negative
                        ) * (int)round((-m_stick1.GetThrottle() + 1) / 2)
                        // arcade
                    ) * ((-m_stick2.GetThrottle() + 2) / 3) //I think this is a constant
                );
                //End of first parameter
            },
            [this] {
                return ( - //Negative sign here, rest is same as the previous parameter expect for stick1
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
            m_drivetrain //Last parameter, drivetrain
        )
    );

    m_arm.SetDefaultCommand(
        ArmDrive(
            [this] {
                return (
                    m_stick3.GetY() / 5 //Turn the arm slowly
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
    //1st parameter is pointer to subsystem, second is which button
    frc2::JoystickButton(&m_stick3,5).WhenHeld(
        IntakeIn(m_intake)
    );
    frc2::JoystickButton(&m_stick3,3).WhenHeld(
        IntakeOut(m_intake)
    );
    frc2::JoystickButton(&m_stick3,1).WhenHeld(
        IntakeYeet(m_intake)
    );

    //I think the  arm should have another way to fully lower and raise, using WhenPressed
    frc2::JoystickButton(&m_stick3,6).WhenHeld(
        ArmUp(m_arm)
    );
    frc2::JoystickButton(&m_stick3,4).WhenHeld(
        ArmDown(m_arm)
    );

}

frc2::Command* RobotContainer::GetAutonomousCommand() {
    // An example command will be run in autonomous
    return &m_autonomousCommand;
}
