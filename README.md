# imu\_vn\_100
For Vectornav VN-100T rugged IMU.

The package is tested on Ubuntu 16.04 with ROS kinetic, and Ubuntu 14.04 with ROS indigo successfully.

## Troubleshooting
1. /imu: VN: Permission denied

이는 vn-100t 가 ttyUSB0 을 사용하는데 ttyUSB0은 root 와 dialout Group에만 읽기/쓰기 권한이 주어져서이다. 
현재 Linux user의 권한이 dialout Group 안에 들어가있는지 확인하기 

command 에서
>>id

dialout 이라는 글자가 안보이면 그 그룹에 안들어가있는것.

>> sudo usermod -a -G dialout <username> 으로 권한을 주고, 꼭 REBOOT을 해야지 권한이 주어진다.



