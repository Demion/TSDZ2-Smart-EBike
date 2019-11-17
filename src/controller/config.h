/*
 * TongSheng TSDZ2 motor controller firmware/
 *
 * Copyright (C) Casainho, 2018.
 *
 * Released under the GPL License, Version 3
 */

#ifndef _CONFIG_H_
#define _CONFIG_H_

// This file is the firmware configuration for the TSDZ2 motor controller,
// to run the 2 different available motors of 36V or 48V motor,
// and from 24V battery (7S) up to 52V battery pack (14S).

// *************************************************************************** //
// BATTERY

// This is the current that motor will draw from the battery
// Higher value will give higher torque and the limit of the controller is 16 amps
#define ADC_BATTERY_CURRENT_MAX 29 // 18 amps (0.625 amps each unit)

// Considering the follow voltage values for each li-ion battery cell
// State of charge 		| voltage
#define LI_ION_CELL_VOLTS_100   4.06
#define LI_ION_CELL_VOLTS_80    3.93
#define LI_ION_CELL_VOLTS_60    3.78
#define LI_ION_CELL_VOLTS_40    3.60
#define LI_ION_CELL_VOLTS_20    3.38
#define LI_ION_CELL_VOLTS_10    3.25
#define LI_ION_CELL_VOLTS_0     3.00

// *************************************************************************** //
// MOTOR CONTROLLER

// Choose PWM ramp up/down step (higher value will make the motor acceleration slower)
//
// For a 24V battery, 25 for ramp up seems ok. For an higher voltage battery, this values should be higher
#define PWM_DUTY_CYCLE_RAMP_UP_INVERSE_STEP 20
#define PWM_DUTY_CYCLE_RAMP_DOWN_INVERSE_STEP 20

// *************************************************************************** //
// MOTOR

// Choose some parameters for your motor (if you don't know, just keep the following original values because they should work ok)
//
// This value should be near 0.
// You can try to tune with the whell on the air, full throttle and look at batttery current: adjust for lower battery current
#define MOTOR_ROTOR_OFFSET_ANGLE 10

#define ADC_MOTOR_PHASE_CURRENT_MAX 48 // 30 amps (0.625 amps each unit)

// This value is ERPS speed after which a transition happens from sinewave no interpolation to have
// interpolation 60 degrees and must be found experimentally but a value of 25 may be good
#define MOTOR_ROTOR_ERPS_START_INTERPOLATION_60_DEGREES 10

#define DISPLAY_VLCD5_ENABLED                                         0
#define DISPLAY_VLCD6_ENABLED                                         1

#if DISPLAY_VLCD5_ENABLED || DISPLAY_VLCD6_ENABLED
// motor type
#define MOTOR_TYPE_48V                                                0
#define MOTOR_TYPE_36V                                                1
#define MOTOR_TYPE_48V_EXPERIMENTAL_HIGH_CADENCE_MODE                 2
#define MOTOR_TYPE_36V_EXPERIMENTAL_HIGH_CADENCE_MODE                 3

// temperature limit feature
#define TEMPERATURE_LIMIT_FEATURE_NONE                                0
#define TEMPERATURE_LIMIT_FEATURE_TEMPERATURE                         1
#define TEMPERATURE_LIMIT_FEATURE_THROTTLE                            2

// motor power boost state
#define STARTUP_MOTOR_POWER_BOOST_STATE_START_ZERO_SPEED              0
#define STARTUP_MOTOR_POWER_BOOST_STATE_START_ZERO_CADENCE            1

// Battery voltage (readed on motor controller)
#define ADC_BATTERY_VOLTAGE_PER_ADC_STEP_X10000                       866

// display
#define DISPLAY_VLCD_ALWAYS_ON                                        0
#define DISPLAY_VLCD_CONTROL_FUNCTIONS                                0

#define DISPLAY_VLCD_ASSIST_LEVEL_ENABLED                             1
#define DISPLAY_VLCD_WALK_ASSIST_ENABLED                              1
#define DISPLAY_VLCD_LIGHTS_ENABLED                                   1
#define DISPLAY_VLCD_WHEEL_PERIMETER_ENABLED                          1
#define DISPLAY_VLCD_WHEEL_MAX_SPEED_ENABLED                          1
#define DISPLAY_VLCD_MOTOR_WORKING_FLAG_ENABLED                       1
#define DISPLAY_VLCD_WHEEL_TURNING_FLAG_ENABLED                       1
#define DISPLAY_VLCD_FAULT_CODE_ENABLED                               1

