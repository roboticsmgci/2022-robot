#include "Robot.h"

#include <cameraserver/CameraServer.h>
#include <frc/RobotController.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/CommandScheduler.h>


void Robot::RobotInit() {
    // frc::CameraServer::GetInstance()->StartAutomaticCapture(0);
    // frc::CameraServer::GetInstance()->StartAutomaticCapture(1);
    frc::RobotController::SetBrownoutVoltage(6_V);
}


void Robot::RobotPeriodic() {
    frc2::CommandScheduler::GetInstance().Run();
}


void Robot::DisabledInit() {}


void Robot::DisabledPeriodic() {}


void Robot::AutonomousInit() {

    // m_container.m_drivetrain.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);

    m_autonomousCommand = m_container.GetAutonomousCommand();

    if (m_autonomousCommand != nullptr) {
        m_autonomousCommand->Schedule();
    }
  
}

void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {

    // m_container.m_drivetrain.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);

    if (m_autonomousCommand != nullptr) {
        m_autonomousCommand->Cancel();
        m_autonomousCommand = nullptr;
    }

}


void Robot::TeleopPeriodic() {}


void Robot::TestPeriodic() {}


#ifndef RUNNING_FRC_TESTS
int main() {
    return frc::StartRobot<Robot>();
}
#endif
