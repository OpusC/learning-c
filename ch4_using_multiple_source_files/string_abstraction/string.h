#pragma once

typedef struct string* String;

String string_create(const char*);

void string_destroy(String);

int string_length(const String);

String string_concat(const String, const String);

void string_print(const String);
