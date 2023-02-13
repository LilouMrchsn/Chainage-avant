Rules - Groupe N
==============

Installation
------------

Use ``brew`` and not ``apt`` if you are on macos!

.. code:: bash

   $ sudo apt install cmake gcc lcov cppcheck python-pip valgrind flawfinder doxygen graphviz
   $ git clone https://gitlab.univ-lr.fr/groupeN/noodle-chaining.git
   $ sudo pip install  -r c-test/docs/requirements.txt

Usage
-----

Compilation
~~~~~~~~~~~

.. code:: bash

   $ mkdir build
   $ cd build
   $ cmake ../noodle-chaining -DBUILD_COVERAGE=1 -DBUILD_HTML_COVERAGE=1 -DUSE_VALGRIND=1 -DRUN_CPPCHECK=1
   $ make

Run test and code coverage
~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code:: bash

   $ make test
   $ make coverage
   $ make html-coverage

Check style
~~~~~~~~~~~

.. code:: bash

   $ make cclint

Run flaw finder
~~~~~~~~~~~~~~~

.. code:: bash

   $ make flawfinder

Build the docs
~~~~~~~~~~~~~~

.. code:: bash

   $ make docs

Create archives
~~~~~~~~~~~~~~~

.. code:: bash

   $ make package
   $ make package_source

Install package
~~~~~~~~~~~~~~~

.. code:: bash

   $ make install


