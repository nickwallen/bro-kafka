
#include "Plugin.h"
#include "KafkaWriter.h"

namespace plugin { namespace Metron_Kafka { Plugin plugin; } }

using namespace plugin::Metron_Kafka;

plugin::Configuration Plugin::Configure()
{
	AddComponent(new ::logging::Component("KafkaWriter", ::metron::kafka::KafkaWriter::Instantiate));

	plugin::Configuration config;
	config.name = "Metron::Kafka";
	config.description = "Writes logs to Kafka";
	config.version.major = 0;
	config.version.minor = 1;
	return config;
}
