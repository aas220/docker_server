#include "ros/ros.h"
#include "server/AddTwoInts.h"
#include <cstdlib>
#include <iostream>
#include <vector>

using std::cout; using std::cin;

int main(int argc, char **argv){
	ros::init(argc, argv, "add_two_ints_client");
	if( argc != 1)
	{	ROS_INFO("usage: add_two_ints_client X Y");
		return 1;
	}
ros::NodeHandle n;
ros::ServiceClient client = n.serviceClient<server::AddTwoInts>("add_two_ints");
server::AddTwoInts srv;
int flag;
int a;
int b;
while (true){
cout << "Give me a command, 1 to run addition, 0 to quit ";
cin >> flag;
if (flag == 1)
{
	cout << "Please insert the first int to add ";
	cin >> a;
	cout << "Please insert second int to add ";
	cin >> b;
}

if (flag == 0)
{
	return 0;
}
srv.request.a = a;
srv.request.b = b;
if(client.call(srv))
{
	ROS_INFO("Sum: %ld", (long int)srv.response.sum);

}


else
{
	ROS_ERROR("Failed to call service add_two_ints");
	return 1;
	}

}
return EXIT_SUCCESS;


}
