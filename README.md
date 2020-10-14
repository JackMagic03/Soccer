# Soccer

Per installare correttamente il codice: 
- installare sul pc PlatformIO su Atom o vscode;
- Creare un progetto vuoto in un'altra cartella;
- Importare i file e le librerie dalla repository alle cartelle del progetto;

## Installation guide
To compile and upload the Soccer firmware, you need to check out a few things.

- Install lastest [_Arduino IDE_](https://www.arduino.cc/en/Main/Software) Software (min 1.8.13) 
- Download this repository. __In a linux terminal__

	git clone https://github.com/MassimoGiordano03/Soccer.git
	

- Enter in the freshly cloned repo and initialize it via the _init.sh_ script:
	
	cd Soccer/
	./init.sh

- Assuming no errors occurred, you can finally compile and upload the firmware through the _scripts/upload.sh_ script:

	./scripts/upload.sh

- If you want to have more control on compile and upload procedures, you can manually set them up:

	./scripts/clean.sh
	./scripts/run.sh
	cd build
	make upload-<my_exec> SERIAL_PORT=<com_port>
	
Where <my_exec> is by default _firmware_ and <com_port> is _/dev/ttyACM0_.

## Script List
The _scripts/_ folder contains a set of useful scripts:

-__run.sh__ : Generates the build folder and compile the project.
-__upload.sh__ : Same as _run.sh_ but also uploads the firmware into a Mega2560 (if available)
-__clean.sh__ : Removes the build files
