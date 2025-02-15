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

#include <iostream>

#include "openhd_util.h"

static void test_execute_commands() {
  // We do echo 1, but the method should return "0" which stands for
  // command succesfully executed
  auto res = OHDUtil::run_command("echo", {"1"});
  std::cout << "Res is:" << res << "\n";
  if (res != 0) {
    throw std::runtime_error("run_command return does not match expected\n");
  }
  // Here we get the actual output in the shell, which should be 1
  auto res2 = OHDUtil::run_command_out("echo 1");
  std::cout << "Res2 is:[" << res2.value() << "]\n";
  if (res2 != "1\n") {
    throw std::runtime_error(
        "run_command_out return does not match expected\n");
  }
  auto res3 = OHDUtil::run_command_out("rambazambathiscommanddoesnotexist");
  if (res3 != std::nullopt) {
    std::cerr << "res3 is:[" << res3.value() << "]\n";
    // throw std::runtime_error("run_command_out an unknown command should
    // return command not found\n");
  }
}

int main(int argc, char *argv[]) { test_execute_commands(); }