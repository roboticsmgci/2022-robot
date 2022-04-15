#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Drivetrain.h"


class TankDrive: public frc2::CommandHelper<frc2::CommandBase, TankDrive> {

    public:

        TankDrive(Drivetrain& drivetrain, std::function<double()> left, std::function<double()> right);
        void Execute() override;
        bool IsFinished() override;
        void End(bool interrupted) override;

    private:

        Drivetrain* m_drivetrain;
        std::function<double()> m_left;
        std::function<double()> m_right;

};
