#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/binary_info.h"
#include <string.h>

const uint PIN_DISPLAY_1 = 21;
const uint PIN_DISPLAY_2 = 20;
const uint PIN_DISPLAY_3 = 19;
const uint PIN_DISPLAY_4 = 18;

const uint PIN_SEG_A = 8;
const uint PIN_SEG_B = 9;
const uint PIN_SEG_C = 10;
const uint PIN_SEG_D = 11;
const uint PIN_SEG_E = 12;
const uint PIN_SEG_F = 13;
const uint PIN_SEG_G = 14;
const uint PIN_SEG_P = 15;



struct digit_key {
	char key[3];
	int hexval;
};

struct digit_key digit_keys[34] = {
			{"0",0x3f},
			{"1",0x06},
			{"2",0x5b},
			{"3",0x4f},
			{"4",0x66},
			{"5",0x6d},
			{"6",0x7d},
			{"7",0x07},
			{"8",0x7f},
			{"9",0x67},
			{"A",0x77},
			{"B",0x7c},
			{"C",0x39},
			{"D",0x5e},
			{"E",0x79},
			{"F",0x71},
			{" ",0x0},
			{"0.",0xBF},
			{"1.",0x86},
			{"2.",0xDB},
			{"3.",0xCF},
			{"4.",0xE6},
			{"5.",0xED},
			{"6.",0xFD},
			{"7.",0x87},
			{"8.",0xFF},
			{"9.",0xEF},
			{"A.",0xF7},
			{"B.",0xFC},
			{"C.",0xB9},
			{"D.",0xDE},
			{"E.",0xF9},
			{"F.",0xF1},
			{" .",0x80}
};

