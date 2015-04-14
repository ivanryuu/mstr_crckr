const double potential_numbers[] = {12.0, 7.0, 22.0, 2.0, 32.0, 2.5, 5.5, 29.5, 27.5, 34.5, 17.5, 8.5};

// return the integers from the array
int* get_ints() {
  Serial.println("start of get_ints()");
  int *actual_ints = (int*) malloc(sizeof(int) * 5);
  Serial.println("start of loop");
  for(int i = 0; i < sizeof(potential_numbers) / sizeof(double); ++i) {
    Serial.println("start");
    Serial.println(potential_numbers[i]);
    
    if( (int) (potential_numbers[i] + .5) == potential_numbers[i]) {
      Serial.println("if");
      *(actual_ints++) = (int) potential_numbers[i]; 
      Serial.println(*(actual_ints-1));  
    }
    else{
      Serial.println("else;");
      Serial.println(potential_numbers[i]);
    }
    Serial.println("-----------------------");
    
  }
  
  return actual_ints-5;  
}

// return unique last digit
// this is the last value of the lock
int get_last_digit(int potential_values[]) {
  Serial.println("start of get_last_digit");
  int unique_value; // this will be the last digit
  
  Serial.println("hello");
  Serial.println((sizeof(potential_values) / sizeof(int)) - 2);
  for(int i = 0; i < (sizeof(potential_values) / sizeof(int) - 2); ++i) {
    Serial.println(i);
    
    if(potential_values[i] % 10 != potential_values[i+1]){
      //Serial.println("0 and 1 are different");
      
      if(potential_values[i] % 10 == potential_values[i+2] % 10) {
        //Serial.println("0 and 2 are same");
        unique_value = potential_values[i+1];
      }
      else {
        //Serial.println("1 and 2 are same");
        unique_value = potential_values[i];
      }
    }
  }
  Serial.println("end of get_last_digit()");
  return unique_value;
}

void setup() {
  Serial.begin(9600);
  Serial.println('a');
  int* potential_last_values = get_ints();
  Serial.println('b');
  int last_value = get_last_digit(potential_last_values);
  Serial.println('c');
  Serial.println(last_value);
}
void loop() {

}
