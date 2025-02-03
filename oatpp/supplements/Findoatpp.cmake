set(oatpp_FOUND True)
set(oatpp_INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/include/oatpp-1.3.0/oatpp")
set(oatpp_LIBRARY ":liboatpp.lib.so")
set(oatpp_LIBRARIES "$${oatpp_LIBRARY}")
add_library(oatpp::oatpp INTERFACE IMPORTED)
set_target_properties(oatpp::oatpp PROPERTIES
	INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_LIST_DIR}/include/oatpp-1.3.0/oatpp")
