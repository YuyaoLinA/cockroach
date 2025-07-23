import processing.serial.*;

Serial myPort;
float humanTension = 0;
float roachTension = 0;

void setup() {
  size(800, 600);
  println("Available Ports:");
  println(Serial.list());

  // ✅ 选择正确端口，如 COM3 / ttyUSB0
  String portName = Serial.list()[6];  // 修改索引以匹配你的实际端口
  myPort = new Serial(this, portName, 9600);
  myPort.bufferUntil('\n');
}

void draw() {
  background(255);

  textAlign(CENTER);
  textSize(20);
  fill(50);
  text("Wavering Arc: Human & Roach", width/2, 40);

  // 平衡杆角度
  float delta = humanTension - roachTension;
  float maxAngle = radians(30);
  float angle = constrain(delta * maxAngle, -maxAngle, maxAngle);

  pushMatrix();
  translate(width/2, height/2);
  rotate(angle);

  // 杆子
  stroke(0);
  strokeWeight(4);
  line(-150, 0, 150, 0);

  // Human weight (right)
  fill(30, 144, 255);
  ellipse(150, 0, 40 + humanTension * 80, 40 + humanTension * 80);
  fill(0); text("Human", 150, 60);

  // Roach weight (left)
  fill(255, 140, 0);
  ellipse(-150, 0, 40 + roachTension * 80, 40 + roachTension * 80);
  fill(0); text("Roach", -150, 60);

  popMatrix();

  // Text info
  fill(0);
  textSize(16);
  textAlign(LEFT);
  text("Human Tension: " + nf(humanTension, 1, 2), 20, height - 40);
  text("Roach Tension: " + nf(roachTension, 1, 2), 20, height - 20);
}

void serialEvent(Serial p) {
  String inData = p.readStringUntil('\n');
  if (inData != null) {
    inData = trim(inData);
    String[] parts = split(inData, ",");
    if (parts.length == 2) {
      humanTension = constrain(float(parts[0]), 0, 1);
      roachTension = constrain(float(parts[1]), 0, 1);
    }
  }
}
