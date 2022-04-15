#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>


class Arm: public frc2::SubsystemBase {

    public:

        Arm();
        void Rotate(double speed);
        void Stop();

    private:
    
        rev::CANSparkMax m_arm{5, rev::CANSparkMax::MotorType::kBrushless};

};