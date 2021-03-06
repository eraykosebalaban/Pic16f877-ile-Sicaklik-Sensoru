#include<16f877.h>

#device ADC = 10;

#use delay(clock = 4000000)

#use fast_io(a)
#use fast_io(b)

#define use_portb_lcd TRUE
#include<lcd.c>

unsigned long int deger;
float gerilim , sicaklik;

void main(){
setup_psp(PSP_DISABLED);
setup_timer_1(T1_DISABLED);
setup_timer_2(T2_DISABLED,0,1);
setup_ccp1(CCP_OFF);
setup_ccp2(CCP_OFF);

set_tris_a(0x20);
set_tris_b(0x00);

lcd_init();

setup_adc(adc_clock_div_32);
setup_adc_ports(ALL_ANALOG);
set_adc_channel(4);
delay_us(20);



while(true){
deger = read_adc();

gerilim = deger*4.88759;

sicaklik = (gerilim / 10) + 2;

printf(lcd_putc,"\fSicaklik= %fC"sicaklik);
delay_ms(100);

}

}



