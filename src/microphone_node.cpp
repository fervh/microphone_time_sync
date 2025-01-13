#include <ros/ros.h>
#include <microphone_time_sync/AudioStamped.h>
#include <chrono>
#include <vector>
#include <string>
#include <signal.h>

// Variable to handle the SIGINT signal
volatile sig_atomic_t stop_requested = false;

// SIGINT signal handler
void sigintHandler(int sig) {
    stop_requested = true;
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "microphone_node", ros::init_options::NoSigintHandler);
    ros::NodeHandle nh("~");  // Using private namespace

    // Register the SIGINT signal handler
    signal(SIGINT, sigintHandler);

    // Read node parameters
    std::string topic_name;
    std::string mic_device;
    nh.param<std::string>("topic_name", topic_name, "audio");  // Default to "audio" if not specified
    nh.param<std::string>("mic_device", mic_device, "default");

    // Audio data publisher, using topic_name directly
    ros::Publisher audio_pub = nh.advertise<microphone_time_sync::AudioStamped>("/" + topic_name, 10); // Publish to "/audio" or custom topic

    ROS_INFO("Microphone node started");
    ROS_INFO("Publishing on topic: /%s", topic_name.c_str());
    ROS_INFO("Using microphone device: %s", mic_device.c_str());

    const int buffer_size = 128;  // Audio buffer size
    std::vector<uint8_t> buffer(buffer_size, 0); 

    while (ros::ok() && !stop_requested) {
        microphone_time_sync::AudioStamped msg;

        // Simulate audio data (you can replace this with your real audio source)
        for (size_t i = 0; i < buffer.size(); ++i) {
            buffer[i] = static_cast<uint8_t>(rand() % 256);
        }

        msg.header.stamp = ros::Time::now();
        msg.data = buffer;

        audio_pub.publish(msg);

        ros::spinOnce();
        ros::Duration(0.1).sleep();  // Simulate a sampling frequency of 10 Hz
    }

    ROS_INFO("Shutting down microphone_node...");

    return 0;
}
