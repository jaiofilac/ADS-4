// Copyright 2021 NNTU-CS

int cbinsearch(int* arr, int size, int value) {
  int current = size - 1;
  int step = size;
  int result = 0;
  while (true) {
    step = step >> 1;
    if (value < arr[current]) {
      current -= step;
    } else if (value > arr[current]) {
      current += step;
    } else if (value == arr[current]) {
      for (; value == arr[current]; current++) {}
      current--;
      for (; value == arr[current] && current >= 0; current--) {
        result++;
      }
      break;
    }
    if (step == 0) {
      break;
    }
  }
  return result;
}

int countPairs1(int* arr, int len, int value) {
  int result = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        result++;
      }
    }
  }
  return result;
}

int countPairs2(int* arr, int len, int value) {
  int lim = value / 2;
  int result = 0;
  for (int i = 0; arr[i] <= lim && i < len; i++) {
    bool found = false;
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        found = true;
        result++;
        continue;
      }
      if (found) {
        break;
      }
    }
  }
  return result;
}

int countPairs3(int* arr, int len, int value) {
  int lim = value / 2;
  int result = 0;
  int halfAmount = cbinsearch(arr, len, lim);
  for (int i = 0; arr[i] <= lim && i < len; i++) {
    result += cbinsearch(arr, len, value - arr[i]);
  }
  for (int i = 1; i <= halfAmount; i++) {
    result -= i;
  }
  return result;
}
