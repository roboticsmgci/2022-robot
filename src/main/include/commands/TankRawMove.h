#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Drivetrain.h"


class TankRawMove: public frc2::CommandHelper<frc2::CommandBase, TankRawMove> {
    
    public:

        TankRawMove(Drivetrain& drivetrain, double speedl, double speedr, double duration);

        void Initialize() override;
        void Execute() override;
        bool IsFinished() override;
        void End(bool interrupted) override;

    private:

        Drivetrain* m_drivetrain;
        double m_speedl;
        double m_speedr;
        double m_duration;

        int period_target;
        int periods;

};
