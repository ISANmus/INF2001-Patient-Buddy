#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Interface (INotification) with a send function pointer
typedef struct INotification {
 void (*send)(struct INotification *self);
} INotification;

// Notification, Reminder, and Alert structs each "implementing" INotification
typedef struct { INotification base; char message[50]; } Notification;
typedef struct { INotification base; char message[50]; } Reminder;
typedef struct { INotification base; char message[50]; } Alert;

// send functions for each type
void sendNotification(INotification *self);
void sendReminder(INotification *self);
void sendAlert(INotification *self);

// Factory function to create different notifications
typedef enum { NOTIFICATION, REMINDER, ALERT } NotificationType;
INotification *createNotification(NotificationType type, const char *message);

// NotificationManager function to use the factory and send notifications
void sendNotificationFromManager(NotificationType type, const char *message);

// Main function 
int main() {
 sendNotificationFromManager(NOTIFICATION, "System update available.");
 sendNotificationFromManager(REMINDER, "Meeting at 3 PM.");
 sendNotificationFromManager(ALERT, "High CPU usage detected!");
 return 0;
}
