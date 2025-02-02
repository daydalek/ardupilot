/** @file: PayloadPrediction.h
 *  @author: daydalek
 *  @date: 2025-02-01
 *  @brief: PayloadPrediction.h is a file that contains the header for the payload prediction system.
 */

#pragma once

#include "AP_Math/vector2.h"
#include <AP_Common/AP_Common.h>
#include <AP_Param/AP_Param.h>
#include <AP_Common/Location.h>

class Plane;

class PayloadPredictor{
    friend class Plane;

    void init(Plane &plane);
    void update_prediction();
    bool get_impact_location(Location &loc) const;

    static const struct AP_Param::GroupInfo var_info[];

    private:
        Plane &plane;

        Location _impact_location;
        uint32_t _last_update_ms;

        Vector2f calculate_impact_offset() const ;
        void send_mavlink_message() const;

        AP_Float _payload_mass;
        AP_Float _drag_coeff;
        AP_Float _cross_area;
};