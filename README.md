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