# CMake to build libraries and binaries in fboss/agent/hw/bcm

# In general, libraries and binaries in fboss/foo/bar are built by
# cmake/FooBar.cmake

add_executable(bcm_ecmp_shrink_speed /dev/null)

target_link_libraries(bcm_ecmp_shrink_speed
  -Wl,--whole-archive
  bcm
  config
  bcm_switch_ensemble
  config_factory
  hw_ecmp_shrink_speed
  bcm_ecmp_utils
  bcm_port_utils
  -Wl,--no-whole-archive
  hw_benchmark_main
  ${OPENNSA}
  Folly::folly
  Folly::follybenchmark
)

add_executable(bcm_ecmp_shrink_with_competing_route_updates_speed /dev/null)

target_link_libraries(bcm_ecmp_shrink_with_competing_route_updates_speed
  -Wl,--whole-archive
  bcm
  config
  bcm_switch_ensemble
  config_factory
  hw_ecmp_shrink_with_competing_route_updates_speed
  bcm_ecmp_utils
  bcm_port_utils
  -Wl,--no-whole-archive
  hw_benchmark_main
  ${OPENNSA}
  Folly::folly
  Folly::follybenchmark
)

add_executable(bcm_fsw_scale_route_add_speed /dev/null)

target_link_libraries(bcm_fsw_scale_route_add_speed
  -Wl,--whole-archive
  bcm
  config
  bcm_switch_ensemble
  config_factory
  hw_fsw_scale_route_add_speed
  route_scale_gen
  -Wl,--no-whole-archive
  hw_benchmark_main
  Folly::folly
  ${OPENNSA}
  Folly::follybenchmark
)

add_executable(bcm_fsw_scale_route_del_speed /dev/null)

target_link_libraries(bcm_fsw_scale_route_del_speed
  -Wl,--whole-archive
  bcm
  config
  bcm_switch_ensemble
  config_factory
  hw_fsw_scale_route_del_speed
  route_scale_gen
  -Wl,--no-whole-archive
  hw_benchmark_main
  Folly::folly
  ${OPENNSA}
  Folly::follybenchmark
)

add_executable(bcm_th_alpm_scale_route_add_speed /dev/null)

target_link_libraries(bcm_th_alpm_scale_route_add_speed
  -Wl,--whole-archive
  bcm
  config
  bcm_switch_ensemble
  config_factory
  hw_th_alpm_scale_route_add_speed
  route_scale_gen
  -Wl,--no-whole-archive
  hw_benchmark_main
  Folly::folly
  ${OPENNSA}
  Folly::follybenchmark
)

add_executable(bcm_th_alpm_scale_route_del_speed /dev/null)

target_link_libraries(bcm_th_alpm_scale_route_del_speed
  -Wl,--whole-archive
  bcm
  config
  bcm_switch_ensemble
  config_factory
  hw_th_alpm_scale_route_del_speed
  route_scale_gen
  -Wl,--no-whole-archive
  hw_benchmark_main
  Folly::folly
  ${OPENNSA}
  Folly::follybenchmark
)

add_executable(bcm_hgrid_du_scale_route_add_speed /dev/null)

target_link_libraries(bcm_hgrid_du_scale_route_add_speed
  -Wl,--whole-archive
  bcm
  config
  bcm_switch_ensemble
  config_factory
  hw_hgrid_du_scale_route_add_speed
  route_scale_gen
  -Wl,--no-whole-archive
  hw_benchmark_main
  Folly::folly
  ${OPENNSA}
  Folly::follybenchmark
)

add_executable(bcm_hgrid_du_scale_route_del_speed /dev/null)

target_link_libraries(bcm_hgrid_du_scale_route_del_speed
  -Wl,--whole-archive
  bcm
  config
  bcm_switch_ensemble
  config_factory
  hw_hgrid_du_scale_route_del_speed
  route_scale_gen
  -Wl,--no-whole-archive
  hw_benchmark_main
  Folly::folly
  ${OPENNSA}
  Folly::follybenchmark
)

add_executable(bcm_hgrid_uu_scale_route_add_speed /dev/null)

target_link_libraries(bcm_hgrid_uu_scale_route_add_speed
  -Wl,--whole-archive
  bcm
  config
  bcm_switch_ensemble
  config_factory
  hw_hgrid_uu_scale_route_add_speed
  route_scale_gen
  -Wl,--no-whole-archive
  hw_benchmark_main
  Folly::folly
  ${OPENNSA}
  Folly::follybenchmark
)

