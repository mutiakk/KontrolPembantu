int Motor1 = 7;
int Motor2 = 6;
int Motor3 = 5;
int Motor4 = 4;
int Lamp=3;
int Lamp2=2;
int DataCheck = 0;

void setup() 
{
  Serial.begin(9600);
  pinMode(Motor1, OUTPUT);
  pinMode(Motor2, OUTPUT);
  pinMode(Motor3, OUTPUT);
  pinMode(Motor4, OUTPUT);
  pinMode(Lamp, OUTPUT);
  pinMode(Lamp2, OUTPUT);
   
  digitalWrite(Motor1, HIGH);
  digitalWrite(Motor2, HIGH);
  digitalWrite(Motor3, HIGH);
  digitalWrite(Motor4, HIGH);
  digitalWrite(Lamp,LOW);
  digitalWrite(Lamp2,LOW);
  Serial.print("Simulasi Kontrol Pembantu");
  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println();
   
}

void loop() 
{
  if(Serial.available())
  {
    char data = Serial.read();
    Serial.print(data);
    Serial.print("      ======== >      ");
    
    if(data == '1'){DataCheck = 1; digitalWrite(Motor2, LOW);digitalWrite(Motor1, HIGH); Serial.println("Gerbang Utama di buka");}
    if(data == '2'){DataCheck = 1; digitalWrite(Motor1, LOW);digitalWrite(Motor2, HIGH); Serial.println("Gerbang Utama di tutup");}
    if(data == '3'){DataCheck = 1; digitalWrite(Motor1, LOW);digitalWrite(Motor2,  LOW); Serial.println("Gerbang Otomatis berhenti");} 
    if(data == '4'){DataCheck = 1; digitalWrite(Motor3, LOW);digitalWrite(Motor4, HIGH); Serial.println("Menyalakan Pendingin");}
    if(data == '5'){DataCheck = 1; digitalWrite(Motor4, LOW);digitalWrite(Motor3, LOW); Serial.println("Mematikan Pendingin");}
    if(data == '6'){DataCheck = 1; digitalWrite(Lamp,HIGH);Serial.println("Lampu Teras Nyala");}
    if(data == '7'){DataCheck = 1; digitalWrite(Lamp,LOW);Serial.println("Lampu Teras Mati");}
    if(data == '8'){DataCheck = 1; digitalWrite(Lamp2,HIGH);Serial.println("Lampu R.Tamu Nyala");}
    if(data == '9'){DataCheck = 1; digitalWrite(Lamp2,LOW);Serial.println("Lampu R.Tamu Mati");}
    if(DataCheck == 0){Serial.println("Perintah Salah. Silakan ulangi !!! ");}
    Serial.println();
    DataCheck = 0;
  }
}
