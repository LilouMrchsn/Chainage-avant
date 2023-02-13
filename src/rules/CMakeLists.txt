set(CMAKE_INSTALL_RPATH_USE_LINK_PATH true)
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")

add_library(rules SHARED rules.c app.c rules.h rules.inc)

add_executable(app app.c)
add_dependencies(app rules)
target_link_libraries(app rules)

configure_file(
	${CMAKE_CURRENT_SOURCE_DIR}/rules.pc.in
	${CMAKE_CURRENT_BINARY_DIR}/rules.pc
	@ONLY
)
install(
	FILES ${CMAKE_CURRENT_BINARY_DIR}/rules.pc
	DESTINATION share/pkgconfig
	COMPONENT "PkgConfig"
)

include(CMakePackageConfigHelpers)
configure_package_config_file(
	${CMAKE_CURRENT_SOURCE_DIR}/RulesConfig.cmake.in
	${CMAKE_CURRENT_BINARY_DIR}/RulesConfig.cmake
	INSTALL_DESTINATION cmake
)
install(
	FILES ${CMAKE_CURRENT_BINARY_DIR}/RulesConfig.cmake
	DESTINATION cmake
)

install(
	TARGETS rules app
	LIBRARY DESTINATION lib COMPONENT "Library"
	ARCHIVE DESTINATION lib COMPONENT "Library"
	RUNTIME DESTINATION bin COMPONENT "Runtime"
)

install(
	FILES rules.h
	DESTINATION include
	COMPONENT "Header"
)

find_package(Coverage)
enable_coverage()

find_package(HtmlCoverage)
enable_html_coverage()

