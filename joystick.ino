//Constante
int iMax = 512;
int RED = 9;
int GREEN = 10;
int BLUE = 11;

float zone1 = 2*PI/3;
float zone2 = 4*PI/3;
float fMax = 512.0;


void setup(){
  pinMode(7, INPUT);
  pinMode(RED,OUTPUT);
  pinMode(BLUE,OUTPUT);
  pinMode(GREEN,OUTPUT);
}

float angle(float X, float Y)
{
  float angle = 0;
  if(X == 0)
  {
    if(Y < 0)
      angle = 3*PI/2;
    if(Y > 0)
      angle = PI/2;
  }
  else
  {
    angle = atan(Y/X);
    if(X > 0 && Y < 0)
      angle += 2*PI; 
    if(X<0)
      angle += PI;
  }
  
  return angle;
}


void loop(){
  // Alpha = angle for polar representation
  float alpha = 0;
  int intensity = 0;
  float X, Y;

  // Read value from analog pin of the arduino and centring the circle.
  int iX = analogRead(0)-iMax;
  int iY = analogRead(1)-iMax;
  
  // bound to [-iMax, iMax]
  if(iX > iMax) iX = iMax;
  if(iX < -iMax) iX = -iMax;
  if(iY > iMax) iY = iMax;
  if(iY < -iMax) iY = -iMax;

  // bound to [-100, 100]
  iX = ((((float)iX)/fMax)*100.0);
  iY = ((((float)iY)/fMax)*100.0);

  // bound to [-1, -1] on float
  X = ((float)iX/100.0);
  Y = ((float)iY/100.0);
  
  // Map all point of the square to the circle
  float XTemp = X;
  X *= (sqrt(1-(pow(Y,2)/2)));
  Y *= (sqrt(1-(pow(XTemp,2)/2)));

  // calculte the angle.
  alpha = angle(X,Y);
  // the raw intensity is calculate from the distance of the point from the center
  // bound to [0,255] because of the pwm value of the arduino. 
  intensity = sqrt(pow(X, 2) + pow(Y, 2))*256;
  
  // limiting the intensity
  if(intensity > 255)
    intensity = 255;
    
  // defining a neutral center region
  if(intensity < 25)
    intensity = 0;
    
  // defining the intensity of each color
  float intensityRed = 0;
  float intensityBlue = 0;
  float intensityGreen = 0;
  
  if(alpha <= zone1)
  { 
    intensityRed = alpha/zone1;
    intensityBlue = 1-intensityRed;
  }
  
  if(alpha > zone1 && alpha <= zone2)
  {
    intensityGreen = ((alpha - zone1)/zone1);
    intensityRed = 1-intensityGreen;  
  }

  if(alpha > zone2)
  {
    intensityBlue = ((alpha-zone2)/zone1); 
    intensityGreen = 1-intensityBlue;  
  }


  // sending the value to the pwm.
  analogWrite(RED, intensity*intensityRed );
  analogWrite(GREEN, intensity*intensityGreen );
  analogWrite(BLUE, intensity*intensityBlue);

  delay(50);
}

