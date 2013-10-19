@@ 1,24 +0,0 @@
/* Arduino Weather Balloon Code
      Purpose: to capture data on a weather balloon rig.
      
   Created by:
   Thomas Moll and Michael Snook
   19 October 2013
*/


herpderp

void setup()
{
    int t, i, j, k, altitude, camAltOld, tempAltOld, sampleAltOld, storedAlt, peakTime, maxAltitude;
    float pressure, temp, fallSpeed;
    char microbeType;
    i = 0, j = 0; k = 0;

    scanf(" %d, %d, %f, %f, %c", &t, &altitude, &pressure, &temp, &microbeType);
    camAltOld = altitude, tempAltOld = altitude, sampleAltOld = altitude, storedAlt = altitude;
  
}

void loop(altitude >= storedAltitude) //while not falling
{
        storedAlt = altitude;
        scanf(" %d, %d, %f, %f, %c", &t, &altitude, &pressure, &temp, &microbeType);
        
        if (altitude - camAltOld >= 5000){
            //Psudo: Rotate camera 90 degrees
            printf("\nCamera Rotated at %d meters.", altitude);
            fflush(stdout);
            camAltOld = altitude; //Stores altitude of when camera was last rotated, rotates every 5000 ft.
        }
        if (altitude - tempAltOld >= 1000){
            printf("\nTemperature at %d meters is %.2f degrees Celsius.", altitude, temp);
            //The following statment will be implemented when time is read in milliseconds
            //printf("\nElapsed Time: %d hours, %d minutes, %d seconds, %d milliseconds", hours(t), minutes(t), seconds(t), millis(t));   //Reports elapsed time ever 1000 meters.
            printf("\nElapsed Time: %d minutes.", t);
            tempAltOld = altitude; //Stores altitude of when temperature was last taken, takes temp every 1000ft.
        }
        
        if (altitude - sampleAltOld >= 10000) {
            while (i < 1) {
                printf("\nOpen Door, Run Fan, Shut Door.");
                printf("\nMicrobe Type %c Collected at %d meters.", microbeType, altitude);
                sampleAltOld = altitude;
                i = i + 1;
            }
            if (j < 6 && j > 0){
                //Psudo
                printf("\nRotate 60 Degrees, Open Door, Run Fan, Close Door.");
                printf("\nMicrobe Type %c Collected at %d meters.", microbeType, altitude);
                sampleAltOld = altitude;
                j = j + 1;
            }
            while (j == 0){
                j = j + 1;
            }
        
        }
        
}
