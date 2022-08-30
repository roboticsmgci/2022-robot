#include "RobotContainer.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/button/JoystickButton.h>

#include <cmath>

#include "commands/TankDrive.h"
#include "commands/ArmDrive.h"
#include "commands/IntakeDrive.h"


RobotContainer::RobotContainer() {

    m_chooser.SetDefaultOption("1 Ball??? sus", &m_ball1sus);
    m_chooser.AddOption("Only Taxi", &m_onlyTaxi);
    /*m_chooser.SetDefaultOption("1 Ball", &m_ball1);
    m_chooser.AddOption("2 Ball", &m_ball2);*/
    // m_chooser.AddOption("2 Ball v2", &m_ball2b);
    // m_chooser.AddOption("3 Ball", &m_ball3);

    frc::SmartDashboard::PutData(&m_chooser);

    // Initialize all of your commands and subsystems here
    // ((-m_stick2.GetThrottle() + 2) / 3)
    m_drivetrain.SetDefaultCommand(
        TankDrive(
            m_drivetrain,
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
            }
        )
    );

    m_arm.SetDefaultCommand(
        ArmDrive(
            m_arm,
            [this] {
                return (
                    m_stick3.GetY() / 5
                );
            }
        )
    );

    // Configure the button bindings
    ConfigureButtonBindings();

}


void RobotContainer::ConfigureButtonBindings() {
    frc2::JoystickButton(&m_stick3,3).WhenHeld(
        // intake
        IntakeDrive(m_intake, -0.5)
    );
    frc2::JoystickButton(&m_stick3,4).WhenHeld(
        // shooter
        IntakeDrive(m_intake, 1)
    );

}


frc2::Command* RobotContainer::GetAutonomousCommand() {
    return m_chooser.GetSelected();
}
