// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Drivetrain.h"

class TankDrive
    : public frc2::CommandHelper<frc2::CommandBase, TankDrive> {
 public:
  TankDrive(Drivetrain* subsystem,
                    std::function<double()> left, std::function<double()> right);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

 private:
  Drivetrain* m_drive;
  std::function<double()> mLeft;
  std::function<double()> mRight;
};
