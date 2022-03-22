#pragma once

#include <frc2/command/SubsystemBase.h>
#include "rev/CANSparkMax.h"

class Intake : public frc2::SubsystemBase {
    public:
        Intake();
        void Rotate(double speed);
        void Stop();

    private:
        // TODO make sure wiring is correct.
        // rev::CANSparkMax m_motor{5, rev::CANSparkMax::MotorType::kBrushed};

        double invert = 1; // change to -1 to invert motor direction

};