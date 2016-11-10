                  // fclose(LEDHandle);
                 // }
                 // usleep(1000000);
                 // }
                 // cout << "LED Flash End" << endl;
//      }
//}

int main(int argc, char** argv)
{


        uint8_t c,d[10]="ABCDE",e[10],f='A';
                setup();
                radio.stopListening();
                radio.write_register(CONFIG, 0x0e);;
                c=radio.read_register(CONFIG);
                printf("\nConfig Register read 0x%x \n",c);
                c=radio.read_register(STATUS);
               printf("\nStatus Register Read: 0x%x \n",c);
//      radio.write_register(TX_ADDR,d,5);
        radio.read_register(TX_ADDR,e,5);
        printf("\nWrite and Readto TX_ADDR");
        for(c=0;c<5;c++)
        {
                printf("\t0x%x",e[c]);

        }
        printf("\n");
//      radio.write_register(RF_SETUP,0x02);
        c=radio.read_register(RF_SETUP);
        printf("\nRF Setup READ and WRITE : 0x%x",c);
        c=radio.read_register(FIFO_STATUS);

        printf("\nFIFO Status : 0x%x \n",c);

        //while(1)
                                                                                                                                                      276,3-24      94% //{
                radio.startWrite( &f ,1 );
                c=radio.read_register(STATUS);
                printf(" 0x%x \n",c);
                while((c & 0x20) != 0x20);
                radio.write_register(STATUS,0x20);

        //}
        return 0;


}


// vim:cin:ai:sts=2 sw=2 ft=cpp
