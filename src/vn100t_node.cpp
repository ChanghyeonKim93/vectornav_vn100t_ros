#include <ros/ros.h>
#include <imu_vn_100/imu_vn_100.h>

int main(int argc, char** argv) {
  ros::init(argc, argv, "vn100t_node");
  ros::NodeHandle nh("~");

  try {
    std::unique_ptr<imu_vn_100::ImuVn100> imu;
    imu = std::make_unique<imu_vn_100::ImuVn100>(nh);
    imu->Stream(true);

    ros::Rate rate(5000);
    while(ros::ok()){
      ros::spinOnce();
      rate.sleep();
    }
  } 
  catch (const std::exception& e) {
    ROS_INFO("%s: %s", nh.getNamespace().c_str(), e.what());
  }

  return 0;
};
