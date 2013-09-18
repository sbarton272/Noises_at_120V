/* Hybrid Instruments
 	Demo
 	Fall 2013
 	Spencer Barton
 */

#include "Noises_at_120V.h"

/*====== Global Vars, Defines ============*/

// devices
Device fan 	= { 
  9, 1, LOW};
Device bulb 	= { 
  8, 2, LOW};
Device vaccum	= { 
  6, 3, LOW};
Device radio	= { 
  7, 4, LOW};
Device sewMach	= { 
  4, 5, LOW};

const int NUM_DEVICES = 5;
Device DEVICES[NUM_DEVICES] = {
  fan, bulb, vaccum, radio, sewMach};

// counter variable, unsigned to allow wrap around without sign change
unsigned counter = 0;

void setup() {

  // set all pins to output
  for(unsigned i = 0; i < NUM_DEVICES; i++) {
    pinMode(DEVICES[i].pin, OUTPUT);
  }

}

void loop() {

  // determine pin states
  for(unsigned i = 0; i < NUM_DEVICES; i++) {
    toggleState(DEVICES[i]);
  }

  // set output to pin state
  for(unsigned i = 0; i < NUM_DEVICES; i++) {
    pinMode(DEVICES[i].pin, DEVICES[i].state);
  }


  // iterate count each loop, overflow does not matter because using modular arith.
  counter++;

}

/* toggleState(Device d)
 	Takes device and compares its counter to the global counter
 	if counter% count is zero then the state of the device toggles
 */
void toggleState(Device d) {

  if( (counter % d.counter) == 0) {

    // switch state
    if( d.state == LOW ) {
      d.state = HIGH;
    } 
    else {
      d.state = LOW;
    }
  }
}

