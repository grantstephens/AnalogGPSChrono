# AnalogGPSChrono fork

This is a forked version that uses the [NeoGPS](https://github.com/SlashDevin/NeoGPS) library to obtain the speed from the GPRMC sentence:

* Program size is only 3800 bytes (3180 bytes smaller!)
* It only uses 137 bytes of RAM (214 bytes saved!)
* Added low-pass filter to gpsFunctions
* NeoGPS configuration files are set to parse RMC and speed field *ONLY* (much faster).  Also configured for IMPLICIT merging and no extra fix structures.
