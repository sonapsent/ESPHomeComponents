#pragma once

#ifdef USE_ESP32


#include <driver/i2c.h>

#include "esphome/core/component.h"
#include "esphome/components/i2c/i2c.h"

namespace esphome {
namespace tas5806 {


class TAS5806 : public Component, public i2c::I2CDevice, public output::FloatOutput {
 public:
  float get_setup_priority() const override { return setup_priority::HARDWARE; }

  void dump_config() override;
  void setup() override;

 protected:



};

}  // namespace tas5806
}  // namespace esphome

#endif  // USE_ESP32