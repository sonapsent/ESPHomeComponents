#include "tas5806volume.h"

#include "esphome/core/application.h"
#include "esphome/core/hal.h"
#include "esphome/core/log.h"

namespace esphome {
namespace tas5806 {

void TAS5806Volume::write_state(float state) {
  parent_->setVolume(state);
  this->volume_ = state;
}

}  // namespace tas5806
}  // namespace esphome
