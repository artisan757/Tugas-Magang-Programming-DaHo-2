// Nama : Rizky Anggian Matondang
// NIM  : 16720470

#include "ros/ros.h"
#include "std_msgs/String.h"


using namespace std;

string info;
void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  info = msg->data;
}

void print(){
  cout << info << endl;
}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "subscriber");


  ros::NodeHandle n;


  ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);

  ROS_INFO("Subscriber running . . .");

  ros::Rate rate(60);

  while(ros::ok()){
    print();
    ros::spinOnce();
    rate.sleep();
  }

  return 0;
}
