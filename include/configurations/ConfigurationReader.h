//
// Created by dinko on 17.02.22.
// Modified by nermin on 22.07.23.
//

#include <string>
#include <yaml-cpp/yaml.h>
#include "yaml-cpp/parser.h"
#include "yaml-cpp/node/node.h"
#include "yaml-cpp/node/parse.h"
#include "RRTConnectConfig.h"
#include "RBTConnectConfig.h"
#include "RGBTConnectConfig.h"
#include "RGBMTStarConfig.h"
#include "DRGBTConnectConfig.h"
#include "RealVectorSpaceConfig.h"

#include <glog/logging.h>

class ConfigurationReader
{
public:
    static void initConfiguration(std::string root_path = "")
    {
        YAML::Node RealVectorSpaceConfigRoot    = YAML::LoadFile(root_path + "/data/configurations/configuration_realvectorspace.yaml");
        YAML::Node RRTConnectConfigRoot         = YAML::LoadFile(root_path + "/data/configurations/configuration_rrtconnect.yaml");
        YAML::Node RBTConnectConfigRoot         = YAML::LoadFile(root_path + "/data/configurations/configuration_rbtconnect.yaml");
        YAML::Node RGBTConnectConfigRoot        = YAML::LoadFile(root_path + "/data/configurations/configuration_rgbtconnect.yaml");
        YAML::Node RGBMTStarConfigRoot          = YAML::LoadFile(root_path + "/data/configurations/configuration_rgbmtstar.yaml");
        YAML::Node DRGBTConnectConfigRoot       = YAML::LoadFile(root_path + "/data/configurations/configuration_drgbtconnect.yaml");

        // RealVectorSpaceConfigRoot
        if (RealVectorSpaceConfigRoot["NUM_INTERPOLATION_VALIDITY_CHECKS"].IsDefined())
            RealVectorSpaceConfig::NUM_INTERPOLATION_VALIDITY_CHECKS = RealVectorSpaceConfigRoot["NUM_INTERPOLATION_VALIDITY_CHECKS"].as<int>();
        else
            LOG(INFO) << "RealVectorSpaceConfig::NUM_INTERPOLATION_VALIDITY_CHECKS is not defined! Using default value of " << RealVectorSpaceConfig::NUM_INTERPOLATION_VALIDITY_CHECKS;
        
        if (RealVectorSpaceConfigRoot["EQUALITY_THRESHOLD"].IsDefined())
            RealVectorSpaceConfig::EQUALITY_THRESHOLD = RealVectorSpaceConfigRoot["EQUALITY_THRESHOLD"].as<float>();
        else
            LOG(INFO) << "RealVectorSpaceConfig::EQUALITY_THRESHOLD is not defined! Using default value of " << RealVectorSpaceConfig::EQUALITY_THRESHOLD;

        // RRTConnectConfigRoot
        if (RRTConnectConfigRoot["MAX_NUM_ITER"].IsDefined())
            RRTConnectConfig::MAX_NUM_ITER = RRTConnectConfigRoot["MAX_NUM_ITER"].as<unsigned long>();
        else
            LOG(INFO) << "RRTConnectConfig::MAX_NUM_ITER is not defined! Using default value of " << RRTConnectConfig::MAX_NUM_ITER;
        
        if (RRTConnectConfigRoot["MAX_NUM_STATES"].IsDefined())
            RRTConnectConfig::MAX_NUM_STATES = RRTConnectConfigRoot["MAX_NUM_STATES"].as<unsigned long>();
        else
            LOG(INFO) << "RRTConnectConfig::MAX_NUM_STATES is not defined! Using default value of " << RRTConnectConfig::MAX_NUM_STATES;
        
        if (RRTConnectConfigRoot["MAX_PLANNING_TIME"].IsDefined())
            RRTConnectConfig::MAX_PLANNING_TIME = RRTConnectConfigRoot["MAX_PLANNING_TIME"].as<float>();
        else
            LOG(INFO) << "RRTConnectConfig::MAX_PLANNING_TIME is not defined! Using default value of " << RRTConnectConfig::MAX_PLANNING_TIME;
        
        if (RRTConnectConfigRoot["MAX_EXTENSION_STEPS"].IsDefined())
            RRTConnectConfig::MAX_EXTENSION_STEPS = RRTConnectConfigRoot["MAX_EXTENSION_STEPS"].as<int>();
        else
            LOG(INFO) << "RRTConnectConfig::MAX_EXTENSION_STEPS is not defined! Using default value of " << RRTConnectConfig::MAX_EXTENSION_STEPS;
        
        if (RRTConnectConfigRoot["EPS_STEP"].IsDefined())
            RRTConnectConfig::EPS_STEP = RRTConnectConfigRoot["EPS_STEP"].as<float>();
        else
            LOG(INFO) << "RRTConnectConfig::EPS_STEP is not defined! Using default value of " << RRTConnectConfig::EPS_STEP;

        // RBTConnectConfigRoot
        if (RBTConnectConfigRoot["MAX_NUM_ITER"].IsDefined())
            RBTConnectConfig::MAX_NUM_ITER = RBTConnectConfigRoot["MAX_NUM_ITER"].as<unsigned long>();
        else
            LOG(INFO) << "RBTConnectConfig::MAX_NUM_ITER is not defined! Using default value of " << RBTConnectConfig::MAX_NUM_ITER;
        
        if (RBTConnectConfigRoot["MAX_NUM_STATES"].IsDefined())
            RBTConnectConfig::MAX_NUM_STATES = RBTConnectConfigRoot["MAX_NUM_STATES"].as<unsigned long>();
        else
            LOG(INFO) << "RBTConnectConfig::MAX_NUM_STATES is not defined! Using default value of " << RBTConnectConfig::MAX_NUM_STATES;
        
        if (RBTConnectConfigRoot["MAX_PLANNING_TIME"].IsDefined())
            RBTConnectConfig::MAX_PLANNING_TIME = RBTConnectConfigRoot["MAX_PLANNING_TIME"].as<float>();
        else
            LOG(INFO) << "RBTConnectConfig::MAX_PLANNING_TIME is not defined! Using default value of " << RBTConnectConfig::MAX_PLANNING_TIME;
        
        if (RBTConnectConfigRoot["D_CRIT"].IsDefined())
            RBTConnectConfig::D_CRIT = RBTConnectConfigRoot["D_CRIT"].as<float>();
        else
            LOG(INFO) << "RBTConnectConfig::D_CRIT is not defined! Using default value of " << RBTConnectConfig::D_CRIT;
        
        if (RBTConnectConfigRoot["DELTA"].IsDefined())
            RBTConnectConfig::DELTA = RBTConnectConfigRoot["DELTA"].as<float>();
        else
            LOG(INFO) << "RBTConnectConfig::DELTA is not defined! Using default value of " << RBTConnectConfig::DELTA;
        
        if (RBTConnectConfigRoot["NUM_SPINES"].IsDefined())
            RBTConnectConfig::NUM_SPINES = RBTConnectConfigRoot["NUM_SPINES"].as<int>();
        else
            LOG(INFO) << "RBTConnectConfig::NUM_SPINES is not defined! Using default value of " << RBTConnectConfig::NUM_SPINES;

        // RGBTConnectConfigRoot
        if (RGBTConnectConfigRoot["MAX_NUM_ITER"].IsDefined())
            RGBTConnectConfig::MAX_NUM_ITER = RGBTConnectConfigRoot["MAX_NUM_ITER"].as<unsigned long>();
        else
            LOG(INFO) << "RGBTConnectConfig::MAX_NUM_ITER is not defined! Using default value of " << RGBTConnectConfig::MAX_NUM_ITER;
        
        if (RGBTConnectConfigRoot["MAX_NUM_STATES"].IsDefined())
            RGBTConnectConfig::MAX_NUM_STATES = RGBTConnectConfigRoot["MAX_NUM_STATES"].as<unsigned long>();
        else
            LOG(INFO) << "RGBTConnectConfig::MAX_NUM_STATES is not defined! Using default value of " << RGBTConnectConfig::MAX_NUM_STATES;
        
        if (RGBTConnectConfigRoot["MAX_PLANNING_TIME"].IsDefined())
            RGBTConnectConfig::MAX_PLANNING_TIME = RGBTConnectConfigRoot["MAX_PLANNING_TIME"].as<float>();
        else
            LOG(INFO) << "RGBTConnectConfig::MAX_PLANNING_TIME is not defined! Using default value of " << RGBTConnectConfig::MAX_PLANNING_TIME;
        
        if (RGBTConnectConfigRoot["NUM_LAYERS"].IsDefined())
            RGBTConnectConfig::NUM_LAYERS = RGBTConnectConfigRoot["NUM_LAYERS"].as<int>();
        else
            LOG(INFO) << "RGBTConnectConfig::NUM_LAYERS is not defined! Using default value of " << RGBTConnectConfig::NUM_LAYERS;
        
        // RGBMTStarConfigRoot
        if (RGBMTStarConfigRoot["MAX_NUM_ITER"].IsDefined())
            RGBMTStarConfig::MAX_NUM_ITER = RGBMTStarConfigRoot["MAX_NUM_ITER"].as<unsigned long>();
        else
            LOG(INFO) << "RGBMTStarConfig::MAX_NUM_ITER is not defined! Using default value of " << RGBMTStarConfig::MAX_NUM_ITER;
        
        if (RGBMTStarConfigRoot["MAX_NUM_STATES"].IsDefined())
            RGBMTStarConfig::MAX_NUM_STATES = RGBMTStarConfigRoot["MAX_NUM_STATES"].as<unsigned long>();
        else
            LOG(INFO) << "RGBMTStarConfig::MAX_NUM_STATES is not defined! Using default value of " << RGBMTStarConfig::MAX_NUM_STATES;
        
        if (RGBMTStarConfigRoot["MAX_PLANNING_TIME"].IsDefined())
            RGBMTStarConfig::MAX_PLANNING_TIME = RGBMTStarConfigRoot["MAX_PLANNING_TIME"].as<float>();
        else
            LOG(INFO) << "RGBMTStarConfig::MAX_PLANNING_TIME is not defined! Using default value of " << RGBMTStarConfig::MAX_PLANNING_TIME;
        
        if (RGBMTStarConfigRoot["TERMINATE_WHEN_PATH_IS_FOUND"].IsDefined())
            RGBMTStarConfig::TERMINATE_WHEN_PATH_IS_FOUND = RGBMTStarConfigRoot["TERMINATE_WHEN_PATH_IS_FOUND"].as<bool>();
        else
            LOG(INFO) << "RGBMTStarConfig::TERMINATE_WHEN_PATH_IS_FOUND is not defined! Using default value of " << RGBMTStarConfig::TERMINATE_WHEN_PATH_IS_FOUND;

        // DRGBTConnectConfigRoot
        if (DRGBTConnectConfigRoot["MAX_NUM_ITER"].IsDefined())
            DRGBTConnectConfig::MAX_NUM_ITER = DRGBTConnectConfigRoot["MAX_NUM_ITER"].as<unsigned long>();
        else
            LOG(INFO) << "DRGBTConnectConfig::MAX_NUM_ITER is not defined! Using default value of " << DRGBTConnectConfig::MAX_NUM_ITER;
        
        if (DRGBTConnectConfigRoot["MAX_ITER_TIME"].IsDefined())
            DRGBTConnectConfig::MAX_ITER_TIME = DRGBTConnectConfigRoot["MAX_ITER_TIME"].as<float>();
        else
            LOG(INFO) << "DRGBTConnectConfig::MAX_ITER_TIME is not defined! Using default value of " << DRGBTConnectConfig::MAX_ITER_TIME;
        
        if (DRGBTConnectConfigRoot["MAX_PLANNING_TIME"].IsDefined())
            DRGBTConnectConfig::MAX_PLANNING_TIME = DRGBTConnectConfigRoot["MAX_PLANNING_TIME"].as<float>();
        else
            LOG(INFO) << "DRGBTConnectConfig::MAX_PLANNING_TIME is not defined! Using default value of " << DRGBTConnectConfig::MAX_PLANNING_TIME;
        
        if (DRGBTConnectConfigRoot["INIT_HORIZON_SIZE"].IsDefined())
            DRGBTConnectConfig::INIT_HORIZON_SIZE = DRGBTConnectConfigRoot["INIT_HORIZON_SIZE"].as<int>();
        else
            LOG(INFO) << "DRGBTConnectConfig::INIT_HORIZON_SIZE is not defined! Using default value of " << DRGBTConnectConfig::INIT_HORIZON_SIZE;
        
        if (DRGBTConnectConfigRoot["STEP"].IsDefined())
            DRGBTConnectConfig::STEP = DRGBTConnectConfigRoot["STEP"].as<float>();
        else
            LOG(INFO) << "DRGBTConnectConfig::STEP is not defined! Using default value of " << DRGBTConnectConfig::STEP;
        
        if (DRGBTConnectConfigRoot["WEIGHT_MIN"].IsDefined())
            DRGBTConnectConfig::WEIGHT_MIN = DRGBTConnectConfigRoot["WEIGHT_MIN"].as<float>();
        else
            LOG(INFO) << "DRGBTConnectConfig::WEIGHT_MIN is not defined! Using default value of " << DRGBTConnectConfig::WEIGHT_MIN;
        
        if (DRGBTConnectConfigRoot["WEIGHT_MEAN_MIN"].IsDefined())
            DRGBTConnectConfig::WEIGHT_MEAN_MIN = DRGBTConnectConfigRoot["WEIGHT_MEAN_MIN"].as<float>();
        else
            LOG(INFO) << "DRGBTConnectConfig::WEIGHT_MEAN_MIN is not defined! Using default value of " << DRGBTConnectConfig::WEIGHT_MEAN_MIN;
        
        if (DRGBTConnectConfigRoot["D_CRIT"].IsDefined())
            DRGBTConnectConfig::D_CRIT = DRGBTConnectConfigRoot["D_CRIT"].as<float>();
        else
            LOG(INFO) << "DRGBTConnectConfig::D_CRIT is not defined! Using default value of " << DRGBTConnectConfig::D_CRIT;

        LOG(INFO) << "Configuration parameters read successfully!";
        
    }
};

