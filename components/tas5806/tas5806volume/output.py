import esphome.codegen as cg
import esphome.config_validation as cv
from esphome import pins
from esphome.components import output
from esphome.const import CONF_ID

CODEOWNERS = ["@bozzobrain"]

tas5806_volume_ns = cg.esphome_ns.namespace("tas5806volume")
Tas5806Volume = tas5806_volume_ns.class_("TAS5806Volume", output.FloatOutput, cg.Component)

CONFIG_SCHEMA = cv.All(
    output.FLOAT_OUTPUT_SCHEMA.extend(
        {
            cv.Required(CONF_ID): cv.declare_id(Tas5806Volume),
       
        }
    ).extend(cv.COMPONENT_SCHEMA),
)


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
    await output.register_output(var, config)


