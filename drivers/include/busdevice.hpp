/*
 * File: busdevice.hpp
 * File Created: Saturday, 3rd August 2019
 * Author: truongtx (truongtx91@gmail.com)
 * -----
 * Description: 
 * Version: 0.1
 * Tool: CMake
 * -----
 * Copyright TruongTX
 */

#ifndef BUS_DEVICE_HPP_
#define BUS_DEVICE_HPP_

namespace driver{

/**
 * @class BusDevice
 * @brief This class is the parent of I2C and SPI devices, so that devices that use both
 * SPI and I2C interfaces can use those interfaces interchangeably. Because it contains
 * abstract methods, the child classes MUST implement the methods that are listed in this
 * class.
 */
class BusDevice {
protected:
	unsigned int bus;    /**< the bus number */
	unsigned int device; /**< the device number on the bus  */
	int file;            /**< the file handle to the device */
public:
	BusDevice(unsigned int bus, unsigned int device);
	virtual int open()=0;
	virtual unsigned char readRegister(unsigned int registerAddress)=0;
	virtual unsigned char* readRegisters(unsigned int number, unsigned int fromAddress=0)=0;
	virtual int write(unsigned char value)=0;
	virtual int writeRegister(unsigned int registerAddress, unsigned char value)=0;
	virtual void debugDumpRegisters(unsigned int number = 0xff)=0;
	virtual void close()=0;
	virtual ~BusDevice();
};


} // namespace driver



#endif