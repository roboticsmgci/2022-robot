// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Arm.h"

/**
 * Drive the given distance straight (negative values go backwards).
 * Uses a local PID controller to run a simple PID loop that is only
 * enabled while this command is running. The input is the averaged
 * values of the left and right encoders.
 */
class AutoArm: public frc2::CommandHelper<frc2::CommandBase, AutoArm> {

    public:

        AutoArm(Arm& arm, double speed);
        void Initialize() override;
        void Execute() override;
        bool IsFinished() override;
        void End(bool interrupted) override;

    private:

        Arm* m_arm;
        double m_height;
        int m_direction;
        int duration = 25;
        int duration_counter;
        double m_speed = 0.2;
};
