/*
	UVASD.h - Library for interfacing with SPI SD card readers
*/
#ifndef CSVwriter_h
#define CSVwriter_h

#include "Arduino.h"
#include <SPI.h>
#include <SD.h>

class CSVWriter{
	public:
		/**
		*	Creates a new CSVWriter with the CS pin initialized to a specific CSpin
		* @param CSpin the digital pin to be connected to the Chip Select
		* (or slave select) port of the SD card reader
		*/
		CSVWriter(int CSpin);

		/**
		* Writes a string (with a concatenated comma) to a the file given
		* by aFileName. Note: all data will be saved to a single column.
		* @param aFileName The name (or directory) to the csv file to be written to
		* @param dataString The data to be recorded into the CSV file
		*/
		void writeToCSV(String aFileName, String dataString);

		/**
		*	Checks to see if the file given by the parameter exists
		* if it does not exist, it is created. If it does already
		* exist, nothing is modified.
		*	@param aFileName The name (or directory) to the csv file to be written to
		* @return True if the file previously did not exist and was created,
		* False if the file already existed and no new file was created
		*/
		bool createFile(String aFilename);

	private:
		File myFile; // To be used in writeToCSV and createFile
};

#endif
