#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>

#include "subsystems/Drivetrain.h"


class OnlyTaxi: public frc2::CommandHelper<frc2::SequentialCommandGroup, OnlyTaxi> {
    
    public:

        OnlyTaxi(Drivetrain& drivetrain);

    private:

        Drivetrain* m_drivetrain;

};