add_executable(bcm_hgrid_uu_scale_route_del_speed /dev/null)

target_link_libraries(bcm_hgrid_uu_scale_route_del_speed
  -Wl,--whole-archive
  bcm
  config
  bcm_switch_ensemble
  config_factory
  hw_hgrid_uu_scale_route_del_speed
  route_scale_gen
  -Wl,--no-whole-archive
  hw_benchmark_main
  Folly::folly
  ${OPENNSA}
  Folly::follybenchmark
)

add_executable(bcm_stats_collection_speed /dev/null)

target_link_libraries(bcm_stats_collection_speed
  -Wl,--whole-archive
  bcm_switch_ensemble
  hw_stats_collection_speed
  -Wl,--no-whole-archive
)

add_executable(bcm_tx_slow_path_rate /dev/null)

target_link_libraries(bcm_tx_slow_path_rate
  -Wl,--whole-archive
  bcm_switch_ensemble
  hw_tx_slow_path_rate
  -Wl,--no-whole-archive
)

add_executable(bcm_warm_boot_exit_speed /dev/null)

target_link_libraries(bcm_warm_boot_exit_speed
  -Wl,--whole-archive
  bcm_switch_ensemble
  hw_warm_boot_exit_speed
  -Wl,--no-whole-archive
)

add_executable(bcm_rx_slow_path_rate /dev/null)

target_link_libraries(bcm_rx_slow_path_rate
  -Wl,--whole-archive
  bcm_switch_ensemble
  hw_tx_slow_path_rate
  bcm_copp_utils
  bcm_qos_utils
  bcm_packet_trap_helper
  -Wl,--no-whole-archive
)

add_executable(bcm_init_to_config_40Gx10G /dev/null)

target_link_libraries(bcm_init_to_config_40Gx10G
  -Wl,--whole-archive
  bcm_switch_ensemble
  config_factory
  hw_init_to_config_40Gx10G
  -Wl,--no-whole-archive
)

add_executable(bcm_init_to_config_100Gx10G /dev/null)

target_link_libraries(bcm_init_to_config_100Gx10G
  -Wl,--whole-archive
  bcm_switch_ensemble
  config_factory
  hw_init_to_config_100Gx10G
  -Wl,--no-whole-archive
)

add_executable(bcm_init_to_config_100Gx25G /dev/null)

target_link_libraries(bcm_init_to_config_100Gx25G
  -Wl,--whole-archive
  bcm_switch_ensemble
  config_factory
  hw_init_to_config_100Gx25G
  -Wl,--no-whole-archive
)

add_executable(bcm_init_to_config_100Gx50G /dev/null)

target_link_libraries(bcm_init_to_config_100Gx50G
  -Wl,--whole-archive
  bcm_switch_ensemble
  config_factory
  hw_init_to_config_100Gx50G
  -Wl,--no-whole-archive
)

add_executable(bcm_init_to_config_100Gx100G /dev/null)

target_link_libraries(bcm_init_to_config_100Gx100G
  -Wl,--whole-archive
  bcm_switch_ensemble
  config_factory
  hw_init_to_config_100Gx100G
  -Wl,--no-whole-archive
)

install(TARGETS bcm_ecmp_shrink_speed)
install(TARGETS bcm_ecmp_shrink_with_competing_route_updates_speed)
install(TARGETS bcm_fsw_scale_route_add_speed)
install(TARGETS bcm_fsw_scale_route_del_speed)
install(TARGETS bcm_th_alpm_scale_route_add_speed)
install(TARGETS bcm_th_alpm_scale_route_del_speed)
install(TARGETS bcm_hgrid_du_scale_route_add_speed)
install(TARGETS bcm_hgrid_du_scale_route_del_speed)
install(TARGETS bcm_hgrid_uu_scale_route_add_speed)
install(TARGETS bcm_hgrid_uu_scale_route_del_speed)
install(TARGETS bcm_stats_collection_speed)
install(TARGETS bcm_tx_slow_path_rate)
install(TARGETS bcm_warm_boot_exit_speed)
install(TARGETS bcm_rx_slow_path_rate)
install(TARGETS bcm_init_to_config_40Gx10G)
install(TARGETS bcm_init_to_config_100Gx10G)
install(TARGETS bcm_init_to_config_100Gx25G)
install(TARGETS bcm_init_to_config_100Gx50G)
install(TARGETS bcm_init_to_config_100Gx100G)
