#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Drivetrain.h"


class TankTurn: public frc2::CommandHelper<frc2::CommandBase, TankTurn> {

    public:

        TankTurn(Drivetrain& drivetrain, double angle_target);
        void Initialize() override;
        void Execute() override;
        bool IsFinished() override;
        void End(bool interrupted) override;

    private:

        Drivetrain* m_drivetrain;
        double m_angleTarget;

        const double m_error = 12;
        const double m_speed = 0.4;

        double m_angleCurrent;
        bool m_clockwise;

};
