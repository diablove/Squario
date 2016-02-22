#include <SPI.h>

#define CLK		15
#define MOSI	16
#define CS		12
#define DC		4
#define RST		6

class Arduboy {
	public:
		Arduboy();
		uint8_t getInput();
		void start();
		void blank();
		
		void drawTile(int x, int _y, const unsigned char *image);
		void drawTile(int x, int _y, unsigned char image[]);
		void drawSprite(int x, int y, const unsigned char *image, uint8_t frame);

		void scrollLeft();

		private:
		uint8_t readCapacitivePin(int pinToMeasure);
		uint8_t readCapXtal(int pinToMeasure);
		volatile uint8_t *mosiport, *clkport, *csport, *dcport;
		uint8_t mosipinmask, clkpinmask, cspinmask, dcpinmask;
		bool scrolling;
};
