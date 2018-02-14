#pragma once
#include <obs-module.h>
#include <obs-hotkey.h>
#include <stdio.h>
#include "RtMidi.h"

#define blog(level, msg, ...) blog(level, "obs-midi: " msg, ##__VA_ARGS__)

OBS_HOTKEY(MIDI_CH_0)

OBS_DECLARE_MODULE()
OBS_MODULE_USE_DEFAULT_LOCALE("obs-midi", "en-US")

RtMidiIn *midiin = NULL;
RtMidiOut *midiout = NULL;

/*****************************************************************************/
void process_midi(double deltatime, std::vector< unsigned char > *message, void *userData)
{
	unsigned int = nBytes = message->size();
	for( unsigned int i=0; i<nBytes; i++ ){
		blog(LOG_INFO, "MIDI Byte %i", (int)message->at(i));
	}
	if( nBytes > 0 ){
		blog(LOG_INFO, "Stamp %f", deltatime);
	}
}

/*****************************************************************************/
bool obs_module_load(void)
{
	try {
		midiin = new RtMidiIn();
	} catch ( RtMidiError &error ) {
		error.printMessage();
		blog(LOG_WARNING, "error caught in: %s", __FUNCTION__);
		blog(LOG_INFO, "error number %i\n", e.getType());
		blog(LOG_INFO, "%s\n", e.getMessage().c_str());
	}
	std::string portName;
	
	unsigned int nPorts = midiin->getPortCount();
	blog(LOG_INFO, "Midi Inputs %i", nPorts);
	for( unsigned int i = 0; i < nPorts; i++ ){
		try {
			portName = midiin->getPortName(i);
		} catch ( RtMidiError &error ){
			error.printMessage();
			blog(LOG_WARNING, "error caught in: %s", __FUNCTION__);
			blog(LOG_INFO, "error number %i\n", e.getType());
			blog(LOG_INFO, "%s\n", e.getMessage().c_str());
			goto cleanup;
		}
		blog(LOG_INFO, "Input Port %i: [%s]", i, portName);
	}
	
	try {
		midiout = new RtMidiOut();
	} catch ( RtMidiError &error ) {
		error.printMessage();
		blog(LOG_WARNING, "error caught in: %s", __FUNCTION__);
		blog(LOG_INFO, "error number %i\n", e.getType());
		blog(LOG_INFO, "%s\n", e.getMessage().c_str());
		goto cleanup;
	}
	
	unsigned int nPorts = midiout->getPortCount();
	blog(LOG_INFO, "Midi Outputs %i", nPorts);
	for(unsigned int i = 0; i < nPorts; i++ ){
		try {
			portName = midiout->getPortName(i);
		} catch ( RtMidiError &error ){
			error.printMessage();
			blog(LOG_WARNING, "error caught in: %s", __FUNCTION__);
			blog(LOG_INFO, "error number %i\n", e.getType());
			blog(LOG_INFO, "%s\n", e.getMessage().c_str());
			goto cleanup;
		}
		blog(LOG_INFO, "Output Port %i: [%s]", i, portName);
	}
	
cleanup:
	return;
}

/*****************************************************************************/
void obs_module_post_load(void){
	
}

/*****************************************************************************/
void obs_module_unload(){
	if(midiin){
		delete midiin;
	}
	if(midiout){
		delete midiout;
	}
}