#define DISPLAY_VLCD_LI_ION_CELL_VOLTS_X100_OVERVOLTAGE               425
#define DISPLAY_VLCD_LI_ION_CELL_VOLTS_X100_UNDERVOLTAGE              300

#define DISPLAY_VLCD5_LI_ION_CELL_VOLTS_X100_0                        300
#define DISPLAY_VLCD5_LI_ION_CELL_VOLTS_X100_1                        325
#define DISPLAY_VLCD5_LI_ION_CELL_VOLTS_X100_2                        338
#define DISPLAY_VLCD5_LI_ION_CELL_VOLTS_X100_3                        360
#define DISPLAY_VLCD5_LI_ION_CELL_VOLTS_X100_4                        378
#define DISPLAY_VLCD5_LI_ION_CELL_VOLTS_X100_5                        393
#define DISPLAY_VLCD5_LI_ION_CELL_VOLTS_X100_6                        406

#define DISPLAY_VLCD6_LI_ION_CELL_VOLTS_X100_0                        300
#define DISPLAY_VLCD6_LI_ION_CELL_VOLTS_X100_1                        330
#define DISPLAY_VLCD6_LI_ION_CELL_VOLTS_X100_2                        344
#define DISPLAY_VLCD6_LI_ION_CELL_VOLTS_X100_3                        370
#define DISPLAY_VLCD6_LI_ION_CELL_VOLTS_X100_4                        396

#define DISPLAY_VLCD5_BATTERY_LEVEL_0                                 0x00
#define DISPLAY_VLCD5_BATTERY_LEVEL_1                                 0x02
#define DISPLAY_VLCD5_BATTERY_LEVEL_2                                 0x04
#define DISPLAY_VLCD5_BATTERY_LEVEL_3                                 0x06
#define DISPLAY_VLCD5_BATTERY_LEVEL_4                                 0x08
#define DISPLAY_VLCD5_BATTERY_LEVEL_5                                 0x0A
#define DISPLAY_VLCD5_BATTERY_LEVEL_6                                 0x0C

#define DISPLAY_VLCD6_BATTERY_LEVEL_0                                 0x00
#define DISPLAY_VLCD6_BATTERY_LEVEL_1                                 0x02
#define DISPLAY_VLCD6_BATTERY_LEVEL_2                                 0x06
#define DISPLAY_VLCD6_BATTERY_LEVEL_3                                 0x09
#define DISPLAY_VLCD6_BATTERY_LEVEL_4                                 0x0C

#define DISPLAY_VLCD_ASSIST_LEVEL_0                                   0x10
#define DISPLAY_VLCD_ASSIST_LEVEL_1                                   0x40
#define DISPLAY_VLCD_ASSIST_LEVEL_2                                   0x02
#define DISPLAY_VLCD_ASSIST_LEVEL_3                                   0x04
#define DISPLAY_VLCD_ASSIST_LEVEL_4                                   0x08

#define DISPLAY_VLCD_FAULT_CODE_NO_FAULT                              0
#define DISPLAY_VLCD_FAULT_CODE_TEMPERATURE_PROTECTION                6
#define DISPLAY_VLCD_FAULT_CODE_EBIKE_WHEEL_BLOCKED                   7
#define DISPLAY_VLCD_FAULT_CODE_OVERVOLTAGE                           8

#define DISPLAY_VLCD_WHEEL_SPEED_ROTATION_UNIT_TIME                   2.04

// default values for assist levels
#define DEFAULT_ASSIST_LEVEL                                          2

// default values for bike wheel parameters
#define DEFAULT_WHEEL_PERIMETER                                       2050          // 26 inch wheel: 2050 mm perimeter
#define DEFAULT_WHEEL_MAX_SPEED                                       50            // 50 kph

// default values for battery parameters
#define DEFAULT_BATTERY_MAX_CURRENT                                   16            // 16 amps
#define DEFAULT_TARGET_BATTERY_MAX_POWER                              250           // 250 watts
#define DEFAULT_BATTERY_CELLS_NUMBER                                  13            // 13 -> 48 V
#define DEFAULT_BATTERY_LOW_VOLTAGE_CUT_OFF_X10                       390           // 48 V battery, LVC = 39.0 (3.0 * 13)

#define DEFAULT_MOTOR_TYPE                                            MOTOR_TYPE_48V
#define DEFAULT_MOTOR_ASSISTANCE_STARTUP_WITHOUT_PEDAL_ROTATION       0
#define DEFAULT_TEMPERATURE_LIMIT_FEATURE_ENABLED                     TEMPERATURE_LIMIT_FEATURE_NONE

