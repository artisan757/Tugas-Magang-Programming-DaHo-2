//Nama : Rizky Anggian Matondang
//NIM  : 16720470

#include "ros/ros.h"
#include "service_client/Operation.h"
#include <cstdlib>

class Operator_Service {
    private:

        ros::NodeHandle nh;

        ros::ServiceServer add_service, times_service, power_service;

    public:

        Operator_Service();

        bool add(service_client::Operation::Request &req,
                  service_client::Operation::Response &res);

        bool times(service_client::Operation::Request &req,
                  service_client::Operation::Response &res);

        bool power(service_client::Operation::Request &req,
                  service_client::Operation::Response &res);

};

Operator_Service::Operator_Service() {

    add_service = nh.advertiseService("add", &Operator_Service::add, this);

    times_service = nh.advertiseService("times", &Operator_Service::times, this);

    power_service = nh.advertiseService("power", &Operator_Service::power, this);

}

bool Operator_Service::add(service_client::Operation::Request &req,
                          service_client::Operation::Response &res) {

    res.result = req.a + req.b;
                    
    return true; 

}

bool Operator_Service::times(service_client::Operation::Request &req,
                        service_client::Operation::Response &res) {

    res.result = req.a * req.b;

    return true;
    
}

bool Operator_Service::power(service_client::Operation::Request &req,
                           service_client::Operation::Response &res) {

    int temp = 1;

    for (int i = 0; i < req.b; i++) {

         temp = temp * req.a;

    }

    res.result = temp;

    return true;

}

int main(int argc, char **argv) {
    
    ros::init(argc, argv, "service");

    ROS_INFO("Running . . .");

    Operator_Service service;

    ros::spin();
    
    return 0;

}
