int var[6] = {2, 3, 4, 5, 6, 7};     /* An array containing all numbers of ports which will be used */

int size = 6;     /* Numbers of elements in the array 'var' */

void setup()
{
  for (int i = 0; i < 6; i++)      /* set all ports in array as OUTPUT */
    pinMode(var[i], OUTPUT);
}

void one_by_one() 
{
  for (int i = 0; i < 6; i++, delay(50))      /* light up one by one by pause of 50ms from first to last */
    digitalWrite(var[i], 1);

  delay(500);                                 /* pause of 500ms */

  for (int i = 5; i > -1; i--, delay(50))     /* switch off one by one by pause of 50ms from last to first */
    digitalWrite(var[i], 0);

  delay(500);                                 /* pause of 500ms */
}


void one_by_one_rev()
{
  for (int i = 5; i > -1; i--, delay(50))    /* light up one by one by pause of 50ms from last to first */
    digitalWrite(var[i], 1);

  delay(500);                                /* pause of 500ms */

  for (int i = 0; i < 6; i++, delay(50))     /* switch off one by one by pause of 50ms from first to last */
    digitalWrite(var[i], 0);

  delay(500);                                 /* pause of 500ms */
}

void one_by_one_2()
{
  for (int i = 0; i < 6; i++, delay(50))      /* light up one by one by pause of 50ms from first to last */
    digitalWrite(var[i], 1);

  delay(500);                                 /* pause of 500ms */

  for (int i = 0; i < 6; i++, delay(50))      /* switch off one by one by pause of 50ms from first to last */
    digitalWrite(var[i], 0);

  delay(500);                                 /* pause of 500ms */
}


void one_by_one_rev_2()
{
  for (int i = 5; i > -1; i--, delay(50))     /* light up one by one by pause of 50ms from last to first */
    digitalWrite(var[i], 1);

  delay(500);                                 /* pause of 500ms */

  for (int i = 5; i > -1; i--, delay(50))     /* switch off one by one by pause of 50ms from last to first */
    digitalWrite(var[i], 0);

  delay(500);                                 /* pause of 500ms */
}

void on_off()
{
  for (int i = 0; i < 6; i++, delay(500))     /* light up one by one by pause of 500ms from first to last */
    digitalWrite(var[i], 1);
  
  for (int i = 5; i > -1; i--, delay(500))    /* switch off one by one by pause of 500ms from last to first */
    digitalWrite(var[i], 0);
}


void on_off_rev()
{
  for (int i = 5; i > -1; i--, delay(500))    /* light up one by one by pause of 500ms from last to first */
    digitalWrite(var[i], 1);
  
  for (int i = 0; i < 6; i++, delay(500))     /* switch off one by one by pause of 500ms from first to last */
    digitalWrite(var[i], 0);
}

void fade_effect(int d)
{
  for (int i = 0; i < 6; i++) {               /* Begin from first LED and end to last */

    for (int x = 0, k = 5; x != -5; x += k) { /* Light up each LED */
      delay(5);                               /* and switch it off */
      analogWrite(var[i], x);                 /* with a fade effect */
      if (x == 255)
        k = -k;    
    }

    delay(d);                                 /* pause of d ms */

  }
}

void fade_effect_2(int d)
{
  for (int i = 0, j = 5; i < 6; i++, j--) {   /* Start with the extremities and reduce the gap at each turn and then enlarge it again */
  
    for (int x = 0, k = 5; x != -5; x += k) { /* Light up and switch it off     */
      delay(5);                               /* LED i and LED j simultaneously */
      analogWrite(var[i], x);                 /* with a fade effect             */
      analogWrite(var[j], x);
      if (x == 255)
        k = -k;
      if (i == 2) {i++; j--;}
    }

    delay(d);                                 /* pause of d ms */

  }
}

void cligno()
{
  for (int i = 0; i < 6; i++)                   /* Light up all LEDs */
    digitalWrite(var[i], 1);

  delay(700);                                   /* pause of 700ms */

  for (int i = 0; i < 6; i++)                   /* Switch off all LEDs */
    digitalWrite(var[i], 0);

  delay(200);                                   /* pause of 200ms */

  for (int i = 0; i < 6; i++)                   /* Light up all LEDs */
    digitalWrite(var[i], 1);

  delay(200);                                   /* pause of 200ms */

  for (int i = 0; i < 6; i++)                   /* Switch off all LEDs */
    digitalWrite(var[i], 0);

  delay(200);                                   /* pause of 200ms */

  for (int i = 0; i < 6; i++)                   /* Light up all LEDs */
    digitalWrite(var[i], 1);

  delay(200);                                   /* pause of 200ms */

  for (int i = 0; i < 6; i++)                   /* Switch off all LEDs */
    digitalWrite(var[i], 0);

  delay(700);                                   /* pause of 700ms */

  for (int i = 0; i < 6; i++)                   /* Light up all LEDs */
    digitalWrite(var[i], 1);

  delay(700);                                   /* pause of 700ms */

  for (int i = 0; i < 6; i++)                   /* Switch off all LEDs */
    digitalWrite(var[i], 0);

  delay(500);                                    /* pause of 500ms */
}

void to_middle(int d, int p)
{
  for (int i = 0, j = 5; i < 3; i++, j--) {     /* Start with the extremities and reduce */
    digitalWrite(var[i], 1);                    /* the gap at each turn by lighting up   */
    digitalWrite(var[j], 1);                    /* simultaneously LED i and LED j */
    delay(d);
  }

  delay(p);                                     /* pause of p ms */

  for (int i = 2, j = 3; i > -1; j++, i--) {    /* Start with the extremities and reduce */
    digitalWrite(var[i], 0);                    /* the gap at each turn by switching off */ 
    digitalWrite(var[j], 0);                    /* simultaneously LED i and LED j */
    delay(d);
  }

  delay(p);                                   /* pause of p ms */
}

void loop()
{

  fade_effect(500);

  on_off();

  on_off_rev();

  one_by_one();

  one_by_one_rev();

  fade_effect_2(500);

  one_by_one_2();

  one_by_one_2();

  to_middle();

  cligno();

  one_by_one_rev_2();

  one_by_one_rev_2();

  delay(1000);                                   /* pause of 1000ms */
}