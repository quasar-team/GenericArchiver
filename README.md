###### Generic Archiver for Quasar ######

This repository hosts a Generic Archiver for Quasar.

[Quasar](https://github.com/quasar-team/quasar): Quick OPC-UA Server Generation Framework, is a software framework used at CERN (and beyond) to create OPC-UA servers.

The Generic Archiver, with an obligatory specific archiver, provides data logging functionality for Quasar Servers. Data logging can be used to:

* provide historic access to the OPC-UA clients,
* deliver quality mechanism to debug, test and development of OPC-UA servers based in quasar,
* deliver persistency

The Generic Archiver is just an interface in the C++ programming language. Specific Archivers implement this interface and provide factual data logging into a data-base, a file, etc. As of June 2017, the only known Specific Archiver is the [https://github.com/quasar-team/InfluxDbArchiver](InfluxDb Archiver).

The Generic Archiver is organized as a Quasar Optional Module (look at Quasar docs).
 
### How to use it? ###

First of all, data logging in Quasar requires both the Generic Archiver and the Specific Implementation, say, the InfluxDB Archiver.

You need to enable both modules in your Quasar project:

```bash
./quasar.py enable_module GenericArchiver
./quasar.py enable_module InfluxDBArchiver   ( or any other Specific Archiver)
```

And you'll need to create and tear down the instance, both in Server/src/QuasarServer.cpp:

In QuasarServer constructor: (note that ignoring the return value from new is intentional)

```c++
new InfluxDbArchiver::InfluxDbArchiver("mydb");
```

In the QuasarServer destructor:

```c++
GenericArchiver::GenericArchiver::instance()->kill();
```

That's it! 

