/*
 * @Copyright: Copyright (c) 2024 by xcmg, All Rights Reserved.
 * @Author: WANGT
 * @Date: 2024-07-09 09:08:43
 * @LastEditTime: 2024-07-09 16:57:59
 * @LastEditors: WANGT 1098419858@qq.com
 * @Description:
 * @FilePath: /speed_planning/src/vehicle_prediction.h
 */
#ifndef VEHICLE_PREDICTION_H_
#define VEHICLE_PREDICTION_H_
#include <cmath>

const double PI2 = 2 * M_PI;
const double V_THRESHOLD = 0.5;
const double WEIGHT_V = 0.5;

/**
 * @brief 车辆障碍物状态类.
 *
 */
struct State
{
    double x;
    double y;
    double theta;
    double length;
    double width;
    double v; // km/h
};

/**
 * @brief 根据车辆当前状态进行预测膨胀.
 *
 * @param pre_st 前一时刻状态
 * @param cur_st 当前时刻状态
 * @return State 预测状态
 */
State PredictSafetyState(State pre_st, State cur_st)
{
    State predict_st = cur_st;
    if (std::abs(cur_st.v) > V_THRESHOLD & std::hypot(cur_st.x - pre_st.x, cur_st.y - pre_st.y) < 1e-3)
    {
        double theta_pre2cur = std::atan2(cur_st.y - pre_st.y, cur_st.x - pre_st.x);
        double dtheta = theta_pre2cur - cur_st.theta;
        dtheta = dtheta - PI2 * floor(dtheta / PI2);
        dtheta = (dtheta > M_PI) ? (dtheta - PI2) : dtheta;
        bool dir_flip = (std::abs(dtheta) > M_PI_2) ? true : false;
        double expand_len = WEIGHT_V * (cur_st.v - V_THRESHOLD);
        expand_len = dir_flip ? -expand_len : expand_len;
        predict_st.x += expand_len * std::cos(cur_st.theta) / 2;
        predict_st.y += expand_len * std::sin(cur_st.theta) / 2;
        predict_st.length += std::abs(expand_len);
    }
    return predict_st;
}

#endif