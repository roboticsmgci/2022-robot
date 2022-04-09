#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Drivetrain.h"


class TankStop: public frc2::CommandHelper<frc2::CommandBase, TankStop> {
    
    public:

        TankStop(Drivetrain& drivetrain, double duration);

        void Initialize() override;
        void Execute() override;
        bool IsFinished() override;
        void End(bool interrupted) override;

    private:

        Drivetrain* m_drivetrain;
        double m_duration;

        int period_target;
        int periods;

};
