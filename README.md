# microphone_time_sync Package

`microphone_time_sync` is a ROS package that simulates a microphone node, which publishes audio data with synchronized timestamps. The main node, `microphone_node`, generates simulated audio data, timestamps it with the current system time, and publishes it to a specified topic.

## Features:
- Publishes simulated audio data to a specified topic.
- Synchronizes data with the system time using ROS timestamps.
- Highly configurable with parameters such as `topic_name` and `mic_device`.

## Parameters:
- `topic_name` (default: "audio"): The topic to publish the audio data to.
- `mic_device` (default: "default"): The microphone device (not used in simulation).

## How to Use:

### 1. Build the package in your workspace:

```bash
cd catkin_ws
```

```bash
catkin_make
```

```bash
source devel/setup.bash
```
  
### 2.1. Using `roslaunch`:

You can start the node using the provided launch file.

```bash
roslaunch microphone_time_sync microphone_time_sync.launch
```

### 2.2. Using `rosrun`:

Alternatively, you can run the node directly using rosrun:

```bash
rosrun microphone_time_sync microphone_node
```

## License:
This package is released under the MIT License.
