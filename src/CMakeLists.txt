
add_executable(
	qm	
	main.cpp
	wave_function.cpp
	)
add_executable(
	test
	test.cpp
	wave_function.cpp
)	

target_link_libraries(
	qm
	PRIVATE
	GSL::gsl
	GSL::gslcblas
)
target_link_libraries(
	test
	PRIVATE
	GSL::gsl
	GSL::gslcblas
)


