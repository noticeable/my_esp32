deps_config := \
	/home/li/esp32/esp-idf/components/app_trace/Kconfig \
	/home/li/esp32/esp-idf/components/aws_iot/Kconfig \
	/home/li/esp32/esp-idf/components/bt/Kconfig \
	/home/li/esp32/esp-idf/components/esp32/Kconfig \
	/home/li/esp32/esp-idf/components/ethernet/Kconfig \
	/home/li/esp32/esp-idf/components/fatfs/Kconfig \
	/home/li/esp32/esp-idf/components/freertos/Kconfig \
	/home/li/esp32/esp-idf/components/heap/Kconfig \
	/home/li/esp32/esp-idf/components/log/Kconfig \
	/home/li/esp32/esp-idf/components/lwip/Kconfig \
	/home/li/esp32/esp-idf/components/mbedtls/Kconfig \
	/home/li/esp32/esp-idf/components/openssl/Kconfig \
	/home/li/esp32/esp-idf/components/pthread/Kconfig \
	/home/li/esp32/esp-idf/components/spi_flash/Kconfig \
	/home/li/esp32/esp-idf/components/spiffs/Kconfig \
	/home/li/esp32/esp-idf/components/tcpip_adapter/Kconfig \
	/home/li/esp32/esp-idf/components/wear_levelling/Kconfig \
	/home/li/esp32/esp-idf/components/bootloader/Kconfig.projbuild \
	/home/li/esp32/workspace/camera/components/camera/Kconfig.projbuild \
	/home/li/esp32/esp-idf/components/esptool_py/Kconfig.projbuild \
	/home/li/esp32/esp-idf/components/partition_table/Kconfig.projbuild \
	/home/li/esp32/esp-idf/Kconfig

include/config/auto.conf: \
	$(deps_config)


$(deps_config): ;
