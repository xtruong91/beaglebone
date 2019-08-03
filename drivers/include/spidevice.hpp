/*
 * File: spidevice.hpp
 * File Created: Saturday, 3rd August 2019
 * Author: truongtx (truongtx91@gmail.com)
 * -----
 * Description: 
 * Version: 0.1
 * Tool: CMake
 * -----
 * Copyright TruongTX
 */
#ifndef SPI_DEVICE_HPP_
#define SPI_DEVICE_HPP_

#include<string>
#include<stdint.h>
#include"BusDevice.h"

namespace driver{

/**
 * @class SPIDevice
 * @brief Generic SPI Device class that can be used to connect to any type of SPI device and read or write to its registers
 */
class SPIDevice:public BusDevice {
public:
	/// The SPI Mode
	enum SPIMODE{
		MODE0 = 0,   //!< Low at idle, capture on rising clock edge
		MODE1 = 1,   //!< Low at idle, capture on falling clock edge
		MODE2 = 2,   //!< High at idle, capture on falling clock edge
		MODE3 = 3    //!< High at idle, capture on rising clock edge
	};

private:
	std::string filename;  //!< The precise filename for the SPI device
public:
	SPIDevice(unsigned int bus, unsigned int device);
	virtual int open();
	virtual unsigned char readRegister(unsigned int registerAddress);
	virtual unsigned char* readRegisters(unsigned int number, unsigned int fromAddress=0);
	virtual int writeRegister(unsigned int registerAddress, unsigned char value);
	virtual void debugDumpRegisters(unsigned int number = 0xff);
	virtual int write(unsigned char value);
	virtual int write(unsigned char value[], int length);
	virtual int setSpeed(uint32_t speed);
	virtual int setMode(SPIDevice::SPIMODE mode);
	virtual int setBitsPerWord(uint8_t bits);
	virtual void close();
	virtual ~SPIDevice();
	virtual int transfer(unsigned char read[], unsigned char write[], int length);
private:
	SPIMODE mode;     //!< The SPI mode as per the SPIMODE enumeration
	uint8_t bits;     //!< The number of bits per word
	uint32_t speed;   //!< The speed of transfer in Hz
	uint16_t delay;   //!< The transfer delay in usecs
};

} // namespace driver


#endif 