// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/drive/DifferentialDrive.h>
#include "rev/CANSparkMax.h"
#include <frc2/command/SubsystemBase.h>

namespace frc {
    class Joystick;
}

/**
 * The Drivetrain subsystem incorporates the sensors and actuators attached to
 * the robots chassis. These include four drive motors, a left and right encoder
 * and a gyro.
 */
class Drivetrain: public frc2::SubsystemBase {

    public:

        Drivetrain();
        void Drive(double left, double right);
        void Periodic() override;

    private:

        static const int leftLeadDeviceID = 1, leftFollowDeviceID = 2, rightLeadDeviceID = 3, rightFollowDeviceID = 4;
        rev::CANSparkMax m_leftLeadMotor{leftLeadDeviceID, rev::CANSparkMax::MotorType::kBrushed};
        rev::CANSparkMax m_rightLeadMotor{rightLeadDeviceID, rev::CANSparkMax::MotorType::kBrushed};
        rev::CANSparkMax m_leftFollowMotor{leftFollowDeviceID, rev::CANSparkMax::MotorType::kBrushed};
        rev::CANSparkMax m_rightFollowMotor{rightFollowDeviceID, rev::CANSparkMax::MotorType::kBrushed};

        frc::DifferentialDrive m_robotDrive{m_leftLeadMotor, m_rightLeadMotor};
};
