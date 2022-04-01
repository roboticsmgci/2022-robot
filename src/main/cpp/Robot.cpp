// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"
#include <iostream>

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/CommandScheduler.h>

#include <cameraserver/CameraServer.h>

//When the robot starts
void Robot::RobotInit() {
    //Start streaming cameras
    frc::CameraServer::GetInstance()->StartAutomaticCapture(0);
    frc::CameraServer::GetInstance()->StartAutomaticCapture(1);
}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want to run during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */

 //What the robot continuosly does
void Robot::RobotPeriodic() {
    //Just has to do this method, leave it here
    frc2::CommandScheduler::GetInstance().Run();
}

/**
 * This function is called once each time the robot enters Disabled mode. You
 * can use it to reset any subsystem information you want to clear when the
 * robot is disabled.
 */

void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

/**
 * This autonomous runs the autonomous command selected by your {@link
 * RobotContainer} class.
 */

//Runs the autonomous part of the program
void Robot::AutonomousInit() {
    //Returns a pointer to the autonomous command
    m_autonomousCommand = m_container.GetAutonomousCommand();

    //If the command is gotten, run it in the schedule thing
    if (m_autonomousCommand != nullptr) {
        m_autonomousCommand->Schedule();
    }

}

void Robot::AutonomousPeriodic() {}

//Stops the autonomous program when teleop starts
void Robot::TeleopInit() {

    // This makes sure that the autonomous stops running when
    // teleop starts running. If you want the autonomous to
    // continue until interrupted by another command, remove
    // this line or comment it out.
    if (m_autonomousCommand != nullptr) {
        //Kill the autonomous command
        m_autonomousCommand->Cancel();
        m_autonomousCommand = nullptr;
    }
}

/**
 * This function is called periodically during operator control.
 */

//The main loop
void Robot::TeleopPeriodic() {}

/**
 * This function is called periodically during test mode.
 */
//Main but it's a test
void Robot::TestPeriodic() {}

//If not a test (running_frc_tests is not defined)
#ifndef RUNNING_FRC_TESTS
int main() {
    //Starts the robot
    return frc::StartRobot<Robot>();
}
#endif