int main() {
	
	bi_decl(bi_program_description("This is a program to show temperature on 4 digits"));
	bi_decl(bi_4pins_with_names(PIN_DISPLAY_1, "Digit 1", PIN_DISPLAY_2, "Digit 2", PIN_DISPLAY_3, "Digit 3", PIN_DISPLAY_4, "Digit 4"));
	
	bi_decl(bi_pin_mask_with_name(0x3f << PIN_SEG_A , "0 - bit mask"));
	bi_decl(bi_pin_mask_with_name(0x06 << PIN_SEG_A , "1 - bit mask"));
	bi_decl(bi_pin_mask_with_name(0x5b << PIN_SEG_A , "2 - bit mask"));
	bi_decl(bi_pin_mask_with_name(0x4f << PIN_SEG_A , "3 - bit mask"));
	bi_decl(bi_pin_mask_with_name(0x66 << PIN_SEG_A , "4 - bit mask"));
	bi_decl(bi_pin_mask_with_name(0x6d << PIN_SEG_A , "5 - bit mask"));
	bi_decl(bi_pin_mask_with_name(0x7d << PIN_SEG_A , "6 - bit mask"));
	bi_decl(bi_pin_mask_with_name(0x07 << PIN_SEG_A , "7 - bit mask"));
	bi_decl(bi_pin_mask_with_name(0x7f << PIN_SEG_A , "8 - bit mask"));
	bi_decl(bi_pin_mask_with_name(0x67 << PIN_SEG_A , "9 - bit mask"));
	
	bi_decl(bi_pin_mask_with_name(0x77 << PIN_SEG_A , "A - bit mask"));
	bi_decl(bi_pin_mask_with_name(0x7c << PIN_SEG_A , "B - bit mask"));
	bi_decl(bi_pin_mask_with_name(0x39 << PIN_SEG_A , "C - bit mask"));
	bi_decl(bi_pin_mask_with_name(0x5e << PIN_SEG_A , "D - bit mask"));
	bi_decl(bi_pin_mask_with_name(0x79 << PIN_SEG_A , "E - bit mask"));
	bi_decl(bi_pin_mask_with_name(0x71 << PIN_SEG_A , "F - bit mask"));
	bi_decl(bi_pin_mask_with_name(0x0 << PIN_SEG_A , "(SPACE) - bit mask"));
	
	bi_decl(bi_pin_mask_with_name(0xBF << PIN_SEG_A , "0. - bit mask"));
	bi_decl(bi_pin_mask_with_name(0x86 << PIN_SEG_A , "1. - bit mask"));
	bi_decl(bi_pin_mask_with_name(0xDB << PIN_SEG_A , "2. - bit mask"));
	bi_decl(bi_pin_mask_with_name(0xCF << PIN_SEG_A , "3. - bit mask"));
	bi_decl(bi_pin_mask_with_name(0xE6 << PIN_SEG_A , "4. - bit mask"));
	bi_decl(bi_pin_mask_with_name(0xED << PIN_SEG_A , "5. - bit mask"));
	bi_decl(bi_pin_mask_with_name(0xFD << PIN_SEG_A , "6. - bit mask"));
	bi_decl(bi_pin_mask_with_name(0x87 << PIN_SEG_A , "7. - bit mask"));
	bi_decl(bi_pin_mask_with_name(0xFF << PIN_SEG_A , "8. - bit mask"));
	bi_decl(bi_pin_mask_with_name(0xEF << PIN_SEG_A , "9. - bit mask"));
	
	bi_decl(bi_pin_mask_with_name(0xF7 << PIN_SEG_A , "A. - bit mask"));
	bi_decl(bi_pin_mask_with_name(0xFC << PIN_SEG_A , "B. - bit mask"));
	bi_decl(bi_pin_mask_with_name(0xB9 << PIN_SEG_A , "C. - bit mask"));
	bi_decl(bi_pin_mask_with_name(0xDE << PIN_SEG_A , "D. - bit mask"));
	bi_decl(bi_pin_mask_with_name(0xF9 << PIN_SEG_A , "E. - bit mask"));
	bi_decl(bi_pin_mask_with_name(0xF1 << PIN_SEG_A , "F. - bit mask"));
	bi_decl(bi_pin_mask_with_name(0x80 << PIN_SEG_A , "(SPACE). - bit mask"));
	
	stdio_init_all();
	
	gpio_init(PIN_DISPLAY_1);
	gpio_set_dir(PIN_DISPLAY_1, GPIO_OUT);
	
	gpio_init(PIN_DISPLAY_2);
	gpio_set_dir(PIN_DISPLAY_2, GPIO_OUT);
	
	gpio_init(PIN_DISPLAY_3);
	gpio_set_dir(PIN_DISPLAY_3, GPIO_OUT);
	
	gpio_init(PIN_DISPLAY_4);
	gpio_set_dir(PIN_DISPLAY_4, GPIO_OUT);
	
	uint displays[4] = {PIN_DISPLAY_1, PIN_DISPLAY_2, PIN_DISPLAY_3, PIN_DISPLAY_4};
	
	gpio_init(PIN_SEG_A);
	gpio_set_dir(PIN_SEG_A, GPIO_OUT);
	gpio_set_outover(PIN_SEG_A, GPIO_OVERRIDE_INVERT);
	
	gpio_init(PIN_SEG_B);
	gpio_set_dir(PIN_SEG_B, GPIO_OUT);
	gpio_set_outover(PIN_SEG_B, GPIO_OVERRIDE_INVERT);
	
	gpio_init(PIN_SEG_C);
	gpio_set_dir(PIN_SEG_C, GPIO_OUT);
	gpio_set_outover(PIN_SEG_C, GPIO_OVERRIDE_INVERT);
	
	gpio_init(PIN_SEG_D);
	gpio_set_dir(PIN_SEG_D, GPIO_OUT);
	gpio_set_outover(PIN_SEG_D, GPIO_OVERRIDE_INVERT);
	
	gpio_init(PIN_SEG_E);
	gpio_set_dir(PIN_SEG_E, GPIO_OUT);
	gpio_set_outover(PIN_SEG_E, GPIO_OVERRIDE_INVERT);
	
	gpio_init(PIN_SEG_F);
	gpio_set_dir(PIN_SEG_F, GPIO_OUT);
	gpio_set_outover(PIN_SEG_F, GPIO_OVERRIDE_INVERT);
	
	gpio_init(PIN_SEG_G);
	gpio_set_dir(PIN_SEG_G, GPIO_OUT);
	gpio_set_outover(PIN_SEG_G, GPIO_OVERRIDE_INVERT);
	
	gpio_init(PIN_SEG_P);
	gpio_set_dir(PIN_SEG_P, GPIO_OUT);
	gpio_set_outover(PIN_SEG_P, GPIO_OVERRIDE_INVERT);
	
	
	
	
	while (1) {
			
			char temp[] = "18.5C";
			int pointfound = 0;
			int pointloc = 0;
			char newtemp[4];
			
			if (strchr(temp, '.') != NULL) { 
				pointfound = 1;
				pointloc = (int)(strchr(temp, '.') - temp);
				
				for (int i = 0; i < (sizeof(temp) / sizeof(temp[0])); i++) {
					if (i >= pointloc) {
						newtemp[i] = temp[i+1];
					} else {
						newtemp[i] = temp[i];
					}
				}
			}
			 
				
			for (uint d=0; d<4 ; d++) {
				
				int32_t mask = digit_keys[0].hexval;
				
				if (pointfound == 1) {

						for (uint i = 0; i < (sizeof(digit_keys) / sizeof(digit_keys[0])); i++) {
							
							if ( d == (pointloc-1) ) {
							
								if ( strchr(digit_keys[i].key, newtemp[d]) != NULL && strchr(digit_keys[i].key, '.') != NULL) {
									mask = digit_keys[i].hexval;
								}
							} else {
								if ( strchr(digit_keys[i].key, newtemp[d]) != NULL && strchr(digit_keys[i].key, '.') == NULL) {
									mask = digit_keys[i].hexval;
								}
							}
					
						}
						
					
					} else {
						
						for (uint i = 0; i < (sizeof(digit_keys) / sizeof(digit_keys[0])); i++) {
							if ( strchr(digit_keys[i].key, newtemp[d]) != NULL  && strchr(digit_keys[i].key, '.') == NULL) {
								mask = digit_keys[i].hexval;
							}
					
						}

					}
				
				gpio_put_masked(0xff << PIN_SEG_A, mask << PIN_SEG_A);
				
				gpio_put(displays[d],1);
				sleep_ms(5);
				gpio_put(displays[d],0);
				
			}
			
	}
	
}
