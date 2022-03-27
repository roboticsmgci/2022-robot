#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Drivetrain.h"

/**
 * Drive the given distance straight (negative values go backwards).
 * Uses a local PID controller to run a simple PID loop that is only
 * enabled while this command is running. The input is the averaged
 * values of the left and right encoders.
 */
class AutoDriveTaxi: public frc2::CommandHelper<frc2::CommandBase, AutoDriveTaxi> {

    public:

        AutoDriveTaxi(Drivetrain& drivetrain);
        void Initialize() override;
        void Execute() override;
        bool IsFinished() override;
        void End(bool interrupted) override;

    private:

        Drivetrain* m_drivetrain;
        int duration = 150;
        int duration_counter;
};
