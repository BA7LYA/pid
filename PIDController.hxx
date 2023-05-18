/**
 * @file PIDController.hxx
 * @author BA7LYA (1042140025@qq.com)
 * @brief
 * @version 0.1
 * @date 2023-05-18
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once

#ifndef __PID_CONTROLLER_HXX_06834B257908__
#define __PID_CONTROLLER_HXX_06834B257908__

#include <chrono>

/**
 * @brief PID Controller
 *
 */
class PIDController
{
public:
	PIDController(
		const float& Kp,
		const float& Ki,
		const float& Kd,
		const float& historicalIntegral = 0,
		const float& lastErrorValue     = 0
	)
		: Kp(Kp)
		, Ki(Ki)
		, Kd(Kd)
		, historicalIntegral(historicalIntegral)
		, lastErrorValue(lastErrorValue)
		, lastTime(std::chrono::high_resolution_clock::now())
	{
	}

public:
	void setGain(const float& Kp, const float& Ki, const float& Kd)
	{
		this->Kp = Kp;
		this->Ki = Ki;
		this->Kd = Kd;
	}

	float step(float setPoint, float processVariable)
	{
		// now time
		auto nowTime = std::chrono::high_resolution_clock::now();

		// delta time
		std::chrono::duration<float> deltaTime = nowTime - lastTime;
		float dt = deltaTime.count();

		// error value
		float nowErrorValue = setPoint - processVariable;

		// Calculate P term
		float pTerm = Kp * nowErrorValue;

		// Calculate I term
		float iTerm = historicalIntegral + Ki * nowErrorValue * dt;

		// Calculate D term, taking care to not divide by zero
		float dTerm = Kd * ((nowErrorValue - lastErrorValue) / dt);

		// update error value
		lastErrorValue = nowErrorValue;

		// return u(t)
		return pTerm + iTerm + dTerm;
	}

private:
	// P Gain
	float Kp;

	// I Gain
	float Ki;

	// D Gain
	float Kd;

	// Historical Integral since the launch of PID Controller
	float historicalIntegral;

	// the Error Value of last step
	float lastErrorValue;

	// the Time when calc last time
	std::chrono::time_point<std::chrono::high_resolution_clock> lastTime;
};

#endif  //__PID_CONTROLLER_HXX_06834B257908__
