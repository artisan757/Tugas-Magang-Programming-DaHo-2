// Nama : Rizky Anggian Matondang
// NIM  : 16720470

#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>

int main(int argc, char **argv)
{

  ros::init(argc, argv, "publisher");

  ros::NodeHandle n;

  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);

  ROS_INFO("Publisher running . . .");

  ros::Rate loop_rate(60);

  while (ros::ok())
  {

    std_msgs::String msg;

    msg.data = "Hello, World!";

    chatter_pub.publish(msg);


    loop_rate.sleep();
  }


  return 0;
}
