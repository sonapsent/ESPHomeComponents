import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import output
from esphome.const import CONF_ID
from .. import TAS5806, CONF_TAS5806_ID, tas5806_ns

DEPENDENCIES = ["tas5806"]

TAS5806Volume = tas5806_ns.class_("TAS5806Volume", output.FloatOutput)

CONFIG_SCHEMA = output.FLOAT_OUTPUT_SCHEMA.extend(
    {
        cv.Required(CONF_ID): cv.declare_id(TAS5806Volume),
        cv.GenerateID(CONF_TAS5806_ID): cv.use_id(TAS5806),
    }
)

async def to_code(config):
    paren = await cg.get_variable(config[CONF_TAS5806_ID])
    var = cg.new_Pvariable(
        config[CONF_ID],
        paren,
    )
    await output.register_output(var, config)