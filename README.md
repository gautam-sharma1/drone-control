## waypoint controller to control drones in hector quadrotor


## Getting Started



### Installing
Install the dependencies inside catkin_ws

Open a terminal:
```
$ cd catkin_ws/src
$ git clone https://github.com/tu-darmstadt-ros-pkg/hector_quadrotor.git
$ git clone https://github.com/gautam-sharma1/drone-control.git
```

```
$ cd ..
$ catkin_make
```
Now source the new files
```
$ source devel/setup.bash
```

```
$ cd src
$ roslaunch hector_quadrotor_gazebo quadrotor_empty_world.launch
$ rosrun robot.cpp
```



### Break down into end to end tests
