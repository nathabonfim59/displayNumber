/*
    _    ========================\
   |_|   = DiplayNumbers  |  0.1
   |_|   = @nathabonfim59 | 2018
         ========================/

DESCRIPTION
  This is a simple function to translate a number passed to the function 
  displayNumber() into a 7 segments display.

HOW TO USE
  All you need to do is assign the correct pint number into the variables
  bellow. It's simple. You test all segments and atribute a pin to it's position.
*/

int middle = 2;   // The middle segment
int t_top = 3;    // The top segment
int t_left = 4;   // The segment on top and left
int t_right = 5;  // The top right segment
int d_down = 6;   // The bottom bottom segment
int d_left = 7;   // The bottom left segment
int d_right = 8;  /// The bottom right segment

// The setup function runs once when you press reset or power the board
void setup() {
  initSegment(middle);
  initSegment(t_top);
  initSegment(t_left);
  initSegment(t_right);
  initSegment(d_left);
  initSegment(d_right);
  initSegment(d_down);
}

// Init a pin with setting to OUTPUT and the voltage to HIGH
void initSegment(int segment) {
  pinMode(segment, OUTPUT);
  digitalWrite(segment, HIGH);
}

// Erease the number shown in the display
void resetSegments() {
  initSegment(middle);
  initSegment(t_top);
  initSegment(t_left);
  initSegment(t_right);
  initSegment(d_left);
  initSegment(d_right);
  initSegment(d_down);
}

// Turn the specific segment based on it's pin
void segmentOn(int segment) {
  digitalWrite(segment, LOW);
}

// Recives a number and display it in the 7 segment display
void displayNumber(int number) {
  if (number < 0 || number > 9) {
    return false;
  }

  resetSegments();
  switch (number) {
    case 0:
      segmentOn(t_top);
      segmentOn(d_down);
      segmentOn(t_left);
      segmentOn(t_right);
      segmentOn(d_left);
      segmentOn(d_right);
      break;
    case 1:
      segmentOn(t_right);
      segmentOn(d_right);
      break;
    case 2:
      segmentOn(t_top);
      segmentOn(t_right);
      segmentOn(middle);
      segmentOn(d_left);
      segmentOn(d_down);
      break;
    case 3:
      segmentOn(t_top);
      segmentOn(t_right);
      segmentOn(d_right);
      segmentOn(middle);
      segmentOn(d_down);
      break;
    case 4:
      segmentOn(t_left);
      segmentOn(t_right);
      segmentOn(middle);
      segmentOn(d_right);
      break;
    case 5:
      segmentOn(t_top);
      segmentOn(t_left);
      segmentOn(middle);
      segmentOn(d_right);
      segmentOn(d_down);
      break;
    case 6:
      segmentOn(t_top);
      segmentOn(t_left);
      segmentOn(middle);
      segmentOn(d_left);
      segmentOn(d_right);
      segmentOn(d_down);
      break;
    case 7:
      segmentOn(t_top);
      segmentOn(t_right);
      segmentOn(d_right);
      break;
    case 8:
      displayNumber(0);
      segmentOn(middle);
      break;
    case 9:
      displayNumber(4); // Invokes the function itself to create a four
      segmentOn(t_top);
      segmentOn(d_down);
      break;
  }
}

// Displays the numbers 1 to 9 in the panel
void loop() {
  for (int i = 0; i <= 9; i++) {
    displayNumber(i);
    delay(1000);  
  }
}
