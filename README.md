# vectornav_vn100t_ros
This repository is about "vectornav_vn100t_node" node.
It requires 'VectorNav VN-100T rugged IMU'.

Tested in:

* Ubuntu 16.04LTS with ROS Kinetic
* Ubuntu 20.04LTS with ROS Noetic

Important Note for using Factory-default and Customized Settings
------
   This node assumes that the IMU uses the **'Serial 2'** port to communicate to the PC on USB.
   
   In the LARR setting (= customized USB cable by CHK), using **'Serial 2'** port is default.
   
   Factory-default setting is using the **'Serial 1'** port. In case of using the factory-default wiring setting, you should choose the **'Serial 1'** in the roslaunch file.

1.Installation
------
    cd ~/{$YOUR_WORKSPACE}/src

    git clone https://github.com/ChanghyeonKim93/vectornav_vn100t_ros.git

    cd .. && catkin_make (or catkin build vectornav_vn100t_ros)
   

2.Usage
------
    roslaunch vectornav_vn100t_ros vn100t_ros.launch 
    
3.Parameters
-----


4.Troubleshooting
------
Issue1. **/imu: VN: Permission denied**

이는 vn-100t 가 ttyUSB0 을 사용하는데 ttyUSB0은 root 와 dialout Group에만 읽기/쓰기 권한이 주어져서이다. 
현재 Linux user의 권한이 dialout Group 안에 들어가있는지 확인하기 

In command,

    id

dialout 이라는 글자가 안보이면 그 그룹에 안들어가있는것.

    sudo usermod -a -G dialout <username> 

으로 권한을 주고, 꼭 REBOOT을 해야지 권한이 주어진다.



