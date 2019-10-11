
// Made by Gautam Sharma
#include "ros/ros.h"
#include <vector>
#include "geometry_msgs/Twist.h"

#include "geometry_msgs/PoseStamped.h"

#include "geometry_msgs/Point.h"
#include <iostream>


ros::Publisher velocity_publisher;
ros::Subscriber velocity_subscriber;

using namespace std;
double a ,b ,h;
struct coord 
{ 
   int u,v,w; 
}; 
vector<coord> pos{0};

void chatterCallback(const geometry_msgs::PoseStamped::ConstPtr& msg)

   {

     double u = msg->pose.position.x;
     double v = msg->pose.position.y;
     double w = msg->pose.position.z;
     cout<<"Current coordinates x,y,z:"<<"["<< msg->pose.position.x<<","<<msg->pose.position.y<<","<<msg->pose.position.z<<"]"<<endl;
     pos.push_back({u,v,w});
     for(auto &i : pos){
      cout<<"past coordinates: ";
      cout<<i.u<<" "<<i.v<<" "<<i.w<<endl;


     }


   }

void flight_control(double height, double hor, double vert);


//

int main(int argc, char **argv){

  ros::init(argc,argv,"drone_controller");
  ros::NodeHandle n;
  ros::NodeHandle m;
  
  velocity_publisher= n.advertise<geometry_msgs::PoseStamped>("/command/pose",1000);
  velocity_subscriber= m.subscribe("/command/pose", 1000, chatterCallback);
  ros::Rate loop_rate(10);
  cout<<"Ready to takeoff"<<endl;

  while (ros::ok()){
    cout<<"Altitude: "<<endl;
    cin>>h;
    cout<<"X coordinate: "<<endl;
    cin>>a;
    cout<<"Y coordinate: "<<endl;
    cin>>b;

    

  flight_control(h,a,b);
  ros::Duration(2).sleep();
  

   ros::spinOnce();
   loop_rate.sleep();


}
}

void flight_control(double height, double hor, double vert){
  

  geometry_msgs::PoseStamped pos_msg;
  pos_msg.header.frame_id ="world";
  pos_msg.pose.position.z = height;;
  pos_msg.pose.position.x = hor;
  pos_msg.pose.position.y = vert;
  pos_msg.pose.orientation.x = 0;
  pos_msg.pose.orientation.y = 0;
  pos_msg.pose.orientation.z = 0;
  pos_msg.pose.orientation.w = 0;
  velocity_publisher.publish(pos_msg);

}

