#pragma once

#include <frc2/command/SubsystemBase.h>
#include "rev/CANSparkMax.h"

class Arm : public frc2::SubsystemBase {
    public:
        Arm();
        void Rotate(double speed);
        void Stop();
        rev::SparkMaxRelativeEncoder m_armEncoder = m_arm.GetEncoder();

    private:
        // TODO make sure wiring is correct.
        rev::CANSparkMax m_arm{5, rev::CANSparkMax::MotorType::kBrushless};

        double invert = 1; // change to -1 to invert motor direction

};