# VulnerableDepsCpp
This is a project to test Software Composition Analysis Tools, see if they can find the dependencies and identify vulnerabilities.

This project is not actually intended to be built and run, but it at least builds on some platforms

Notes:
* CMAKE_SOURCE_DIR was changed to PROJECT_SOURCE_DIR in all CMakeList.txt in Poco. The included version of Poco uses CMAKE_SOURCE_DIR instead of PROJECT_SOURCE_DIR to find DLLVersion.rc and this causes Cmake to search for the file in the root directory of the CMakeList.txt that included Poco rather than the Poco root directory. This is fixed in later versions of Poco, but we want this version since it has a vulnerability. 
* Snyk is not able to detect Nlohmman Json-library at all. It is downloaded by Cmake when building so I'd expect Snyk to find it after Cmake-build.
* Snyk will detect Mosquitto as a dependency, even if it is not included in the build. As expected since Snyk only scans the source files in the directories and do not know what is actually included the build.
* If a directory does not contain any identified dependencies it will just output : "Errors Could not test dependencies in C:\Dev\Vulnerable\build"