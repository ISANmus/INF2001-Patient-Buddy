#include <stdio.h>  
#include <stdlib.h> 
 
// Observer structure 
typedef struct Observer {  
   void (*update)(const char* message);  
} Observer; 

// Concrete Observers: Patient, Caregiver, Clinician  
void patient_update(const char* message) {  
   printf("[Patient] Received: %s\n", message);  
} 

void caregiver_update(const char* message) {  
   printf("[Caregiver] Received: %s\n", message);  
} 

void clinician_update(const char* message) {  
   printf("[Clinician] Received: %s\n", message);  
} 

// Subject structure  
typedef struct {  
   Observer* observers[10];  
   int num_observers;  
} Subject; 

// Function to add an observer  
void add_observer(Subject* subject, Observer* observer) { 
   if (subject->num_observers < 10) {  
      subject->observers[subject->num_observers++] = observer;  
   }  
} 

// Function to notify all observers  
void notify_observers(Subject* subject, const char* message) {  
   for (int i = 0; i < subject->num_observers; i++) {  
      subject->observers[i]->update(message);  
   }  
} 

int main() {  
   // Create subject  
   Subject subject = { .num_observers = 0 }; 
   // Create observers 
   Observer patient = { patient_update }; 
   Observer caregiver = { caregiver_update }; 
   Observer clinician = { clinician_update }; 
   // Register observers 
   add_observer(&subject, &patient); 
   add_observer(&subject, &caregiver); 
   add_observer(&subject, &clinician); 
   // Notify observers 
   notify_observers(&subject, "Video successfully uploaded!"); 
   notify_observers(&subject, "Reminder: Upload your video within 4-6 weeks."); 
   notify_observers(&subject, "Alert: Abnormal measurement detected!"); 
   return 0; 
} 
