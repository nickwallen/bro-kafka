
#include "Plugin.h"

namespace plugin { namespace Metron_Kafka { Plugin plugin; } }

using namespace plugin::Metron_Kafka;

plugin::Configuration Plugin::Configure()
	{
	plugin::Configuration config;
	config.name = "Metron::Kafka";
	config.description = "<Insert description>";
	config.version.major = 0;
	config.version.minor = 1;
	return config;
	}
