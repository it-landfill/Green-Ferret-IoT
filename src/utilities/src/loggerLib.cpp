/**
 * @file timeLib.cpp
 * @author Alessandro Benetton (aleben98@gmail.com)
 * @author Crespan Lorenzo (lorenzo.crespan@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-05-06
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "../loggerLib.hpp"
#include "../stringConverter.hpp"
#include "../../connections/MQTT.hpp"

#include <Arduino.h>

#define INFO "I"
#define ERROR "E"
#define WARNING "W"
#define DEBUG "D"

// Buffer to convert numbers to string
char tmpBuff[20];

void logMessage(const char* level, const char* module, const char *message) {
	Serial.printf("[%s] [%s] %s\n", level, module, message);
}

void logMessage(const char* level, const char* module, const char *message, const char *value) {
	Serial.printf("[%s] [%s] %s %s\n", level, module, message, value);
}

void logMessage(const char* level, const char* module, const char *message, int value) {
	Serial.printf("[%s] [%s] %s %d\n", level, module, message, value);
}

void logMessage(const char* level, const char* module, const char *message, float value) {
	Serial.printf("[%s] [%s] %s %.2f\n", level, module, message, value);
}

void logInfo(const char *module, const char *message) {
	logMessage(INFO, module, message);
}

void logInfo(const char *module, const char *message, const char* value) {
	logMessage(INFO, module, message, value);
}

void logInfo(const char *module, const char *message, String value) {
	logMessage(INFO, module, message, value.c_str());
}

void logInfo(const char *module, const char *message, int value) {
	logMessage(INFO, module, message, value);
}

void logInfo(const char *module, const char *message, float value) {
	logMessage(INFO, module, message, value);
}

void logError(const char *module, const char *message, bool send) {
	logMessage(ERROR, module, message);
	#ifndef LOCAL_DEBUG
	if (send && mqttGetStatus()) {
		mqttSendError(message);
	}
	#endif
}

void logError(const char *module, const char *message, const char* value, bool send) {
	logMessage(ERROR, module, message, value);
	#ifndef LOCAL_DEBUG
	if (send && mqttGetStatus()) {
		char *tmp = (char*) malloc((strlen(module) + strlen(message) + strlen(value) + 5)*sizeof(char));
		sprintf(tmp, "[%s] %s %s\0", module, message, value);
		mqttSendError(tmp);
	}
	#endif
}

void logError(const char *module, const char *message, String value, bool send) {
	logMessage(ERROR, module, message, value.c_str());
	#ifndef LOCAL_DEBUG
	if (send && mqttGetStatus()) {
		char *tmp = (char*) malloc((strlen(module) + strlen(message) + value.length() + 5)*sizeof(char));
		sprintf(tmp, "[%s] %s %s\0", module, message, value.c_str());
		mqttSendError(tmp);
	}
	#endif
}

void logError(const char *module, const char *message, int value, bool send) {
	logMessage(ERROR, module, message, value);
	#ifndef LOCAL_DEBUG
	if (send && mqttGetStatus()) {
		sprintf(tmpBuff, "%d\0", value);
		char *tmp = (char*) malloc((strlen(module) + strlen(message) + strlen(tmpBuff) + 5)*sizeof(char));
		sprintf(tmp, "[%s] %s %s\0", module, message, tmpBuff);
		mqttSendError(tmp);
	}
	#endif
}

void logError(const char *module, const char *message, float value, bool send) {
	logMessage(ERROR, module, message, value);
	#ifndef LOCAL_DEBUG
	if (send && mqttGetStatus()) {
		sprintf(tmpBuff, "%.2f\0", value);
		char *tmp = (char*) malloc((strlen(module) + strlen(message) + strlen(tmpBuff) + 5)*sizeof(char));
		sprintf(tmp, "[%s] %s %s\0", module, message, tmpBuff);
		mqttSendError(tmp);
	}
	#endif
}

void logWarning(const char *module, const char *message, bool send){
	logMessage(WARNING, module, message);
	#ifndef LOCAL_DEBUG
	if (send && mqttGetStatus()) {
		mqttSendWarning(message);
	}
	#endif
}

void logWarning(const char *module, const char *message, const char* value, bool send) {
	logMessage(WARNING, module, message, value);
	#ifndef LOCAL_DEBUG
	if (send && mqttGetStatus()) {
		char *tmp = (char*) malloc((strlen(module) + strlen(message) + strlen(value) + 5)*sizeof(char));
		sprintf(tmp, "[%s] %s %s\0", module, message, value);
		mqttSendWarning(tmp);
	}
	#endif
}

void logWarning(const char *module, const char *message, String value, bool send) {
	logMessage(WARNING, module, message, value.c_str());
	#ifndef LOCAL_DEBUG
	if (send && mqttGetStatus()) {
		char *tmp = (char*) malloc((strlen(module) + strlen(message) + value.length() + 5)*sizeof(char));
		sprintf(tmp, "[%s] %s %s\0", module, message, value.c_str());
		mqttSendWarning(tmp);
	}
	#endif
}

void logWarning(const char *module, const char *message, int value, bool send) {
	logMessage(WARNING, module, message, value);
	#ifndef LOCAL_DEBUG
	if (send && mqttGetStatus()) {
		sprintf(tmpBuff, "%.2f\0", value);
		char *tmp = (char*) malloc((strlen(module) + strlen(message) + strlen(tmpBuff) + 5)*sizeof(char));
		sprintf(tmp, "[%s] %s %s\0", module, message, tmpBuff);
		mqttSendWarning(tmp);
	}
	#endif
}

void logWarning(const char *module, const char *message, float value, bool send) {
	logMessage(WARNING, module, message, value);
	#ifndef LOCAL_DEBUG
	if (send && mqttGetStatus()) {
		sprintf(tmpBuff, "%.2f\0", value);
		char *tmp = (char*) malloc((strlen(module) + strlen(message) + strlen(tmpBuff) + 5)*sizeof(char));
		sprintf(tmp, "[%s] %s %s\0", module, message, tmpBuff);
		mqttSendWarning(tmp);
	}
	#endif
}

void logDebug(const char *module, const char *message){
	logMessage(DEBUG, module, message);
}

void logDebug(const char *module, const char *message, const char* value) {
	logMessage(DEBUG, module, message, value);
}

void logDebug(const char *module, const char *message, String value) {
	logMessage(DEBUG, module, message, value.c_str());
}

void logDebug(const char *module, const char *message, int value) {
	logMessage(DEBUG, module, message, value);
}

void logDebug(const char *module, const char *message, float value) {
	logMessage(DEBUG, module, message, value);
}