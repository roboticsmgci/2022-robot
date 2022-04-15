// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Drivetrain.h"

#include <frc/Joystick.h>
#include <frc/smartdashboard/SmartDashboard.h>

Drivetrain::Drivetrain() {

    // Configures the motors to follow each other
    m_leftFollowMotor.Follow(m_leftLeadMotor);
    m_rightFollowMotor.Follow(m_rightLeadMotor);

    //Conversion factor from rotations to meters
    m_leftLeadEncoder.SetPositionConversionFactor(0.0443);
    m_rightLeadEncoder.SetPositionConversionFactor(0.0443);
   
    SetName("Drivetrain");
  
}


void Drivetrain::Drive(double left, double right) {
    m_robotDrive.TankDrive(-left, right);
}


void Drivetrain::Periodic() {
    frc::SmartDashboard::PutNumber("Gyro", m_navX.GetYaw());
}


void Drivetrain::SetIdleMode(rev::CANSparkMax::IdleMode mode){
    m_leftLeadMotor.SetIdleMode(mode);
    m_rightLeadMotor.SetIdleMode(mode);
    m_leftFollowMotor.SetIdleMode(mode);
    m_rightFollowMotor.SetIdleMode(mode);
}
