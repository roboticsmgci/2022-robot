#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>

#include "subsystems/Drivetrain.h"
#include "subsystems/Intake.h"


class OnlyTaxi: public frc2::CommandHelper<frc2::SequentialCommandGroup, OnlyTaxi> {
    
    public:

        OnlyTaxi(Drivetrain& drivetrain, Intake& intake);

    private:

        Drivetrain* m_drivetrain;
        Intake* m_intake;

};
