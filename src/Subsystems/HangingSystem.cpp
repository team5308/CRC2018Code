// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "ctre/Phoenix.h"


#include "HangingSystem.h"
#include "../RobotMap.h"
#include "../Robot.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

HangingSystem::HangingSystem() : frc::Subsystem("HangingSystem") {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    quadratureEncoder1 = RobotMap::hangingSystemQuadratureEncoder1;
    talonSRX1 = RobotMap::hangingSystemTalonSRX1;
    pIDController1 = RobotMap::hangingSystemPIDController1;
    spark1 = RobotMap::hangingSystemSpark1;
    victorSPX1 = RobotMap::hangingSystemVictorSPX1;
    victorSPX2 = RobotMap::hangingSystemVictorSPX2;


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}

void HangingSystem::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}

void HangingSystem::Periodic() {
    // Put code here to be run every loop
	frc::XboxController Xbox1(0);
	if(Xbox1.GetY(frc::GenericHID::JoystickHand::kRightHand)>0.2 || Xbox1.GetY(frc::GenericHID::JoystickHand::kRightHand)<-0.2){
		HangingSystem::talonSRX1->Set(Xbox1.GetY(frc::GenericHID::JoystickHand::kRightHand));
		HangingSystem::spark1->Set(Xbox1.GetY(frc::GenericHID::JoystickHand::kRightHand));
		HangingSystem::victorSPX1->Set(Xbox1.GetY(frc::GenericHID::JoystickHand::kRightHand));
		HangingSystem::victorSPX2->Set(Xbox1.GetY(frc::GenericHID::JoystickHand::kRightHand));
	}
	else{
		HangingSystem::talonSRX1->Set(0);
		HangingSystem::spark1->Set(0);
		HangingSystem::victorSPX1->Set(0);
		HangingSystem::victorSPX2->Set(0);
	}
}

void HangingSystem::Auto(){
}
//void HangingSystem::Auto(){
//	HangingSystem::talonSRX1->Set(ControlMode::Position,4096)
//}
// Put methods for controlling this subsystem
// here. Call these from Commands.
