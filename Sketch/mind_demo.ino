#include <FastLED.h>
#include <Tone.h>

#define LEDPIN          4
#define LeftAudioPIN    5
#define RightAudioPIN   6

Tone LeftAudio;
Tone RightAudio;

#define NUM_LEDS    2
#define BRIGHTNESS  25
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];

#define BRAIN_WAVE 9 //9Hz Alpha Wave
int half_period;

void setup()
{
    float RightTone = 440.0 - (BRAIN_WAVE/2);
    float LeftTone = 440.0 + (BRAIN_WAVE/2);
    LeftAudio.begin(LeftAudioPIN);
    RightAudio.begin(RightAudioPIN);
    LeftAudio.play(LeftTone);
    RightAudio.play(RightTone);

    delay( 2000 ); // power-up safety delay
    FastLED.addLeds<LED_TYPE, LEDPIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.setBrightness( BRIGHTNESS );

    half_period = (int) (500.0 / (float) BRAIN_WAVE);
}

void loop()
{
    leds[0] = CRGB::Green;
    leds[1] = CRGB::Green;
    FastLED.show();
    delay(half_period);
    leds[0] = CRGB::Black;
    leds[1] = CRGB::Black;
    FastLED.show();
    delay(half_period);
}
