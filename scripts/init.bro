module Kafka;

export {

	#
	# the kafka broker(s) to which data will be sent
	#
	const kafka_broker_list: string = "localhost:9092" &redef;

	#
	# the name of the kafka topic
	#
	const topic_name: string = "bro" &redef;

	#
	# the maximum amount of time in milliseconds to wait for
	# kafka message delivery upon shutdown
	#
	const max_wait_on_delivery: count = 3000 &redef;
}
