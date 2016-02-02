
#ifndef BRO_PLUGIN_METRON_KAFKA
#define BRO_PLUGIN_METRON_KAFKA

#include <plugin/Plugin.h>

namespace plugin {
namespace Metron_Kafka {

class Plugin : public ::plugin::Plugin
{
protected:
	// Overridden from plugin::Plugin.
	virtual plugin::Configuration Configure();
};

extern Plugin plugin;

}
}

#endif
