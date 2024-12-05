/******************************************************************************
 * OpenHD
 *
 * Licensed under the GNU General Public License (GPL) Version 3.
 *
 * This software is provided "as-is," without warranty of any kind, express or
 * implied, including but not limited to the warranties of merchantability,
 * fitness for a particular purpose, and non-infringement. For details, see the
 * full license in the LICENSE file provided with this source code.
 *
 * Non-Military Use Only:
 * This software and its associated components are explicitly intended for
 * civilian and non-military purposes. Use in any military or defense
 * applications is strictly prohibited unless explicitly and individually
 * licensed otherwise by the OpenHD Team.
 *
 * Contributors:
 * A full list of contributors can be found at the OpenHD GitHub repository:
 * https://github.com/OpenHD
 *
 * © OpenHD, All Rights Reserved.
 ******************************************************************************/

#ifndef OPENHD_OPENHD_OHD_TELEMETRY_SRC_MAV_PARAM_MAVLINK_INCLUDE_H_
#define OPENHD_OPENHD_OHD_TELEMETRY_SRC_MAV_PARAM_MAVLINK_INCLUDE_H_

extern "C" {
// NOTE: Make sure to include the openhd mavlink flavour, otherwise the custom
// messages won't bw parsed.
#include <openhd/mavlink.h>
}

#endif  // OPENHD_OPENHD_OHD_TELEMETRY_SRC_MAV_PARAM_MAVLINK_INCLUDE_H_
