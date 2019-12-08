#include <Arduino.h>

#define ANALOG_BUFFER_SIZE	1000
#define ADCPIN		5
volatile  uint8_t ADCBuffer[ANALOG_BUFFER_SIZE];
volatile  boolean freeze;
volatile uint16_t ADCCounter;



#ifndef cbi
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#endif
#ifndef sbi
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
#endif

ISR(ADC_vect)
{
    // When ADCL is read, the ADC Data Register is not updated until ADCH
    // is read. Consequently, if the result is left adjusted and no more
    // than 8-bit precision is required, it is sufficient to read ADCH.
    // Otherwise, ADCL must be read first, then ADCH.
    ADCBuffer[ADCCounter*2] = ADCL;
    ADCBuffer[ADCCounter*2+1] = ADCH;

    ADCCounter = ( ADCCounter + 1 ) % (ANALOG_BUFFER_SIZE / 2);

    if (ADCCounter == (ANALOG_BUFFER_SIZE/2) - 1) {
        cbi( ADCSRA, ADEN );
        freeze = true;
    }

}

void setup() {
    //Disable digital IO on ADC pins
    sbi(DIDR0,ADC5D);
    sbi(DIDR0,ADC4D);
    sbi(DIDR0,ADC3D);
    sbi(DIDR0,ADC2D);
    sbi(DIDR0,ADC1D);
    sbi(DIDR0,ADC0D);

    //shift values to make them 8 bits
    //sbi(ADMUX,ADLAR);

    //set ref to VCC
    cbi(ADMUX,REFS1);
    sbi(ADMUX,REFS0);

    //set ADC division factor
    sbi(ADCSRA,ADPS2);
    sbi(ADCSRA,ADPS1);
    sbi(ADCSRA,ADPS0);

    //select ADC pin
    ADMUX |= ( ADCPIN & 0x07 );

    //set free running mode
    cbi(ADCSRB,ADTS2);
    cbi(ADCSRB,ADTS1);
    cbi(ADCSRB,ADTS0);

    // When this bit is written to one and the I-bit in SREG is set, the
    // ADC Conversion Complete Interrupt is activated.
    sbi(ADCSRA,ADIE);

    ADCSRA |= (1 << ADATE); // Enable auto-triggering


    freeze = false;
    sbi( ADCSRA, ADEN );
    sbi(ADCSRA,ADSC);


    Serial.begin(115200);
}

void loop() {
    if (freeze) {
        //Serial.write("sync");
        Serial.write( (uint8_t *) &ADCBuffer, ANALOG_BUFFER_SIZE );

        freeze = false;
        sbi( ADCSRA, ADEN );
        sbi(ADCSRA,ADSC);

    }
}
