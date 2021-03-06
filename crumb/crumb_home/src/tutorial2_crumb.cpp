/**
 * This node reads information from 
 * the topic /odom.
 * Marina Aguilar-Moreno, 2016
 * 
 * DISCLAIMER: This is a work-in-progress test code, not finished yet.
 * 
 * This code must be integrated into a ros package
 * while gazebo is running.
 * 

 */


#include "ros/ros.h"
#include "nav_msgs/Odometry.h"


void callbackodom(const nav_msgs::Odometry::ConstPtr& _msg)
{
		//ROS_INFO("HOLA");
		float x,y;
		x=_msg->pose.pose.position.x;
		y=_msg->pose.pose.position.y;		
		ROS_INFO("x=%f y=%f", x,y);
}



/////////////////////////////////////////////////
int main(int _argc, char **_argv)
{
  
  ros::init(_argc, _argv, "tutorial2_crumb");
  ros::NodeHandle n;
  ros::Rate loop_rate(10);
  
  // Create ROS node and init
  ros::Subscriber sub_odom  =n.subscribe("/odom",10, callbackodom);
     
  while (ros::ok())
  {
	  ros::spinOnce();
	  loop_rate.sleep();
  }
 
}

