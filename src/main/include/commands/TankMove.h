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
class TankMove: public frc2::CommandHelper<frc2::CommandBase, TankMove> {

    public:

        TankMove(Drivetrain& drivetrain, double distance, double speed);
        void Initialize() override;
        void Execute() override;
        bool IsFinished() override;
        void End(bool interrupted) override;

    private:

        Drivetrain* m_drivetrain;
        double m_distance;
        double m_speed;
        double distanceCounter;
};
