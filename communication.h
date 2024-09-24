#ifndef COMMN_H
#define COMMN_H

void bno_rec() {
  if (Serial1.available() > 0) {
    json = Serial1.readStringUntil('*');
    // Serial.println(json); // Print the received JSON for debugging

    Jsonerror = deserializeJson(doc, json);

    if (Jsonerror) {
      Serial.print(F("deserializeJson() failed: "));
      Serial.println(Jsonerror.f_str());
      // bno_chassis=0;
    } else {
      if (doc.containsKey("Z")) {
        const char* BT = doc["Z"];
        bno_chassis = -1 * atoi(BT);

        Serial.println(bno_chassis);
        // return bno_chassis;

      } else {
        Serial.println("NO JSON");
        // return -1;
      }
    }
  }
}

void json_rec() {
  if (Serial2.available() > 0) {
    json = Serial2.readStringUntil('*');

    Jsonerror = deserializeJson(doc, json);

    if (Jsonerror) {
      Serial.println(Jsonerror.f_str());
      return;
    } else {
      String esp_data = doc["LOC"];
      cmd = esp_data.charAt(0);
      String numStr = esp_data.substring(1, 4);
      strength = esp_data.substring(4, 7).toInt();
      num = numStr.toInt();
    }
  }

    // Serial.print("  : ");
  // Serial.print(cmd);
  // Serial.print("  : ");
  // Serial.print(num);
}

#endif