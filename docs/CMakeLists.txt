
# Doxygen

# look for Doxygen package
find_package(Doxygen)

if (DOXYGEN_FOUND)
    # set input and output files
    set(DOXYGEN_INPUT_DIR ${PROJECT_SOURCE_DIR}/src)
    set(DOXYGEN_OUTPUT_DIR ${PROJECT_BINARY_DIR}/docs/doxygen)
    set(DOXYGEN_INDEX_FILE ${DOXYGEN_OUTPUT_DIR}/xml/index.xml)
    set(DOXYFILE_IN ${PROJECT_SOURCE_DIR}/docs/Doxyfile.in)
    set(DOXYFILE_OUT ${PROJECT_BINARY_DIR}/Doxyfile.out)

    # Replace variables inside @@ with the current values
    configure_file(${DOXYFILE_IN} ${DOXYFILE_OUT} @ONLY)

    file(MAKE_DIRECTORY ${DOXYGEN_OUTPUT_DIR}) #Doxygen won't create this for us
    add_custom_command(OUTPUT ${DOXYGEN_INDEX_FILE}
                       DEPENDS ${lsysgen_BASE_HEADERS}
                       COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYFILE_OUT}
                       MAIN_DEPENDENCY ${DOXYFILE_OUT} ${DOXYFILE_IN}
                       COMMENT "Generating docs")

    # Note: do not put "ALL" - this builds docs together with application EVERY TIME!
    add_custom_target(doxygen # ALL 
                      DEPENDS ${DOXYGEN_INDEX_FILE})

    # # request to configure the file
    # configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    # message("Doxygen build started")

    # # Note: do not put "ALL" - this builds docs together with application EVERY TIME!
    # add_custom_target(doxygen
    #     COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
    #     WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
    #     COMMENT "Generating API documentation with Doxygen"
    #     VERBATIM)
else (DOXYGEN_FOUND)
  message("Doxygen needs to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)

# Sphinx

# find_package(Sphinx)

# if (SPHINX_FOUND)
#   set(SPHINX_SOURCE ${PROJECT_SOURCE_DIR}/docs)
#   set(SPHINX_BUILD ${PROJECT_BINARY_DIR}/docs/sphinx)
#   set(SPHINX_INDEX_FILE ${SPHINX_BUILD}/index.html)

#   # Only regenerate Sphinx when:
#   # - Doxygen has rerun
#   # - Our doc files have been updated
#   # - The Sphinx config has been updated
#   add_custom_command(OUTPUT ${SPHINX_INDEX_FILE}
#                     COMMAND 
#                       ${SPHINX_EXECUTABLE} -b html
#                       # Tell Breathe where to find the Doxygen output
#                       -Dbreathe_projects.LSysGen=${DOXYGEN_OUTPUT_DIR}/xml
#                       ${SPHINX_SOURCE} ${SPHINX_BUILD}
#                     WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
#                     DEPENDS
#                       # Other docs files you want to track should go here (or in some variable)
#                       ${PROJECT_SOURCE_DIR}/docs/index.rst
#                       ${DOXYGEN_INDEX_FILE}
#                     MAIN_DEPENDENCY ${SPHINX_SOURCE}/conf.py
#                     COMMENT "Generating documentation with Sphinx")

#   # Nice named target so we can run the job easily
#   add_custom_target(sphinx # ALL
#                     DEPENDS ${SPHINX_INDEX_FILE})

#   # Add an install target to install the docs
#   # include(GNUInstallDirs)
#   # install(DIRECTORY ${SPHINX_BUILD}
#   #     DESTINATION ${CMAKE_INSTALL_DOCDIR})
# else (SPHINX_FOUND)
#   message("Sphinx need to be installed to style the doxygen documentation")
# endif (SPHINX_FOUND)
