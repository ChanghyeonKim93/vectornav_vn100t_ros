#include <ros/ros.h>
#include <imu_vn_100/imu_vn_100.h>

using namespace imu_vn_100;

int main(int argc, char** argv) {
  ros::init(argc, argv, "vn100t_node");
  ros::NodeHandle pnh("~");

  try {
    ImuVn100 imu(pnh);
    imu.Stream(true);

    ros::Rate rate(5000);
    while(ros::ok()){
      ros::spinOnce();
      rate.sleep();
    }
  } catch (const std::exception& e) {
    ROS_INFO("%s: %s", pnh.getNamespace().c_str(), e.what());
  }
}
