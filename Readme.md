Working directory for our project at PennApps XV. 

Team Members: Derek Jones, Waverly Roeger, Andrew Boyan

## Inspiration
_Maximizing Free Cloud Storage!_

## What it does
RLCS is a mountable virtual drive for distributing, encrypting, and retrieving files across multiple cloud storage providers.

## How we built it

### Dependencies
```
Python Dropbox API
PyDrive
libfuse
ccrypt
python 2.7
gcc
```

## Challenges we ran into
We had trouble interfacing with the API's of the cloud storage providers and ended up only having time to support two (Google Drive and Dropbox).

Sleep Deprivation!


## Accomplishments that we're proud of
Getting a seemlessly integrated FUSE filesystem.

Successful integration of Python scripts into C++.

## What's next for RLCS
Adding _**functionality**_ including: remove files, retrieving amount of free/used space.

Adding _**cloud drives**_ including: OneDrive, Mega.

Implementing additional _**RAID storage algorithms**_.

Adding a _**user interface**_.
