#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>


class Intake: public frc2::SubsystemBase {

    public:

        Intake();
        void Rotate(double speed);
        void Stop();

    private:
    
        rev::CANSparkMax m_motor{6, rev::CANSparkMax::MotorType::kBrushed};

};