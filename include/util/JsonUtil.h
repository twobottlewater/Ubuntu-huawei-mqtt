
#ifndef INCLUDE_UTIL_JSONUTIL_H_
#define INCLUDE_UTIL_JSONUTIL_H_


typedef struct JSON
{
    struct JSON *next;
    struct JSON *prev;
    struct JSON *child;
    int type;
    char *valuestring;
    int valueint;
    double valuedouble;
    char *string;
} JSON;

typedef int JSON_BOOL;

#define JSON_FALSE 0
#define JSON_TRUE 1

JSON* JSON_CreateObject(void);

JSON* JSON_CreateArray(void);
JSON* JSON_CreateIntArray(const int *numbers, int count);
JSON* JSON_CreateFloatArray(const float *numbers, int count);
JSON* JSON_CreateDoubleArray(const double *numbers, int count);
JSON* JSON_CreateStringArray(const char **strings, int count);

void JSON_AddStringToObject(JSON* object, const char* key, const char* value);
void JSON_AddNumberToObject(JSON* object, const char* key, double value);
void JSON_AddBoolToObject(JSON* object, const char* key, JSON_BOOL value);
void JSON_AddObjectToObject(JSON* object, const char* key, JSON* value);

void JSON_AddObjectToArray(JSON* arrayObject, JSON* value);

char* JSON_Print(const JSON * object);
JSON* JSON_Parse(const char *value);
void JSON_Delete(JSON * object);

int JSON_GetIntFromObject(const JSON * object, const char * key, const int defaultValue);
JSON_BOOL JSON_GetBoolFromObject(const JSON * object, const char * key, const JSON_BOOL defaultValue);
double JSON_GetDoubleFromObject(const JSON * object, const char * key, const double defaultValue);
char* JSON_GetStringFromObject(const JSON * object, const char * key, const char* defaultValue);
JSON* JSON_GetObjectFromObject(const JSON * object, const char * key);

int JSON_GetArraySize(const JSON *array);
int JSON_GetIntFromArray(const JSON * array, int index, const int defaultValue);
JSON_BOOL JSON_GetBoolFromArray(const JSON * array, int index, const JSON_BOOL defaultValue);
double JSON_GetDoubleFromArray(const JSON * array, int index, const double defaultValue);
char* JSON_GetStringFromArray(const JSON * array, int index, const char* defaultValue);
JSON* JSON_GetObjectFromArray(const JSON *array, int index);

#endif /* INCLUDE_UTIL_JSONUTIL_H_ */
