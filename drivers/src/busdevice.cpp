/*
 * File: busdevice.cpp
 * File Created: Saturday, 3rd August 2019
 * Author: truongtx (truongtx91@gmail.com)
 * -----
 * Description: 
 * Version: 0.1
 * Tool: CMake
 * -----
 * Copyright TruongTX
 */
#include "busdevice.hpp"

namespace driver{
    
/**
 * Constructor for a generic bus device
 * @param bus the bus number
 * @param device the device number
 */
BusDevice::BusDevice(unsigned int bus, unsigned int device) {
	this->bus = bus;
	this->device = device;
	this->file=-1;
}

/**
 * Destructor is unused
 */
BusDevice::~BusDevice() {}

}