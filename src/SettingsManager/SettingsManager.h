#ifndef SettingsManager_h
#define SettingsManager_h
#include <ArduinoJson.h>
#include "Arduino.h"
#include "macros.h"
#include <map>

#include "FS.h"
#define JSON_LEN               1500
#define SM_KEY_NOT_FOUND       1
#define SM_ERROR              -1
#define SM_SUCCESS             0
class SettingsManager {
  public:
    SettingsManager() {};
    void readSettings(char * fileName);
    std::map <String, String> getSettings();
    void writeSettings(const char * fileName);
    //    void writeSettings(const String &fileName, const String &content);


    signed int getInt(const char * key, const signed int defaultValue = 0);
    unsigned int getUInt(const char * key, const unsigned int defaultValue = 0);

    signed short getShort(const char * key, const signed short defaultValue);
    unsigned short getUShort(const char * key, const unsigned short defaultValue);

    signed long getLong(const char * key, const signed long defaultValue);
    unsigned long getULong(const char * key, const unsigned long defaultValue);

    char getCChar(const char * key, const char defaultValue);
    signed char getChar(const char * key, const signed char defaultValue);
    unsigned char getUChar(const char * key, const unsigned char defaultValue);

    const char * getChar(const char * key, const char * defaultValue);
    String getString(const char * key, const String defaultValue);
    float getFloat(const char * key, const float defaultValue);
    double getDouble(const char * key, const double defaultValue);
    bool getBool(const char * key, const bool defaultValue);

    int setInt(const char * key, const signed int value);
    int setUInt(const char * key, const unsigned int value);
    int setShort(const char * key, const signed short value);
    int setUShort(const char * key, const unsigned short value);
    int setLong(const char * key, const signed long value);
    int setULong(const char * key, const unsigned long value);
    int setCChar(const char * key, const char value);
    int setChar(const char * key, const signed char value);
    int setUChar(const char * key, const unsigned char value);
    int setChar(const char * key, const char * value);
    int setString(const char * key, const String value);
    int setFloat(const char * key, const float value);
    int setDouble(const char * key, const double value);
    int setBool(const char * key, const bool value);

    JsonVariant getJsonVariant(const char * key);
    JsonObject getJsonObject(const char * key);
    JsonArray getJsonArray(const char * key);

    JsonObject getRoot() {
      return root;
    };
  private:
    DynamicJsonDocument doc = DynamicJsonDocument(1300);
    JsonObject root;
    void getFileContent(char* content, File &file);
    void createJson(const char* payload);
    void openSPIFFS();
};
#endif
