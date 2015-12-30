#include <iostream>
#include <thread>
#include <chrono>

#include "ptz.hpp"
#include "cv.hpp"

int main(int argc, char *const argv[]) {
  Axis6045::Axis6045 camera("192.168.0.120", "ptz", "ptz");
  camera.RefreshPosition();
  camera.ShowInfo();
  camera.SetpointPanTiltZoom(0.0, 0.0, 100);
  camera.StepTowardsSetpoint();

  std::this_thread::sleep_for(std::chrono::seconds(2));
  camera.RefreshPosition();
  camera.ShowInfo();

  AxisVision::AxisVision camvis;
  camvis.StartCapture();
  while (true) {
    // camvis.LoopCam();
    auto chrono_grab_start = std::chrono::steady_clock::now();
    camvis.LoopCam();
    auto chrono_grab_end = std::chrono::steady_clock::now();
    auto chrono_diff = chrono_grab_end - chrono_grab_start;
    std::cout << "Grab took " << std::chrono::duration <double, std::milli> (chrono_diff).count() << " milliseconds" << std::endl;

  }

  return 0;
}
