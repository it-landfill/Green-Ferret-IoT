/**
 * @file MQTT.hpp
 * @author Alessandro Benetton (aleben98@gmail.com)
 * @author Crespan Lorenzo (lorenzo.crespan@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-05-21
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef MQTT_HPP
#define MQTT_HPP
/**
 * @brief Setup MQTT connection.
 * Set the broker address and port, the client ID and the topic.
 * 
 */
void mqttSetup();
/**
 * @brief Connect to the MQTT broker.
 * 
 * @return true Connection successful
 * @return false Connection failed
 */
bool mqttConnect();
/**
 * @brief Publish a message to the MQTT broker in the sensor data topic.
 * 
 * @param payload Message to publish
 * @return true Message published
 * @return false Publish failed
 */
bool mqttPublishSensorData(char *payload);
#endif