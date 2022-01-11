#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/point_cloud2.hpp"

#include <pcl/point_cloud.h>
#include <pcl_conversions/pcl_conversions.h>

#include <iostream>
#include <string>
#include <memory>
#include <functional>

const int MSG_QUEUE_SIZE = 1000;
const std::string TOPIC_NAME = "/velodyne_points";
const std::string NODE_NAME = "point_cloud_subscruber";

class LidarSubscriber : public rclcpp::Node
{

	public:
		LidarSubscriber()
			: Node(NODE_NAME)
		{
			_subscription = this->create_subscription<sensor_msgs::msg::PointCloud2>(TOPIC_NAME, MSG_QUEUE_SIZE, std::bind(&LidarSubscriber::callback, this, std::placeholders::_1));
		}

	private:
		rclcpp::Subscription<sensor_msgs::msg::PointCloud2>::SharedPtr _subscription;

		void callback(const sensor_msgs::msg::PointCloud2::SharedPtr pPc2)
		{
				
		}

		void processPointCloud()
		{

		}

};

int main(int argc, char* argv[])
{
	rclcpp::init(argc, argv);
	rclcpp::spin(std::make_shared<LidarSubscriber>());
	rclcpp::shutdown();
	return 0;
}
