/*
 * Copyright 2016 Robert Pottorff PCC Lab - BYU - Provo, UT
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0

 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef fcu_sim_PLUGINS_STEPWORLD_PLUGIN_H
#define fcu_sim_PLUGINS_STEPWORLD_PLUGIN_H


#include <gazebo/common/common.hh>
#include <gazebo/common/Plugin.hh>
#include <gazebo/gazebo.hh>
#include <ros/callback_queue.h>
#include <ros/ros.h>

#include <chrono>
#include <cmath>
#include <iostream>
#include <stdio.h>

#include <std_msgs/Int16.h>
#include <boost/bind.hpp>


namespace gazebo {


class GazeboStepWorldPlugin : public WorldPlugin {
public:
  GazeboStepWorldPlugin();
  ~GazeboStepWorldPlugin();
  void commandCallback(const std_msgs::Int16 &msg);

protected:

  virtual void Load(physics::WorldPtr _parent, sdf::ElementPtr _sdf);
  void OnUpdate(const common::UpdateInfo & _info);

private:
  physics::WorldPtr world_;

  // ROS variables
  ros::NodeHandle* nh_;
  ros::Subscriber command_sub_;
  ros::Publisher pose_pub_;

  std::string namespace_;
};
} // namespace gazebo
#endif //fcu_sim_PLUGINS_STEPWORLD_PLUGIN_H
