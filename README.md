# IPMIManager

Welcome to IPMI Manager, an experimental and educational project for spare time.

## Building

To install IPMI Manager, follow these steps:

Before installation ensure you have following dependencies: CMake, ipmitool

1. Clone the repository:


```bash
git clone https://github.com/lilxandrias/ipmimanager
```

2. Navigate to the project directory


```bash
cd ipmimanager
```

3. Create a build directory


```bash
mkdir build
```

4. Navigate to the build directory


```bash
cd build
```

5. Run CMake to configure the project:


```bash
cmake ..
```

6. Build the project


```bash
make
```

7. Execute IPMIManager


```bash
./ipmimanager
```

## What works?

- [x] Power commands: status, on, off, cycle, reset, diag, soft

- [x] Sensor commands: reading sensor data inside program

- [x] Password authentication with option to save credentials

- [ ] Option to specify local IPMI device

- [ ] Option to choose Interface

- [ ] Option to specify RMCP port

- [ ] Option to change size of communication channel (OEM)

- [ ] Option to use only IPv4

- [ ] Option to use only IPv6

- [ ] IPMIv2 Authentication

- [ ] Option to choose authentication type

- [ ] Option to set privilege level

- [ ] Option to set local IPMB address

- [ ] Option to set destination channel for bridged request (dual bridge)

- [ ] Option to set transit address for bridge request (dual bridge)

- [ ] Option to set destination lun for raw commands

- [ ] Option to setup for OEM

- [ ] Option to use file for OEM SEL event descriptions

- [ ] Option to specify timeout

- [ ] Option to set number of retries for lan/lanplus interface

- [ ] Option to display all dates in UTC

- [ ] Option to send RAW IPMI requests and prompt response

- [ ] Option to send i2c commands and print responses

- [ ] Option to print spd info from remote I2C device

- [ ] Option to configure LAN channels

- [ ] Option to get chassis status and set power state

- [ ] Option to send pre-defined events to MC

- [ ] Option to print Sensor Data Repository entries and readings

- [ ] Option to print built-in FRU and scan SDR for FRU locators

- [ ] Option to Read/Write Device associated with Generic Device locators sdr

- [ ] Option to print system event log (SEL)

- [ ] Option to configure Platform Event Filtering (PEF)

- [ ] Option to configure and connect IPMIv2.0 Serial-over-LAN

- [ ] Option to configure and connect with Tyan IPMIv1.5 Serial-over-LAN

- [ ] Option to configure IPMIv1.5 Serial-over-LAN

- [ ] Option to configure management controller users

- [ ] Option to configure management controller channels

- [ ] Option to print session information

- [ ] Option to use Data Center Management Interface

- [ ] Option to use Node Manager Interface

- [ ] Option to enter OEM Commands for Sun servers

- [ ] Option to enter OEM Commands for Kontron devices

- [ ] Option to Run a PICMG/ATCA exetended cmd

- [ ] Option to update IPMC using Kontron OEM Firmware Update Manager

- [ ] Option to configure firmware firewall

- [ ] Option to enter OEM Commands for Dell sytems

- [ ] Option to launch interactive IPMI shell

- [ ] Option to run list of commands from file

- [ ] Option to set runtime variables for shell and exec

- [ ] Option to update HPM components using PICMG HPM.1 file

- [ ] Option to run FRU-EKeyring analyzer using FRU files

- [ ] Option to update Intel Manageability Engine Firmware

- [ ] Option to run a VITA 46.11 extended cmd

- [ ] Option to configure IPv6 LAN channels


## License

This project is licensed under the terms of the MIT License. See the [LICENSE](https://github.com/lilxandrias/ipmimanager/blob/main/LICENSE) file for details.
