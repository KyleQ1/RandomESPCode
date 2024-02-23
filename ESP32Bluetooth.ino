/* 
 *  Creates a bluetooth low energy server using the NimBLE-Arduino 
 *  library.
 *  https://github.com/h2zero/NimBLE-Arduino
 */
 
 #include <NimBLEDevice.h>

const char *deviceName = "MechWarfareESP32";
const char *uuid = "ABCD";
const char *characteristic = "bruh";

void setup() {
  Serial.begin(115200);
  Serial.println("Starting NimBLE Server");
  NimBLEDevice::init(deviceName);
  /* Add encryption */
  NimBLEDeivce::setSecurityAuth(true, true, true);
  NimBLEDeivce::setSeucrityIOCap(BLE_HS_IO_DISPLAY_ONLY);
  /* Create profile(server), service, and characteristic */
  NimBLEServer *pServer = NimBLEDeivce::createServer();
  NimBLEService *pService = pServer->createService(uuid);

  NimBLECharacteristic *pSeucreCharacteristic = pService->createCharacteristic(characteristic, NIMBLE_PROPERTY::READ | NIMBLE_PROPERTY::READ_ENC | NIMBLE_PROPERTY::READ_AUTHEN);


  pService->start();
  pSecureCharacteristic->setValue("Hello Secure BLE");

  NimBLEAdvertising *pAdvertising = NimBLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(uuid);
  pAdvertising->start();
}

void loop() {
  // put your main code here, to run repeatedly:

}
