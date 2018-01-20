# <project_name>

## NAME

<project_name>

## VERSION

0.0.1

## SINOPSYS

git clone https://github.com/rfilipo/cpp_skel.git myNewCppProject

cd myNewCppProject

grep -rli '<project_name>' * | xargs -i@ sed -i "s/<project_name>/myNewCppProject/g" @

autoreconf --install
./configure --with-boost --with-boost-unit-test-framework
make check

## DESCRIPTION

Simple skeleton for a cpp autotolls TDD project with basic boost support

If you have a non trivial boost instalation, don't forget to export the BOOST_HOME environment variable.

Use autotools to configure, build, test and install.

## SEE ALSO

- autotools
https://en.wikipedia.org/wiki/GNU_Build_System
https://autotools.io/index.html
https://www.gnu.org/software/autoconf/autoconf.html

- Boost 
http://www.boost.org
http://www.boost.org/doc/libs/1_66_0/libs/test/doc/html/index.html

- Windows:
http://gnuwin32.sourceforge.net/packages/autoconf.htm
