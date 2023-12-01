#include "tas5806volume.h"

#include "esphome/core/application.h"
#include "esphome/core/hal.h"
#include "esphome/core/log.h"

namespace esphome {
namespace tas5806 {

static const char *const TAG = "tas5806volume";

void TAS5806Volume::write_state(float state) {
  this->volume_ = state;
    ESP_LOGCONFIG(TAG, "Volume set to %f", state);
}

}  // namespace tas5806
}  // namespace esphome
