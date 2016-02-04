
#ifndef BRO_PLUGIN_METRON_KAFKA_KAFKAWRITER_H
#define BRO_PLUGIN_METRON_KAFKA_KAFKAWRITER_H

#include <logging/WriterBackend.h>
#include <logging/WriterFrontend.h>
#include <threading/Formatter.h>
#include <librdkafka/rdkafkacpp.h>

using logging::WriterBackend;
using logging::WriterFrontend;
using threading::Value;
using threading::Field;
using threading::formatter::Formatter;

namespace metron {
namespace kafka {

    /**
 * A logging writer that sends data to a Kafka broker.
 */
    class KafkaWriter : public WriterBackend {
    public:
        KafkaWriter(WriterFrontend* frontend);
        ~KafkaWriter();

        static WriterBackend* Instantiate(WriterFrontend* frontend)
        {
            return new KafkaWriter(frontend);
        }

    protected:
        virtual bool DoInit(const WriterBackend::WriterInfo& info, int num_fields,
            const threading::Field* const* fields);
        virtual bool DoWrite(int num_fields, const threading::Field* const* fields,
            threading::Value** vals);
        virtual bool DoSetBuf(bool enabled);
        virtual bool DoRotate(const char* rotated_path, double open, double close,
            bool terminating);
        virtual bool DoFlush(double network_time);
        virtual bool DoFinish(double network_time);
        virtual bool DoHeartbeat(double network_time, double current_time);

    private:
        // values defined within 'bro-space'; must match kafka.bif, scripts/init.bro
        string kafka_broker_list;
        string topic_name;
        int max_wait_on_delivery;

        // other
        Formatter* formatter;
        RdKafka::Producer* producer;
        RdKafka::Topic* topic;
        RdKafka::Conf* conf;
        RdKafka::Conf* topic_conf;
    };
}
}

#endif
