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

// For the onboard computer status we read a lot of stuff,
// This is for testing these functionalities

#include <csignal>
#include <memory>

#include "../src/internal/LogCustomOHDMessages.hpp"
#include "../src/internal/OnboardComputerStatusProvider.h"
#include "openhd_platform.h"
#include "openhd_spdlog_include.h"

int main() {
  const auto platform = OHDPlatform::instance();
  const auto provider = std::make_unique<OnboardComputerStatusProvider>();

  static bool quit = false;
  signal(SIGTERM, [](int sig) { quit = true; });
  while (!quit) {
    auto tmp = provider->get_current_status();
    LogCustomOHDMessages::logOnboardComputerStatus(tmp);
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
  return 0;
}