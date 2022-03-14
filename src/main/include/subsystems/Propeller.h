#pragma once

#include <frc2/command/SubsystemBase.h>
#include "rev/CANSparkMax.h"

class Propeller : public frc2::SubsystemBase {

 public:

  Propeller();

  void Rotate();

  void Stop();

 private:

  rev::CANSparkMax m_motor{5,rev::CANSparkMax::MotorType::kBrushed};
  // Components (e.g. motor controllers and sensors) should generally be

  // declared private and exposed only through public methods.

};