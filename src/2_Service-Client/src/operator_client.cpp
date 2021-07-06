//Nama : Rizky Anggian Matondang
//NIM  : 16720470

#include "ros/ros.h"
#include "service_client/Operation.h"
#include <cstdlib>

class Operator_Client {
    private:

        ros::NodeHandle nh;

        ros::ServiceClient add_client, times_client, power_client;

    public:

        Operator_Client();

        int operate(int argc, char **argv);

};
Operator_Client::Operator_Client() {

    add_client = nh.serviceClient<service_client::Operation>("add");
    
    times_client = nh.serviceClient<service_client::Operation>("times");
    
    power_client = nh.serviceClient<service_client::Operation>("power");

}

int Operator_Client::operate(int argc, char **argv) {

    int hasil = 0;

    for (int i = 0; i < argc - 2; i++) {

        service_client::Operation srvadd, srvtimes, srvpower;

        srvpower.request.a = atoi(argv[1]);
        srvpower.request.b = argc - 3 - i;

        this->power_client.call(srvpower);

        srvtimes.request.a = atoi(argv[i + 2]);
        srvtimes.request.b = (int)srvpower.response.result;

        this->times_client.call(srvtimes);

        srvadd.request.a = hasil;
        srvadd.request.b = (int)srvtimes.response.result;

        this->add_client.call(srvadd);

        hasil = (int)srvadd.response.result;

    }

    return hasil;

}

int main(int argc, char **argv) {

    ros::init(argc, argv, "client");

    Operator_Client client;

    if (argc < 3) {

        ROS_INFO("Error. . . ");

        return 1;

    } else {

        ROS_INFO("%d", client.operate(argc, argv));

    }

    return 0;
}
