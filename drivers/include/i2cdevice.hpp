/*
 * File: i2cdevice.hpp
 * File Created: Saturday, 3rd August 2019
 * Author: truongtx (truongtx91@gmail.com)
 * -----
 * Description: 
 * Version: 0.1
 * Tool: CMake
 * -----
 * Copyright TruongTX
 */
#ifndef I2C_DEVICE_HPP_
#define I2C_DEVICE_HPP_

#include "busdevice.hpp"

namespace driver{

/**
 * @class I2CDevice
 * @brief Generic I2C Device class that can be used to connect to any type of I2C device and read or write to its registers
 */
class I2CDevice:public BusDevice{

public:
	I2CDevice(unsigned int bus, unsigned int device);
	virtual int open();
	virtual int write(unsigned char value);
	virtual unsigned char readRegister(unsigned int registerAddress);
	virtual unsigned char* readRegisters(unsigned int number, unsigned int fromAddress=0);
	virtual int writeRegister(unsigned int registerAddress, unsigned char value);
	virtual void debugDumpRegisters(unsigned int number = 0xff);
	virtual void close();
	virtual ~I2CDevice();
};

}

#endif