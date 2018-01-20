AC_INIT([<project_name>], [0.1], [youremail@some.local])

m4_include([m4/ax_gnu_autotest.m4])
m4_include([m4/ax_boost_base.m4])
m4_include([m4/ax_boost_unit_test_framework.m4])

AC_PREREQ([2.59])
AC_CONFIG_AUX_DIR(config)
AM_INIT_AUTOMAKE([foreign -Wall -Werror])
AC_PROG_CXX
AC_PROG_CC
AX_BOOST_BASE([1.58])
AX_BOOST_UNIT_TEST_FRAMEWORK
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile src/Makefile t/Makefile])
AC_OUTPUT
