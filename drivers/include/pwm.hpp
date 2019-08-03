/*
 * File: pwm.hpp
 * File Created: Saturday, 3rd August 2019
 * Author: truongtx (truongtx91@gmail.com)
 * -----
 * Description: 
 * Version: 0.1
 * Tool: CMake
 * -----
 * Copyright TruongTX
 */

#ifndef PWM_HPP_
#define PWM_HPP_

#include<string>
using std::string;

#define PWM_PATH "/sys/devices/ocp.3/"
#define PWM_PERIOD "period"
#define PWM_DUTY "duty"
#define PWM_POLARITY "polarity"
#define PWM_RUN "run"

namespace driver{

class PWM {
public:
	enum POLARITY{ ACTIVE_LOW=0, ACTIVE_HIGH=1 };

private:
	string name, path;
	float analogFrequency;  //defaults to 100,000 Hz
	float analogMax;        //defaults to 3.3V

public:
	PWM(string pinName);

	virtual int setPeriod(unsigned int period_ns);
	virtual unsigned int getPeriod();
	virtual int setFrequency(float frequency_hz);
	virtual float getFrequency();
	virtual int setDutyCycle(unsigned int duration_ns);
	virtual int setDutyCycle(float percentage);
	virtual unsigned int getDutyCycle();
	virtual float getDutyCyclePercent();

	virtual int setPolarity(PWM::POLARITY);
	virtual void invertPolarity();
	virtual PWM::POLARITY getPolarity();

	virtual void setAnalogFrequency(float frequency_hz) { this->analogFrequency = frequency_hz; }
	virtual int calibrateAnalogMax(float analogMax); //must be between 3.2 and 3.4
	virtual int analogWrite(float voltage);

	virtual int run();
	virtual bool isRunning();
	virtual int stop();

	virtual ~PWM();
private:
	float period_nsToFrequency(unsigned int);
	unsigned int frequencyToPeriod_ns(float);
};

}

#endif /* PWM_HPP_ */
