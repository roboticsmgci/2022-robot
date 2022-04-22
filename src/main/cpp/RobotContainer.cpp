#include "RobotContainer.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/button/JoystickButton.h>

#include <cmath>

#include "commands/TankDrive.h"


RobotContainer::RobotContainer() {

    m_chooser.SetDefaultOption("1 Ball??? sus", &m_ball1sus);
    m_chooser.AddOption("Only Taxi", &m_onlyTaxi);
    /*m_chooser.SetDefaultOption("1 Ball", &m_ball1);
    m_chooser.AddOption("2 Ball", &m_ball2);
    m_chooser.AddOption("2 Ball v2", &m_ball2b);
    m_chooser.AddOption("3 Ball", &m_ball3);*/

    frc::SmartDashboard::PutData(&m_chooser);

    // Initialize all of your commands and subsystems here
    // ((-m_stick2.GetThrottle() + 2) / 3)
    m_drivetrain.SetDefaultCommand(
        TankDrive(
            m_drivetrain,
            [this] {},
            [this] {}
        )
    );

    // Configure the button bindings
    ConfigureButtonBindings();

}


void RobotContainer::ConfigureButtonBindings() {}


frc2::Command* RobotContainer::GetAutonomousCommand() {
    return m_chooser.GetSelected();
}
