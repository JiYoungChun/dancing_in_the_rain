// SOUND
var s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11;

var serial;
var Sensor1 = 0;
var Sensor2 = 0;
var Sensor3 = 0;
var Sensor4 = 0;
var Sensor5 = 0;
var Sensor6 = 0;
var Sensor7 = 0;
var Sensor8 = 0;

var canvas;


function preload() {
  s1 = loadSound('/assets/0.mp3');
  s2 = loadSound('/assets/1.mp3');
  s3 = loadSound('/assets/2.mp3');
  s4 = loadSound('/assets/3.mp3');
  s5 = loadSound('/assets/4.mp3');
  s6 = loadSound('/assets/5.mp3');
  s7 = loadSound('/assets/6.mp3');
  s8 = loadSound('/assets/7.mp3');
  s9 = loadSound('/assets/8.mp3');
  s10 = loadSound('/assets/9.mp3');
  s11 = loadSound('/assets/10.mp3');
}

function setup() {
  //songs.push(s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11);
  canvas = createCanvas(300, 300);
  serial = new p5.SerialPort();
  serial.open("/dev/cu.usbmodem1411");
  serial.on('data', serialEvent);
  serial.on('open', serialOpen);
  
  //playMode(sustain);
}

function draw() {
  //noprotect
  background(0, 10);
 fill(255,200);
  noStroke();
ellipse(Sensor1*4,Sensor2*4,50,50);
text(Sensor1, 20, 20);
  text(Sensor2, 40, 20);
  text(Sensor3, 60, 20);
  text(Sensor4, 80, 20);
  text(Sensor5, 100, 20);
  text(Sensor6, 120, 20);
  text(Sensor7, 140, 20);
  text(Sensor8, 160, 20);
  

 if(frameCount %50 === 0){ 
  if (Sensor1>=1 &&Sensor1<30){
   s1.play();

   }
  if (Sensor2>=1 &&Sensor2<30){
  s2.play();
    // s2.setVolume(30/Sensor2);
  }
  if (Sensor3>=1 &&Sensor3<30){
  s3.play();
      // s3.setVolume(30/Sensor3);
  }
  if (Sensor4>=1 &&Sensor4<30){
  s4.play();
  }
  if (Sensor5>=1 &&Sensor5<30){
 s5.play();
  }
  if (Sensor6>=1 &&Sensor6<30){
  s6.play();
  }
 if (Sensor7>=1 &&Sensor7<30){
s7.play();
  }
   if (Sensor8>=1 &&Sensor8<30){
  s8.play();
  }

   //else if (Sensor>=30){
    //s5.play();
    //return false;
  //}
 //}
}
}
function serialOpen(){
 serial.write('X'); 
  
}
function serialEvent() {
  var instring = serial.readLine();
  if (instring.length > 0) {
    var tmp = split(instring, " ");
    if (tmp.length > 1) {
      Sensor1 = Number(tmp[0]);
      Sensor2 = Number(tmp[1]);
      Sensor3 = Number(tmp[2]);
      Sensor4 = Number(tmp[3]);
      Sensor5 = Number(tmp[4]);
      Sensor6 = Number(tmp[5]);
      Sensor7 = Number(tmp[6]);
      Sensor8 = Number(tmp[7]);
     serial.write('X'); 
     // console.log(Sensor5);

   //console.log(Sensor1 + ' ' + Sensor2 + ' ' + Sensor3);
    }
  }
}

