

#include <ros/ros.h>
#include <sensor_msgs/Imu.h>
#include <geometry_msgs/Vector3Stamped.h>


int main(int argc, char * argv[])
{

    ros::init(argc,argv,"imu_dummy");
    ros::NodeHandle nh("~");

    ros::Publisher imu_pub = nh.advertise<sensor_msgs::Imu>("data",1);
    ros::Publisher rpy_pub = nh.advertise<geometry_msgs::Vector3Stamped>("rpy",1);
    ros::Publisher mag_pub = nh.advertise<geometry_msgs::Vector3Stamped>("mag",1);

    sensor_msgs::Imu imu_data;
    imu_data.header.frame_id = "/dummy";
    geometry_msgs::Vector3Stamped rpy_data;
    rpy_data.header.frame_id = "/dummy";
    geometry_msgs::Vector3Stamped mag_data;
    mag_data.header.frame_id = "/dummy";
    while (ros::ok()) {
        ros::Time now = ros::Time::now();
        double t = now.toSec();
        imu_data.header.stamp = now;
        mag_data.header.stamp = now;
        rpy_data.header.stamp = now;

        mag_data.vector.x = cos(t);
        mag_data.vector.y = sin(t);
        mag_data.vector.z = cos(t/100);

        rpy_data.vector.x = cos(t/3);
        rpy_data.vector.y = sin(t/3);
        rpy_data.vector.z = cos(t/2);


        imu_pub.publish(imu_data);
        rpy_pub.publish(rpy_data);
        mag_pub.publish(mag_data);
    }


    return 0;
}


