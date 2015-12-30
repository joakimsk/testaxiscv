#include <iostream>
#include <thread>

#include "ptz.hpp"
#include "cv.hpp"

int main(int argc, char *const argv[]) {
  Axis6045::Axis6045 camera("192.168.0.120", "ptz", "ptz");
  camera.RefreshPosition();
 camera.ShowInfo();
    camera.SetpointPanTiltZoom(0.0,0.0,100);
    camera.StepTowardsSetpoint();

  std::this_thread::sleep_for(std::chrono::seconds(2));
    camera.RefreshPosition();
    camera.ShowInfo();

  return 0;
}
