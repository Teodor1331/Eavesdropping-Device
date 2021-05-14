import processing.serial.*;

Serial mySerial;
PrintWriter output;

void setup() {
   String normalPort = Serial.list()[0];
   String bluetoothPort = Serial.list()[2];

   mySerial = new Serial(this, bluetoothPort, 9600);
   output = createWriter("data.txt");
   mySerial.bufferUntil('\n');
}

void draw() {
    if (mySerial.available() > 0 ) {
         String value = mySerial.readString();
         output.println(value);
         printArray(value);
    }
}

void keyPressed() {
    output.flush();  // Writes the remaining data to the file
    output.close();  // Finishes the file
    exit();  // Stops the program
}
