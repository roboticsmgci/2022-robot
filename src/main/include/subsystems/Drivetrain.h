#pragma once

#include <AHRS.h>
#include <frc/controller/PIDController.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/SPI.h>
#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>


namespace frc {
    class Joystick;
}


class Drivetrain: public frc2::SubsystemBase {

    public:

        Drivetrain();
        void Drive(double left, double right);
        void Periodic() override;
        void SetIdleMode(rev::CANSparkMax::IdleMode mode);

    private:

        static const int leftLeadID = 1;
        static const int leftFollowID = 2;
        static const int rightLeadID = 3;
        static const int rightFollowID = 4;

        rev::CANSparkMax m_leftLeadMotor{leftLeadID, rev::CANSparkMax::MotorType::kBrushless};
        rev::CANSparkMax m_leftFollowMotor{leftFollowID, rev::CANSparkMax::MotorType::kBrushless};
        rev::CANSparkMax m_rightLeadMotor{rightLeadID, rev::CANSparkMax::MotorType::kBrushless};
        rev::CANSparkMax m_rightFollowMotor{rightFollowID, rev::CANSparkMax::MotorType::kBrushless};

        frc::DifferentialDrive m_robotDrive{m_leftLeadMotor, m_rightLeadMotor};

    public:
    
        AHRS m_navX{frc::SPI::Port::kMXP};
        rev::SparkMaxRelativeEncoder m_leftLeadEncoder = m_leftLeadMotor.GetEncoder();
        rev::SparkMaxRelativeEncoder m_rightLeadEncoder = m_rightLeadMotor.GetEncoder();
        frc2::PIDController m_PIDMove{0.005, 0, 0};

};
