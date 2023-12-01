#pragma once



#include "esphome/core/component.h"
#include "esphome/components/i2c/i2c.h"
#include "esphome/components/output/float_output.h"

namespace esphome {
namespace tas5806 {


class TAS5806 : public Component, public i2c::I2CDevice, public output::FloatOutput {
 public:
  TAS5806()  {}
  float get_setup_priority() const override { return setup_priority::HARDWARE; }

  void dump_config() override;
  void setup() override;
  void loop() override;
  void setVolume(float vol);
  
  const optional<float> &get_volume() const { return volume_; }
 protected:
  void write_state(float state) override;
 private: 
  float volume_ = 50.0f;
  bool update_ = false;


};

}  // namespace tas5806
}  // namespace esphome
