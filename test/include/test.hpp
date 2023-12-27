#pragma once

#include <iostream>
#include <Eigen/Core>

#include <pcl/point_types.h>
#include <pcl/registration/gicp.h>

using GICP = pcl::GeneralizedIterativeClosestPoint<pcl::PointXYZ, pcl::PointXYZ>;

class BBS3DTest {
public:
  BBS3DTest();
  ~BBS3DTest();

  int run(std::string config);

private:
  bool load_config(const std::string& config);

private:
  std::unique_ptr<GICP> gicp_ptr;

  // path
  std::string tar_path, src_path, output_path;

  // 3D-BBS parameters
  double min_level_res;
  int max_level;

  // angular search range
  Eigen::Vector3d min_rpy;
  Eigen::Vector3d max_rpy;

  // score threshold percentage
  double score_threshold_percentage;

  // downsample
  float tar_leaf_size, src_leaf_size;
  double min_scan_range, max_scan_range;

  // align
  bool use_gicp;
};
