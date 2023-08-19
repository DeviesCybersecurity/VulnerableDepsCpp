# VulnerableDepsCpp
This is a project to test Software Composition Analysis Tools, see if they can find the dependencies and identify vulnerabilities.

It has currently been scanned by:
* Snyk

Todo:
* Blackduck
* https://cyclonedx.org
* Google OSV (when they support C++)
...

Scanners which will not work
* https://github.com/anchore/syft requires Conan
* Gitlab requires Conan
* Google OSV does not have support for C++ at the time of the first release 
Rex Pan, software engineer at Google, shared some details on what is next for OSV-Scanner. The team is looking to offer a standalone CI action to enable further integration into workflows. Pan shared that they are looking to improve C and C++ support by "building a high quality database of C/C++ vulnerabilities by adding precise commit level metadata to CVEs."

Not researched:
* Veracode Software Composition Analysis - https://docs.veracode.com/r/c_sc_ccpp

This project is not actually intended to be built and run, but it at least builds on some platforms

Notes:
* CMAKE_SOURCE_DIR was changed to PROJECT_SOURCE_DIR in all CMakeList.txt in Poco. The included version of Poco uses CMAKE_SOURCE_DIR instead of PROJECT_SOURCE_DIR to find DLLVersion.rc and this causes Cmake to search for the file in the root directory of the CMakeList.txt that included Poco rather than the Poco root directory. This is fixed in later versions of Poco, but we want this version since it has a vulnerability. 
* Snyk is not able to detect Nlohmman Json-library at all. It is downloaded by Cmake when building so I'd expect Snyk to find it after Cmake-build.
* Snyk will detect Mosquitto as a dependency, even if it is not included in the build. As expected since Snyk only scans the source files in the directories and do not know what is actually included the build.
* If a directory does not contain any identified dependencies it will just output : "Errors Could not test dependencies in C:\Dev\Vulnerable\build"


Instructions:
The intention is to try SCA and vulnerability scanning tools and not to actually build the project.

Snyk : just run snyk CLI in the root directory. E.g. snyk-win test --unmanaged