#define DEFAULT_LIGHTS_STATE                                          0

// default values for assist levels
#define DEFAULT_ASSIST_LEVEL_FACTOR_X10_0                             0             // 0
#define DEFAULT_ASSIST_LEVEL_FACTOR_X10_1                             6             // 0.6
#define DEFAULT_ASSIST_LEVEL_FACTOR_X10_2                             15
#define DEFAULT_ASSIST_LEVEL_FACTOR_X10_3                             21
#define DEFAULT_ASSIST_LEVEL_FACTOR_X10_4                             30

// default values for BOOST function
#define DEFAULT_STARTUP_MOTOR_POWER_BOOST_FEATURE_ENABLED             0             // disabled by default
#define DEFAULT_STARTUP_MOTOR_POWER_BOOST_STATE                       STARTUP_MOTOR_POWER_BOOST_STATE_START_ZERO_CADENCE
#define DEFAULT_STARTUP_MOTOR_POWER_BOOST_LIMIT_TO_MAX_POWER          0
#define DEFAULT_STARTUP_MOTOR_POWER_BOOST_ASSIST_LEVEL_X10_0          0
#define DEFAULT_STARTUP_MOTOR_POWER_BOOST_ASSIST_LEVEL_X10_1          2
#define DEFAULT_STARTUP_MOTOR_POWER_BOOST_ASSIST_LEVEL_X10_2          12            // 1.2
#define DEFAULT_STARTUP_MOTOR_POWER_BOOST_ASSIST_LEVEL_X10_3          23
#define DEFAULT_STARTUP_MOTOR_POWER_BOOST_ASSIST_LEVEL_X10_4          30
#define DEFAULT_STARTUP_MOTOR_POWER_BOOST_TIME_X10                    20            // 2.0 seconds
#define DEFAULT_STARTUP_MOTOR_POWER_BOOST_FADE_TIME_X10               35            // 3.5 seconds

// default values for motor temperature limit function
#define DEFAULT_MOTOR_TEMPERATURE_MIN_VALUE_TO_LIMIT                  75            // 75 degrees celsius
#define DEFAULT_MOTOR_TEMPERATURE_MAX_VALUE_TO_LIMIT                  85

// default values for internal resistance of battery
#define DEFAULT_BATTERY_PACK_RESISTANCE                               130           // 48 V battery, 13S5P measured 130 milli ohms

// default values for street mode function
#define DEFAULT_STREET_MODE_FUNCTION_ENABLED                          0
#define DEFAULT_STREET_MODE_ENABLED_ON_STARTUP                        0
#define DEFAULT_STREET_MODE_SPEED_LIMIT                               25
#define DEFAULT_STREET_MODE_POWER_LIMIT_ENABLED                       0
#define DEFAULT_STREET_MODE_POWER_LIMIT                               250           // 250 W
#define DEFAULT_STREET_MODE_THROTTLE_ENABLED                          0             // throttle is disabled in street mode by default

// default values for ramp up
#define DEFAULT_RAMP_UP_AMPS_PER_SECOND_X10                           50            // 5.0 amps per second ramp up

// default values for walk assist function
#define DEFAULT_WALK_ASSIST_FUNCTION_ENABLED                          0             // disabled by default
#define DEFAULT_WALK_ASSIST_LEVEL_FACTOR_0                            0             // target PWM for walk assist
#define DEFAULT_WALK_ASSIST_LEVEL_FACTOR_1                            30
#define DEFAULT_WALK_ASSIST_LEVEL_FACTOR_2                            45
#define DEFAULT_WALK_ASSIST_LEVEL_FACTOR_3                            55
#define DEFAULT_WALK_ASSIST_LEVEL_FACTOR_4                            65

// default values for cruise function
#define DEFAULT_CRUISE_FUNCTION_ENABLED                               0             // disabled by default
#define DEFAULT_CRUISE_FUNCTION_SET_TARGET_SPEED_ENABLED              0             // disabled by default
#define DEFAULT_CRUISE_TARGET_WHEEL_SPEED                             25            // 25 kph

// Possible values: 0, 1, 2, 3, 4, 5, 6
// 0 equal to no filtering and no delay, higher values will increase filtering but will also add bigger delay
#define DEFAULT_BATTERY_VOLTAGE_FILTER_COEFFICIENT                    6
#define DEFAULT_BATTERY_CURRENT_FILTER_COEFFICIENT                    5
#endif

#endif /* _CONFIG_H_ */
